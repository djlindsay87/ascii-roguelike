all: Poly

Poly: main.o gamesystem.o level.o
	g++ main.o gamesystem.o level.o -o Poly
	
main.o: main.cpp gamesystem.h
	g++ -Wall -std=c++20 -c -g main.cpp

gamesystem.o: gamesystem.cpp gamesystem.h level.h
	g++ -Wall -std=c++20 -c -g gamesystem.cpp
	
level.o: level.cpp level.h
	g++ -Wall -std=c++20 -c -g level.cpp
	
clean: 
	rm *.o