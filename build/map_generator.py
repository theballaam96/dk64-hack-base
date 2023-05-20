import subprocess
import os

def generateMap(path : str, mesh_name : str, water_exists : str, texture_index : str):
	if(not os.path.exists(path+"/output")):
		os.mkdir(path+"/output")
	subprocess.call(['java', '-cp', './build/dk64maps.jar', 'map_generator.MapGenerator', path+"/model.c", path+"/output", mesh_name, water_exists, texture_index])