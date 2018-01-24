#include "Pacman.hpp"

Pacman::Pacman(std::string initAddress, std::pair<int, int> initCoordinates) : Character(initAddress, initCoordinates) 
{
	direction = RIGHT;
	state = ALIVE;
	lives = 3;
	points = 0;
}

void Pacman::addPoints(int morePoints)
{
	points += morePoints;
}

int Pacman::getPoints()
{
	return points;
}
