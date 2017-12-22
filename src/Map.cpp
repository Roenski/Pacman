#include "Map.hpp"

Map::Map(std::string filename)
{
	std::tuple< std::vector<std::vector<int>>, int, int > bunch = toMap(filename);
	map = std::get<0>(bunch);
	height = std::get<1>(bunch);
	width = std::get<2>(bunch);
	std::cout << "check2";
}

// Returns a tuple with members: map, height, width
std::tuple< std::vector<std::vector<int>>, int, int > Map::toMap(std::string filename)
{
	std::vector<unsigned char> png;
	std::vector<unsigned char> image;
	unsigned w, h;
	
	unsigned error = lodepng::load_file(png, filename); // returns an error if there is one
	
	if(!error) {
		error = lodepng::decode(image, w, h, png);
	}

	if(error) {
		std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl; // this should be changed to throw + something...
	}
	
	std::vector<std::vector<int> > init_map; 
	
	for(int y = 0; y < height; y++) {
		std::vector<int> temp;
		for(int x = 0; x < width; x++) {

			if( (int)image[4*width*y + 4*x + 0] == 255 &&
				(int)image[4*width*y + 4*x + 1] == 255 &&
				(int)image[4*width*y + 4*x + 2] == 255 &&
				(int)image[4*width*y + 4*x + 3] == 255 ) {
					temp.push_back(0);
				}
			else {
				temp.push_back(-1);
			}
		}
		init_map.push_back(temp);
	}
	std::tuple< std::vector< std::vector<int> >, int, int > ret_tuple = std::make_tuple(init_map, height, width);
	return ret_tuple;
}
