import subprocess
import os

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
	rows = result[a+6:b-1]
	columns = result[b+9:c]
	#print(rows+" "+columns)
	
	#open model header to get number of textures
	model_file = open(path+"/header.h")
	num_textures = int(model_file.read().count('u64'))
	print('Number of textures in '+mesh_name+' '+str(num_textures))
	return (texture_index + num_textures)