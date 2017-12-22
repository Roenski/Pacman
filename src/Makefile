CC = g++
CPPFLAGS = -c -g -std=c++14 -Wall -Wextra -pedantic
LDFLAGS = -Wall -g
OBJECTS = main.o lodepng.o Map.o Window.o drawing.o -lsfml-graphics -lsfml-window -lsfml-system
EXECUTABLE = Pacman

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

main.o : Map.hpp Window.hpp drawing.hpp lodepng.h
	$(CC) $(CPPFLAGS) main.cpp

drawing.o : drawing.hpp Window.hpp Map.hpp lodepng.h
	$(CC) $(CPPFLAGS) drawing.cpp

lodepng.o : lodepng.h
	$(CC) $(CPPFLAGS) lodepng.cpp

Map.o : Map.hpp lodepng.h
	$(CC) $(CPPFLAGS) Map.cpp

Window.o : Window.hpp Map.hpp lodepng.h
	$(CC) $(CPPFLAGS) Window.cpp

clean:
	rm -f *.o *.hpp.gch *~ $(EXECUTABLE)

run: Pacman
	./Pacman
 
valgrind: learner
	valgrind --leak-check=full --show-reachable=no ./learner

