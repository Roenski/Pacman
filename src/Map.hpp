#ifndef MAP_HH
#define MAP_HH

#include <string>
#include <vector>
#include <iostream>
#include <tuple>
#include "lodepng.h"


class Map {

protected:
	std::string address;
	std::vector<std::vector<int>> map; // the map in XY dimensions. -1 is wall, 0 is ground
	int height; // height of the map
	int width; // width of the map

public:
	Map(std::string filename);
	std::tuple< std::vector<std::vector<int>>, int, int > toMap(std::string filename);
};

#endif
