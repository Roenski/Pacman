#include "drawing.hpp"

void startGame(Window &window)
{
	sf::Event event;
	Pacman pacman("../images/pacman.png", std::make_pair(29,29));
	Map map("../images/Map2.png", "../images/Map2_tech.png");
	window.startWindow("Pacman");
	Direction wantedDirection = STILL;
	while(window.isOpened()) {
		
		window.clear("white");
		
		while(window.checkEvent(event)) {
			if(window.isClosed(event)) {
				window.close();
			}
			else if(window.arrowKeyPressed()) { // direction changed already in the function
				wantedDirection = window.getKeyPress();
			}
		}
		
		if(map.availableDirection(wantedDirection, pacman.getX(), pacman.getY())) { 
			pacman.setDirection(wantedDirection);
		}
		if(map.availableDirection(pacman.getDirection(), pacman.getX(), pacman.getY())) {
			pacman.move();
		}
			
		window.drawMap();
		window.drawPacman(pacman.getX(), pacman.getY(), pacman);
		window.display();
		window.setFramerate(30);
	}
}
