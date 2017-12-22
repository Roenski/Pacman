#include "Window.hpp"

Window::Window(std::string filename) : Map(filename) 
{
	auto color_list = {sf::Color::Yellow, sf::Color::Blue, sf::Color::Green, sf::Color::Cyan, sf::Color::Magenta, sf::Color::Black, sf::Color::White};
	auto keys = {"yellow", "blue", "green", "cyan", "magenta", "black", "white"};
	auto keys_it = keys.begin();
	auto color_it = color_list.begin();
	while(keys_it != keys.end() && color_it != color_list.end()) {
		colors.insert({*keys_it, *color_it});
		keys_it++; 
		color_it++;
	}
}

bool Window::checkEvent(sf::Event &event)
{
	if(window.pollEvent(event)) { // an SFML function. 
																// Will be true, if there has been an event, e.g closing the window, mouse button pressed
		return true;
	}
	else
		return false;
}

void Window::drawMap()
{
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (map[j][i] == -1) {
				sf::RectangleShape rec; // initialize a rectangle
				rec.setSize(sf::Vector2f(1,1)); // sets the size to one pixel
				rec.setPosition(i,j); // sets the position on the window
				rec.setFillColor(sf::Color::White); // set the color
				window.draw(rec); // send the rectangle to the window for drawing
													// it doesn't draw it yet: only when window.display() is called
			}
		}
	}
}

/*
 * Starts the window.
 * Name is the name of the window, displayed on top of the window
*/
void Window::startWindow(std::string name) 
{
	window.create(sf::VideoMode(800,800), name); // sf::Videomode is an SFML variable,
																							 // takes the window width and height as a variable
}

bool Window::isClosed(sf::Event &event)
{
	return (event.type == sf::Event::Closed);
}

// returns true, if the window is open, false, if not
bool Window::isOpened()
{
	return window.isOpen();
}

// closes the window
void Window::close()
{
	window.close();
}

// flushes the window with the given color
void Window::clear(std::string color)
{
	window.clear(colors[color]);
}

// displays everything that has been drawn on the screen
void Window::display()
{
	window.display();
}

void Window::printValues()
{
	std::cout << height << " " << width << " " << map[0].size() << std::endl;
}
