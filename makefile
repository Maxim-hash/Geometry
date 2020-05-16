CFLAGS = -g -Wall -Werror
CC = g++
EXECUTABLE = prog

SOURCES = src/main.cpp src/readCircle.cpp src/geom.cpp src/read-fill.cpp
#OBJECTS = $(SOURCES: .cpp=build/.o)
OBJECTS=build/main.o build/geom.o build/readCircle.o build/read-fill.o
all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o bin/prog 

build/main.o: $(SOURCES)
	$(CC) $(CFLAGS) -c src/main.cpp -o build/main.o

build/geom.o: $(SOURCES)
	$(CC) $(CFLAGS) -c src/geom.cpp -o build/geom.o

build/readCircle.o: $(SOURCES)
	$(CC) $(CFLAGS) -c src/readCircle.cpp -o build/readCircle.o

build/read-fill.o: $(SOURCES)
	$(CC) $(CFLAGS) -c src/read-fill.cpp -o build/read-fill.o

clean: 
	rm -rf build/*.o
	rm -rf bin/*

.PHONY: all clean