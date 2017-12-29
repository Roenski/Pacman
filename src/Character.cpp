#include "Character.hpp"

Character::Character(sf::Texture &initTexture, std::string initAddress)
{
	if(!texture.loadFromFile(initAddress)) {
		//throw error
		std::cout << "Error loading pacman texture\n";
	}
	
	texture = initTexture;
	address = initAddress;
	direction = RIGHT;
}

Direction Character::getDirection()
{
	return direction;
}

void Character::setDirection(Direction dir)
{
	direction = dir;
}
