#ifndef WINDOW_HH
#define WINDOW_HH

#include "Map.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Window : public Map {
	
public:
	Window(std::string filename);
	int calcScale(const int calc_height, const int calc_width);
	
private:
	int scale;
	std::vector<sf::Color> colors; // list of colors that can be used
};

#endif
