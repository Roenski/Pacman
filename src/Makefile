CC = g++
CPPFLAGS = -c -g -std=c++14 -Wall -Wextra -pedantic
LDFLAGS = -Wall -g
OBJECTS = main.o lodepng.o Map.o Window.o Character.o Pacman.o drawing.o -lsfml-graphics -lsfml-window -lsfml-system
EXECUTABLE = Pacman

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

main.o : main.cpp Map.hpp Window.hpp Character.hpp Pacman.hpp drawing.hpp lodepng.h
	$(CC) $(CPPFLAGS) main.cpp

drawing.o : drawing.cpp drawing.hpp Window.hpp Map.hpp Pacman.hpp Character.hpp lodepng.h
	$(CC) $(CPPFLAGS) drawing.cpp

lodepng.o : lodepng.cpp lodepng.h
	$(CC) $(CPPFLAGS) lodepng.cpp

Map.o : Map.cpp Map.hpp lodepng.h
	$(CC) $(CPPFLAGS) Map.cpp

Window.o : Window.cpp Window.hpp Map.hpp Pacman.hpp Character.hpp lodepng.h
	$(CC) $(CPPFLAGS) Window.cpp

Character.o : Character.cpp Character.hpp
	$(CC) $(CPPFLAGS) Character.cpp

Pacman.o : Pacman.cpp Pacman.hpp Character.hpp
	$(CC) $(CPPFLAGS) Pacman.cpp

clean:
	rm -f *.o *.hpp.gch *~ $(EXECUTABLE)

run: Pacman
	./Pacman
 
valgrind: $(EXCECUTABLE)
	valgrind --leak-check=full --show-reachable=no ./Pacman

