#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Map.hpp"
#include "Window.hpp"

int main()
{
	Window test("../images/16x16.png");
	sf::Event event;
	test.startWindow("Pacman");
	while(test.isOpened()) {
		test.clear("black");
		while(test.checkEvent(event)) {
			
		}
		test.display();
	}
}
