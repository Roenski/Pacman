#include "Character.hpp"

Character::Character(std::string initAddress, std::pair<int, int> initCoordinates)
{
	if(!texture.loadFromFile(initAddress)) {
		//throw error
		std::cout << "Error loading pacman texture\n";
	}
	
	coordinates = initCoordinates;
	address = initAddress;
	direction = RIGHT;
}

Direction Character::getDirection()
{
	return direction;
}

sf::Texture& Character::getTexture()
{
	return texture;
}

int Character::getX()
{
	return coordinates.first;
}

int Character::getY()
{
	return coordinates.second;
}

void Character::move()
{
	switch(direction) {
		
		case UP:
			coordinates.second -= 1;
			break;
		
		case DOWN:
			coordinates.second += 1;
			break;
			
		case LEFT:
			coordinates.first -= 1;
			break;
			
		case RIGHT:
			coordinates.first += 1;
			break;
		
		case STILL:
			break;
	}
}

void Character::setDirection(Direction dir)
{
	direction = dir;
}
