all: circle

circle: 
	g++ -g -Wall -Werror src/*.* -o build/main
split:
	g++ -g -Wall -Werror src/*.* -o build/main