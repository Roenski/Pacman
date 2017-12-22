#ifndef WINDOW_HH
#define WINDOW_HH

#include "Map.hpp"
#include <map>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Window : public Map {
	
public:
	Window(std::string filename);
	bool checkEvent(sf::Event &event);
	void close();
	void clear(std::string color);
	void display();
	void drawMap();
	void drawMap2();
	bool isClosed(sf::Event &event);
	bool isOpened();
	void startWindow(std::string name);
	
	void printValues();
	
private:
	std::map<std::string, sf::Color> colors;
	sf::RenderWindow window;
};

#endif
