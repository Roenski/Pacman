#include "drawing.hpp"

void startGame(Window &window)
{
	sf::Event event;
	window.startWindow("Pacman");
	while(window.isOpened()) {
		window.clear("black");
		while(window.checkEvent(event)) {
			
		}
		window.display();
	}
}
