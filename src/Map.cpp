#include "Map.hpp"

Map::Map(std::string filename, std::string filename_bw)
{
	skipCoins = {std::make_pair(30,30), std::make_pair(50,30), std::make_pair(30,50)};
	std::tuple< std::vector<std::vector<int>>, int, int > bunch = toMap(filename_bw);
	map = std::get<0>(bunch);
	height = std::get<1>(bunch);
	width = std::get<2>(bunch);
	address = filename;
}

void Map::addCoin(std::pair<int, int> coordinates, int value, State state) 
{
	Coin toAdd = Coin(coordinates, value, state);
	coins.push_back(toAdd);
	//std::cout << "Added coin coordinates: " << coordinates.first << " " << coordinates.second << std::endl;
}

bool Map::availableDirection(Direction dir, int x, int y)
{
	switch(dir) {
		case UP:
			if(map[y-1][x] != 1 && map[y-1][x] != 100)
				return false;
			break;
			
		case DOWN:
			if(map[y+1][x] != 1 && map[y+1][x] != 100)
				return false;
			break;
		
		case LEFT:
			if(map[y][x-1] != 1 && map[y][x-1] != 100)
				return false;
			break;
			
		case RIGHT:
			if(map[y][x+1] != 1 && map[y][x+1] != 100)
				return false;
			break;
			
		case STILL:
			return false;
	}
	return true;
}

bool Map::inSkipCoinsList(int x, int y)
{
	for(auto i = skipCoins.begin(); i != skipCoins.end(); i++) {
		if(i->first == x && i->second == y)
			return true;
	}
	return false;
}

// Returns a tuple with members: map, height, width
std::tuple< std::vector<std::vector<int>>, int, int > Map::toMap(std::string filename)
{
	std::vector<unsigned char> png;
	std::vector<unsigned char> image;
	unsigned int init_width, init_height;
	
	unsigned error = lodepng::load_file(png, filename); // returns an error if there is one
	
	if(!error) {
		error = lodepng::decode(image, init_width, init_height, png);
	}

	if(error) {
		std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl; // this should be changed to throw + something...
	}
	
	std::vector<std::vector<int> > init_map; 
	
	for(unsigned int y = 0; y < init_height; y++) {
		std::vector<int> temp;
		for(unsigned int x = 0; x < init_width; x++) {

			if( (int)image[4*init_width*y + 4*x + 0] == 255 &&
				(int)image[4*init_width*y + 4*x + 1] == 255 &&
				(int)image[4*init_width*y + 4*x + 2] == 255 &&
				(int)image[4*init_width*y + 4*x + 3] == 255 ) {
					temp.push_back(0);
				}
			else if( (int)image[4*init_width*y + 4*x + 0] == 255 &&
				(int)image[4*init_width*y + 4*x + 1] == 0 &&
				(int)image[4*init_width*y + 4*x + 2] == 0 &&
				(int)image[4*init_width*y + 4*x + 3] == 255 ) {
					temp.push_back(1);
				}
			else if( (int)image[4*init_width*y + 4*x + 0] == 0 &&
				(int)image[4*init_width*y + 4*x + 1] == 255 &&
				(int)image[4*init_width*y + 4*x + 2] == 0 &&
				(int)image[4*init_width*y + 4*x + 3] == 255 ) {
					temp.push_back(1);
					if(inSkipCoinsList(x,y))
						addCoin(std::make_pair(x,y), 10, DEAD);
					else
						addCoin(std::make_pair(x,y), 10, ALIVE);
				}
			else {
				temp.push_back(-1);
			}
		}
		init_map.push_back(temp);
	}
	std::tuple< std::vector< std::vector<int> >, int, int > ret_tuple = std::make_tuple(init_map, init_height, init_width);
	return ret_tuple;
}
