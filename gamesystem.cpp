#include "gamesystem.h"

GameSystem::GameSystem(string levelFile){
	_level.loadPalette(levelFile);
	_level.print();
	printf("You did it!\n");
}

void GameSystem::playGame(){
	char allDone;
	
	while (allDone != 'x'){
		allDone = playerMove();
		printf("%c\nYou're still doing it!\n", allDone);
	}
}
char GameSystem::playerMove(){
	printf("Enter a command: ");
	return _getch();
}