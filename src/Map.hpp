#ifndef MAP_HH
#define MAP_HH

#include <string>
#include <vector>
#include <iostream>
#include <tuple>
#include "lodepng.h"
#include "Character.hpp"
#include "Coin.hpp"


class Map {

protected:
	std::string address;
	std::vector<std::vector<int>> map; // the map in XY dimensions. -1 is wall, 0 is ground
	int height; // height of the map
	int width; // width of the map
	std::vector<Coin> coins;
	std::vector<std::pair<int, int>> skipCoins;

public:
	Map(std::string filename, std::string filename_bw);
	std::tuple< std::vector<std::vector<int>>, int, int > toMap(std::string filename);
	bool availableDirection(Direction dir, int x, int y);
	void addCoin(std::pair<int, int> coordinates, int value, State state);
	bool inSkipCoinsList(int x, int y);
};

#endif
