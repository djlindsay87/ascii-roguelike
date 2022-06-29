#ifndef _LEVEL_H
#define _LEVEL_H

#include <vector>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>


//#include "player.h"

using namespace std;

class Level{
	public:
		Level();
	
		void loadPalette(string fileName);
		void print();
		
		//char getTile(int x, int y);
		//void setTile(int x, int y, char tile);
	
	private:
		vector <string> _levelData;
		int _magic;
		//TileBatch _tileBatch;
		
		//void interpret(int x, int y);
};

#endif