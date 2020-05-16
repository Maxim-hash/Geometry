CFLAGS = -g -Wall -Werror
CC = g++
EXECUTABLE = prog
SOURCES = src/main.cpp src/readCircle.cpp src/geom.cpp
OBJECTS = $(SOURCES: .c=build/.o)

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o build/main

main.o: src/main.cpp
	$(CC) $(CFLAGS) src/main.cpp

geom.o: src/geom.cpp
	$(CC) $(CFLAGS) src/geom.cpp

split.o: src/split.cpp
	$(CC) $(CFLAGS) arc/split.cpp

clean: 
	rm -rf build/*.o