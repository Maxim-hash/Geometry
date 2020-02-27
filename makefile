sfml-app: main.cpp
	g++ -g -Wall -o main.o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	g++ -c main.cpp
