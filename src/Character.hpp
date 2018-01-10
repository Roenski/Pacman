#ifndef CHARACTER_HH
#define CHARACTER_HH

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

enum Direction {
	UP,
	DOWN,
	LEFT,
	RIGHT,
	STILL
};

class Character {
	
public:
	Character(std::string initAddress, std::pair<int, int> initCoordinates);
	Direction getDirection();
	sf::Texture& getTexture();
	void setDirection(Direction dir);
	int getX();
	int getY();
	void move();
	
protected:
	sf::Texture texture;
	std::string address;
	Direction direction;
	std::pair<int, int> coordinates; // coordinates in x,y
};

#endif
