import os
import shutil
import gzip
import zlib
import subprocess
import hashlib
import requests
import zipfile

def generateMap(path : str, mesh_name : str, water_exists : str, texture_index : int):
	print('Starting texture index '+str(texture_index))
	if(not os.path.exists(path+"/output")):
		os.mkdir(path+"/output")
	result = subprocess.run(['java', '-cp', './build/dk64maps.jar', 'map_generator.MapGenerator', path+"/model.c", path+"/output", mesh_name, water_exists, str(texture_index)], stdout=subprocess.PIPE)
	result = result.stdout.decode('utf-8')
	print(result)
	
	#parse values from result
	a = result.find('ROWS: ')
	b = result.find('COLUMNS: ')
	c = result.find('\n',b) #find the new line character after COLUMNS
	rows = int(result[a+6:b-1])
	columns = int(result[b+9:c])
	#print(rows)
	#print(columns)
	
	d = result.find('Verts:')
	e = result.find('\n',d)
	verts = int(result[d+6:e])
	#print(verts)	
	
	#compile model file with mips64-elf-gcc
	cwd = os.path.dirname(os.path.abspath(__file__))
	if os.path.exists(path+"/obj"):
		shutil.rmtree(path+"/obj")
	os.mkdir(path+"/obj")
	for root, dirs, files in os.walk(path):
		for file in files:
			if file.endswith('.h'):
				shutil.copyfile(path+"/"+file, path+"/output/"+file)
	for root, dirs, files in os.walk(path+"/output"):
		for file in files:
			if file.endswith('.c'):
				subprocess.run([f"{cwd}\\n64chain\\tools\\bin\\mips64-elf-gcc", "-w", "-Wall", "-O1", "-mtune=vr4300", "-march=vr4300", "-mabi=32", "-fomit-frame-pointer", "-fno-toplevel-reorder", "-G0", "-c", "-nostdinc", "-I.", "-Iinclude2", "-Iinclude2/libc", "-DTARGET_N64", "-DF3DEX2_GBI", os.path.join(root, file)])
				shutil.move("./"+file.replace(".c", ".o"), path+"/obj/"+file.replace(".c", ".o"))
	
	#get displaylists and vert blocks
	#vert block starts at 0x38
	with open(path+"/obj/model.o","rb") as model_obj:
		contents = model_obj.read()
		model_obj.close()
	vert_block = contents[0x38:(0x38+(verts*0x10))]
	end_of_file = contents.find(b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00')
	if end_of_file % 8 != 0:
		end_of_file += (8 - (end_of_file % 8))
	dl_block = contents[(0x38+(verts*0x10)):end_of_file]
	with open(path+"/obj/dl_and_verts.bin","wb") as output_file:
		output_file.write(dl_block)
		output_file.close()
	with open(path+"/obj/dl_and_verts.bin","ab") as output_file:
		output_file.write(b'\xdf\x00\x00\x00\x00\x00\x00\x00') #0xDF00000000000000 = end display list
		output_file.close()
	with open(path+"/obj/dl_and_verts.bin","ab") as output_file:
		output_file.write(vert_block)
		output_file.close()
		
	#get wall and floor size for header
	wall_file_size  = getFileSize(path+"/output/walls.bin")
	floor_file_size = getFileSize(path+"/output/floors.bin")
	print(wall_file_size)
	print(floor_file_size)
	
	#modify header
	cwd = os.path.dirname(os.path.abspath(__file__))
	#print(cwd)
	#print("{cwd}\\geometry\\geometry_header.bin")
	shutil.copy(f"{cwd}\\geometry\\geometry_header.bin",path+"/obj/geometry_header.bin")
	shutil.copy(f"{cwd}\\geometry\\geometry_footer.bin",path+"/obj/geometry_footer.bin")
	with open(path+"/obj/geometry_header.bin","r+b") as geometry_header:
		#wall size
		geometry_header.seek(0x0)
		geometry_header.write(wall_file_size.to_bytes(4,'big'))
		#floor size
		geometry_header.seek(0x4)
		geometry_header.write(floor_file_size.to_bytes(4,'big'))
		#grid dimensions
		geometry_header.seek(0x10)
		geometry_header.write(columns.to_bytes(2,'big'))
		geometry_header.seek(0x12)
		geometry_header.write(rows.to_bytes(2,'big'))
		geometry_header.seek(0x18)
		geometry_header.write(columns.to_bytes(2,'big'))
		geometry_header.seek(0x1A)
		geometry_header.write(rows.to_bytes(2,'big'))
		#data block pointers
		#dl block pointer
		data_pointer = 0x140
		#vert block pointer
		geometry_header.seek(0x38)
		data_pointer+= (getFileSize(path+"/obj/dl_and_verts.bin") - verts * 0x10)
		geometry_header.write(data_pointer.to_bytes(4,'big'))
		#rest of data
		geometry_header.seek(0x40)
		data_pointer+=(verts * 0x10)
		geometry_header.write(data_pointer.to_bytes(4,'big'))
		
		geometry_header.seek(0x44)
		data_pointer+=4
		geometry_header.write(data_pointer.to_bytes(4,'big'))
		
		geometry_header.seek(0x48)
		data_pointer+=4
		geometry_header.write(data_pointer.to_bytes(4,'big'))
		
		geometry_header.seek(0x4C)
		data_pointer+=4
		geometry_header.write(data_pointer.to_bytes(4,'big'))
		
		geometry_header.seek(0x50)
		data_pointer+=4
		geometry_header.write(data_pointer.to_bytes(4,'big'))
		
		geometry_header.seek(0x54)
		data_pointer+=4
		geometry_header.write(data_pointer.to_bytes(4,'big'))
		
		geometry_header.seek(0x58)
		data_pointer+=4
		geometry_header.write(data_pointer.to_bytes(4,'big'))
		
		geometry_header.seek(0x5C)
		data_pointer+=4
		geometry_header.write(data_pointer.to_bytes(4,'big'))
		
		geometry_header.seek(0x60)
		data_pointer+=0x10
		geometry_header.write(data_pointer.to_bytes(4,'big'))
		
		geometry_header.seek(0x64)
		data_pointer+=0
		geometry_header.write(data_pointer.to_bytes(4,'big'))
		
		geometry_header.seek(0x68)
		data_pointer+=0x10
		geometry_header.write(data_pointer.to_bytes(4,'big'))
		
		geometry_header.seek(0x6C)
		data_pointer+=0
		geometry_header.write(data_pointer.to_bytes(4,'big'))
		
		geometry_header.seek(0x70)
		data_pointer+=4
		geometry_header.write(data_pointer.to_bytes(4,'big'))
		
		geometry_header.close()
		
	#finish geometry file
	geometry_file_complete = open(path+"/output/geometry.bin","wb")
	with open(path+"/obj/geometry_header.bin","r+b") as geometry_header:
		with open(path+"/obj/dl_and_verts.bin","r+b") as dl_and_verts_file:
			with open(path+"/obj/geometry_footer.bin","r+b") as geometry_footer:
				contents = geometry_header.read()
				geometry_header.close()
				geometry_file_complete.write(contents)
				contents = dl_and_verts_file.read()
				dl_and_verts_file.close()
				geometry_file_complete.write(contents)
				contents = geometry_footer.read()
				geometry_footer.close()
				geometry_file_complete.write(contents)
				geometry_file_complete.close()
	
	#open model header to get number of textures
	model_file = open(path+"/header.h")
	num_textures = int(model_file.read().count('u64'))
	print('Number of textures in '+mesh_name+' '+str(num_textures))
	return (texture_index + num_textures)

def getFileSize(path : str):
	return os.path.getsize(path)