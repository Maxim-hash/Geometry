sfml-app: main.o
	g++ -g -Wall buidl/main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

buid/main.o: src/main.cpp
	g++ -c src/main.cpp
