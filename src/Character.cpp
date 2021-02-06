#include "Character.hpp"

Character::Character(std::string initAddress, std::pair<int, int> initCoordinates)
{
	if(!texture.loadFromFile(initAddress)) {
		//throw error
		std::cout << "Error loading pacman texture\n";
	}
	
	coordinates = initCoordinates;
	address = initAddress;
}

Direction Character::getDirection()
{
	return direction;
}

State Character::getState()
{
	return state;
}

sf::Texture& Character::getTexture()
{
	return texture;
}

// The map is divided into 20px sized tiles
// This method calculates the tile the character currently is in
std::pair<int, int> Character::getTile()
{
	int xTile = coordinates.first/20;
	int yTile = coordinates.second/20;
	return std::make_pair(xTile, yTile);
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

void Character::setAlive()
{
	state = ALIVE;
}

void Character::setDead()
{
	state = DEAD;
}

void Character::setDirection(Direction dir)
{
	direction = dir;
}
