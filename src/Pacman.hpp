#ifndef PACMAN_HH
#define PACMAN_HH

#include "Character.hpp"

class Pacman : public Character {
	
public:
	Pacman(std::string initAddress, std::pair<int, int> initCoordinates);
	void addPoints(int morePoints);
	int getPoints();
	
private:
	int points;
	int lives;
	
	
};


#endif
