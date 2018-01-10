#ifndef WINDOW_HH
#define WINDOW_HH

#include "Map.hpp"
#include "Pacman.hpp"
#include <map>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Window : public Map {
	
public:
	Window(std::string filename, std::string filename_bw);
	bool arrowKeyPressed();
	bool checkEvent(sf::Event &event);
	void close();
	void clear(std::string color);
	void display();
	void drawMap();
	void drawFrames();
	void drawPacman(int x, int y, Pacman pacman);
	void drawPixels();
	Direction getKeyPress();
	bool isClosed(sf::Event &event);
	bool isOpened();
	void setFramerate(int fps);
	void startWindow(std::string name);
	void printValues();
	
private:
	std::map<std::string, sf::Color> colors;
	sf::RenderWindow window;
	sf::Texture mapTexture;
};

#endif
