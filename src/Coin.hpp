#ifndef COIN_HH
#define COIN_HH

#include "Character.hpp"



class Coin : public Character {
	
public:
	Coin(std::pair<int, int> coordinates, int initValue, State state);
	int getValue();
	
private:
	int value;
	
};


#endif
