CC=g++ -pthread
CPPFLAGS=-c -g -std=c++14 -Wall -Wextra -pedantic
SOURCES=main.cpp lodepng.cpp Map.cpp Window.cpp
OBJECTS=main.o lodepng.o Map.o Window.o -lsfml-graphics -lsfml-window -lsfml-system
OBJECTS_RM=main.o lodepng.o Map.o Window.o Window.hpp.gch Map.hpp.gch
EXECUTABLE=Pacman

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

.cpp.o:
	$(CC) $(CPPFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS_RM) $(EXECUTABLE)

run: Pacman
	./Pacman
 
valgrind: learner
	valgrind --leak-check=full --show-reachable=no ./learner

