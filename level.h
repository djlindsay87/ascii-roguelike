#ifndef _LEVEL_H
#define _LEVEL_H

#include <vector>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <map>

#include <cassert>

//#include "player.h"

using namespace std;

class Level{
	public:
		Level();
	
		void loadPalette(string fileName);
		void loadLevel(string fileName);
		void print();
		
		char getChar(int x, int y);
		void setChar(int x, int y, char tile);
		
		vector<string> tileGrab(char ch);
	
	private:
		void initMap_();
	
		vector <string> levelData_;
		vector <string> paletteData_;
		unsigned int pal_, tw_, th_;
		int magic_, pw_, ph_;
		
		string charList_;
		int charLen_;
		
		map<char, vector<int>> m_;
};

#endif