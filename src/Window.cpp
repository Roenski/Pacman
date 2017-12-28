#include "Window.hpp"

Window::Window(std::string filename, std::string filename_bw, std::string filename_pacman) : Map(filename, filename_bw) 
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
	
	pacmanAddress = filename_pacman;
	
	if(!mapTexture.loadFromFile(address)) {
		//throw error
		std::cout << "Error loading map texture\n";
	}
	
	if(!pacmanTexture.loadFromFile(pacmanAddress)) {
		//throw error
		std::cout << "Error loading pacman texture\n";
	}
}

bool Window::arrowKeyPressed(sf::Event &event)
{
	return (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
					sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down));
}

// flushes the window with the given color
void Window::clear(std::string color)
{
	window.clear(colors[color]);
}

// closes the window
void Window::close()
{
	window.close();
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

// displays everything that has been drawn on the screen
void Window::display()
{
	window.display();
}

void Window::drawMap()
{
	sf::Sprite sprite;
	sprite.setTexture(mapTexture);
	sprite.setPosition(sf::Vector2f(0,0));
	window.draw(sprite);
}

void Window::drawPacman(int x, int y)
{
	sf::Sprite sprite;
	sprite.setTexture(pacmanTexture);
	sprite.setPosition(sf::Vector2f(x,y));
	window.draw(sprite);
}

void Window::drawPixels()
{
	for (auto i = map.begin(); i != map.end(); i++) {
		for (auto j = (*i).begin(); j != (*i).end(); j++) {
			if (*j == -1) {
				sf::RectangleShape rec; // initialize a rectangle
				rec.setSize(sf::Vector2f(1,1)); // sets the size to one pixel
				rec.setPosition(j-(*i).begin(),i-map.begin()); // sets the position on the window
				rec.setFillColor(sf::Color::Black); // set the color
				window.draw(rec); // send the rectangle to the window for drawing
													// it doesn't draw it yet: only when window.display() is called
			}
		}
	}
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

void Window::setFramerate(int fps)
{
	window.setFramerateLimit(fps);
}

/*
 * Starts the window.
 * Name is the name of the window, displayed on top of the window
*/
void Window::startWindow(std::string name) 
{
	sf::Texture texture;
	if(!texture.loadFromFile(address)) {
		//throw error
		std::cout << "Error loading address\n";
	}
	sf::Vector2u dimensions = texture.getSize();
	window.create(sf::VideoMode(dimensions.x, dimensions.y), name); // sf::Videomode is an SFML variable,
																							 // takes the window width and height as a variable
}

void Window::printValues()
{
	std::cout << height << " " << width << " " << map[0].size() << std::endl;
}
