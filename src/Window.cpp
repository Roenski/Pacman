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

bool Window::checkEvent(sf::Event &event) {
	if(window.pollEvent(event)) { // an SFML function. 
																// Will be true, if there has been an event, e.g closing the window, mouse button pressed
		return true;
	}
	else
		return false;
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


