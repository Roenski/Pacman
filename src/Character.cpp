#include "Character.hpp"

Character::Character(std::string initAddress)
{
	if(!texture.loadFromFile(initAddress)) {
		//throw error
		std::cout << "Error loading pacman texture\n";
	}
	
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

void Character::setDirection(Direction dir)
{
	direction = dir;
}
