#include "Coin.hpp"

Coin::Coin(std::pair<int, int> coordinates, int initValue, State initState) : Character("../images/coin.png", coordinates)
{
	value = initValue;
	direction = STILL;
	state = initState;
}

int Coin::getValue()
{
	return value;
}
