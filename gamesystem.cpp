#include "gamesystem.h"

GameSystem::GameSystem(){	
	for (int i=1;i<=2;i++){
		string level="level"+to_string(i)+string(".txt");
		cout<<level<<endl;
		system("PAUSE");
		loadLevel(level);
		playGame();
	}
}

void GameSystem::loadLevel(string levelFile){
	level_.loadLevel(levelFile);
	level_.print();
	printf("You did it!\n");
}

void GameSystem::playGame(){
	char allDone;
	
	while (allDone != 'x'){
		allDone = playerMove();
		printf("%c\n", allDone);
		if (allDone != 'x'){printf("You're still doing it!\n");}
	}
}
char GameSystem::playerMove(){
	printf("Enter a command: ");
	return _getch();
}