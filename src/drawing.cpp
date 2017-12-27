#include "drawing.hpp"

void startGame(Window &window)
{
	sf::Event event;
	window.startWindow("Pacman");
	while(window.isOpened()) {
		window.clear("white");
		while(window.checkEvent(event)) {
			if(window.isClosed(event)) {
				window.close();
			}
		}
		window.drawPixels();
		window.display();
		window.setFramerate(60);
	}
}
