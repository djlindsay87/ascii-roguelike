#include <iostream>
#include <cstdio>

#include <io.h>
#include <fcntl.h>

#include "gamesystem.h"

using namespace std;

int main()
{
	GameSystem tileSet("sheet.txt");
	tileSet.playGame();
	
	return 0;
}