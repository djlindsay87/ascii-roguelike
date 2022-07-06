#ifndef _GAMESYSTEM_H
#define _GAMESYSTEM_H

//#include "player.h"
#include "level.h"

#include <cstdlib>
#include <string>
#include <iostream>
#include <conio.h>

using namespace std;

class GameSystem
{
	public:
		GameSystem();
		
		void loadLevel(string levelFile);
		
		void playGame();
		char playerMove();
		
	private:
		//Player _player;
		Level level_;
};

#endif