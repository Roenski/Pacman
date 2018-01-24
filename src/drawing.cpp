#include "drawing.hpp"

void startGame(Window &window)
{
	sf::Event event;
	Pacman pacman("../images/pacman.png", std::make_pair(30,30));
	window.startWindow("Pacman");
	Direction wantedDirection = STILL;
	while(window.isOpened()) {
		
		window.clear("white");
		
		while(window.checkEvent(event)) {
			if(window.isClosed(event)) {
				window.close();
			}
			else if(window.arrowKeyPressed()) { 
				wantedDirection = window.getKeyPress();
			}
		}
		
		if(window.availableDirection(wantedDirection, pacman.getX(), pacman.getY())) { 
			pacman.setDirection(wantedDirection);
		}
		if(window.availableDirection(pacman.getDirection(), pacman.getX(), pacman.getY())) {
			pacman.move();
			window.checkEatenCoins(pacman);
		}
			
		window.drawMap();
		window.drawCoins();
		window.drawPacman(pacman.getX(), pacman.getY(), pacman);
		window.display();
		window.setFramerate(30);
	}
}
