import os
import shutil
import gzip
import zlib
import subprocess
import hashlib
import requests
import zipfile
from typing import List, Dict

material_type = {
	"water_0": 0,
	"bright_lava": 1,
	"yellow-green": 2,
	"water": 3,
	"sand": 4,
	"orange_yellow_lava": 5,
	"moving_green_goo": 6,
	"hot_water": 7,
	"sand_8": 8,
}

def generateMap(path : str, output_path : str, mesh_name : str, water_exists : str, water_planes : list, texture_index : int):
	if(os.path.exists(path+"/output")):
		shutil.rmtree(path+"/output")
	if(os.path.exists(path+"/obj")):
		shutil.rmtree(path+"/obj")
	
	print('Starting texture index '+str(texture_index))
	
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
		output_file.write(b'\xe7\x00\x00\x00\x00\x00\x00\x00') #E7 00 00 00 00 00 00 00 = pipe sync
		output_file.write(b'\xd9\xff\xff\xff\x00\x00\x04\x01') #D9 FF FF FF 00 00 04 01 = z-buffering, cull back-facing tris
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
		
		#water plane block pointer
		geometry_header.seek(0x4C)
		data_pointer+=4
		geometry_header.write(data_pointer.to_bytes(4,'big'))
		
		number_of_planes = 0
		if water_exists == "true":
			shutil.copy(f"{cwd}\\geometry\\geometry_material_block.bin",path+"/obj/geometry_material_block.bin")
			for water_plane in water_planes:
				number_of_planes+=1
				with open(path+"/obj/geometry_material_block.bin","r+b") as material_block:
					#0x46 = x1
					#0x48 = z1
					#0x4A = x2
					#0x4C = z2
					#0x4E = water plane height
					#0x60 = damage type
					#0x61 - 0x64 = rgba (u8)
					#0x66 - material type
					material_block.seek(0x46)
					material_block.write(water_plane["x1"].to_bytes(2,'big'))
					material_block.seek(0x48)
					material_block.write(water_plane["z1"].to_bytes(2,'big'))
					material_block.seek(0x4A)
					material_block.write(water_plane["x2"].to_bytes(2,'big'))
					material_block.seek(0x4C)
					material_block.write(water_plane["z2"].to_bytes(2,'big'))
					material_block.seek(0x4E)
					material_block.write(water_plane["water_height"].to_bytes(2,'big'))
					material_block.seek(0x61)
					material_block.write(water_plane["red"].to_bytes(1,'big'))
					material_block.seek(0x61)
					material_block.write(water_plane["green"].to_bytes(1,'big'))	
					material_block.seek(0x61)
					material_block.write(water_plane["blue"].to_bytes(1,'big'))	
					material_block.seek(0x61)
					material_block.write(water_plane["alpha"].to_bytes(1,'big'))
					material_block.seek(0x66)
					material_block.write(material_type[water_plane["material_type"]].to_bytes(1,'big'))
					material_block.close()
				
				with open(f"{cwd}\\geometry\\geometry_footer.bin","rb") as original_footer:
					with open(path+"/obj/geometry_footer.bin","wb+") as geometry_footer:
						for i in range(0xC):
							b = original_footer.read(1)
							geometry_footer.write(b)
						geometry_footer.write(number_of_planes.to_bytes(4,'big'))
						with open(path+"/obj/geometry_material_block.bin","rb") as material_block:
							geometry_footer.seek(0x10 + 0x6C * (number_of_planes - 1))
							for i in range(0x6C):
								b = material_block.read(1)
								geometry_footer.write(b)
							material_block.close()
						original_footer.seek(0x10)
						for i in range(0x34):
							b = original_footer.read(1)
							geometry_footer.write(b)
						geometry_footer.close()
					original_footer.close()

		geometry_header.seek(0x50)
		data_pointer+= (4 + number_of_planes * 0x6C)
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
		
		#chunk section start
		geometry_header.seek(0x60)
		if water_exists == "true":
			data_pointer+=0x4
		else:
			data_pointer+=0x10
		geometry_header.write(data_pointer.to_bytes(4,'big'))
		
		geometry_header.seek(0x64)
		data_pointer+=0
		geometry_header.write(data_pointer.to_bytes(4,'big'))
		
		if water_exists == "true":
			shutil.copy(f"{cwd}\\geometry\\geometry_chunk_block.bin",path+"/obj/geometry_chunk_block.bin")
			with open(path+"/obj/geometry_chunk_block.bin","r+b") as chunk_block:
				#size of dl block
				chunk_block.seek(0x14)
				chunk_block.write((len(dl_block)+0x18).to_bytes(4,'big')) #add 0x18 to the dl block size for the additional commands added above
				
				#size of vert block
				chunk_block.seek(0x34)
				chunk_block.write((len(vert_block)).to_bytes(4,'big'))
				
				chunk_block.seek(0)
				with open(path+"/obj/geometry_footer.bin","r+b") as geometry_footer:
					geometry_footer.seek(0x10 + 0x6C * number_of_planes + 0x10)
					for i in range(0x6C):
						b = chunk_block.read(1)
						geometry_footer.write(b)
					for i in range(0x8):
						b = b'\x00'
						geometry_footer.write(b)
					geometry_footer.close()
				chunk_block.close()
			
		geometry_header.seek(0x68)
		if water_exists == "true":
			data_pointer+=0x4
		else:
			data_pointer+=0x10
		geometry_header.write(data_pointer.to_bytes(4,'big'))
		
		geometry_header.seek(0x6C)
		if water_exists == "true":
			data_pointer+=0x68
		else:
			data_pointer+=0
		geometry_header.write(data_pointer.to_bytes(4,'big'))
		
		geometry_header.seek(0x70)
		data_pointer+=4
		geometry_header.write(data_pointer.to_bytes(4,'big'))
		
		#water existing / chunks existing - needs to set a specific header byte from 1 to 2
		if water_exists == "true":
			geometry_header.seek(0x130)
			data = 2
			geometry_header.write(data.to_bytes(1,'big'))
		
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
				
	#copy geometry, walls, floors to output directory
	if(not os.path.exists(output_path)):
		os.mkdir(output_path)
	shutil.copy(path+"/output/geometry.bin",output_path+"/geometry.bin")
	shutil.copy(path+"/output/walls.bin",output_path+"/walls.bin")
	shutil.copy(path+"/output/floors.bin",output_path+"/floors.bin")
	
	#copy textures to bin
	if(not os.path.exists("bin/"+mesh_name)):
		shutil.copytree(path+"/output/textures/"+mesh_name,"bin/"+mesh_name)
	else:
		shutil.rmtree("bin/"+mesh_name)
		shutil.copytree(path+"/output/textures/"+mesh_name,"bin/"+mesh_name)
		
	#copy build imports to bin/build_imports
	if(not os.path.exists("bin/build_imports/")):
		os.mkdir("bin/build_imports/")
	else:
		shutil.rmtree("bin/build_imports")
		os.mkdir("bin/build_imports")
	with open("bin/build_imports/"+mesh_name+".txt","w") as imports:
		with open(path+"/output/build_imports.txt","r") as build_imports:
			contents = build_imports.read()
			imports.write("[\n")
			imports.write(contents)
			imports.write("]")
			build_imports.close()
			imports.close()
	
	#open model header to get number of textures
	model_file = open(path+"/header.h")
	num_textures = int(model_file.read().count('u64'))
	print('Number of textures in '+mesh_name+' '+str(num_textures))
	return (texture_index + num_textures)

def getFileSize(path : str):
	return os.path.getsize(path)