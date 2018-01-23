#include "Coin.hpp"

Coin::Coin(std::pair<int, int> coordinates, int initValue) : Character("../images/coin.png", coordinates)
{
	value = initValue;
}

int Coin::getValue()
{
	return value;
}
