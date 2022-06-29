#include "level.h"

#include <typeinfo>

Level::Level(){
	_magic = (12+1)*32; //size of palette + newlines
}

void Level::loadPalette(string fileName){
	ifstream file;
	
	file.open(fileName);
	if (file.fail()){
		perror(fileName.c_str());
		exit(1);
	}
	
	string line;
	int i=0;

	while (getline(file,line) && i < 12){
		_levelData.push_back(line);
		i++;
	}
	
	file.close();
}


void Level::print(){
	char buf[_magic];
	char* const last = buf + sizeof(buf);
	char* out = buf;
	
	for (unsigned int i =0;i<_levelData.size();i++){
		for (unsigned int j =0;j<_levelData[i].size();j++){
			out+=snprintf(out, last - out, "%c", char(_levelData[i][j]));
		}
		out+=snprintf(out, last - out, "\n");
	}
	*out = '\0';
	printf("%s", buf);
}

//char Level::getTile(int x, int y){return _levelData[y][x];}

//void Level::setTile(int x, int y, char tile){_levelData[y][x]=tile;}