#ifndef CHARACTER_HH
#define CHARACTER_HH

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>

enum Direction {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class Character {
	
public:
	Character(sf::Texture &initTexture, std::string initAddress);
	Direction getDirection();
	sf::Texture& getTexture();
	void setDirection(Direction dir);
	
protected:
	sf::Texture texture;
	std::string address;
	Direction direction;
};

#endif
