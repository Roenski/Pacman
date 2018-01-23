#include "Pacman.hpp"

Pacman::Pacman(std::string initAddress, std::pair<int, int> initCoordinates) : Character(initAddress, initCoordinates) 
{
	lives = 3;
	points = 0;
}
