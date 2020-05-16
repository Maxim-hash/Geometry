CFLAGS = -g -Wall -Werror
CC = g++
EXECUTABLE = prog
SOURCES = src/main.cpp src/readCircle.cpp src/geom.cpp
OBJECTS = $(SOURCES: .c=build/.o)

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

clean: 
	rm -rf build/*.o