#include "drawing.hpp"

void startGame(Window &window)
{
	sf::Event event;
	Pacman pacman("../images/pacman.png");
	
	window.startWindow("Pacman");
	int pacX = 20;
	int pacY = 17;
	while(window.isOpened()) {
		window.clear("white");
		while(window.checkEvent(event)) {
			if(window.isClosed(event)) {
				window.close();
			}
			else if(window.arrowKeyPressed(pacman)) {
				
			}
		}
		
		if(pacman.getDirection() == LEFT)
			pacX--;
		else if(pacman.getDirection() == RIGHT)
			pacX++;
		else if(pacman.getDirection() == UP)
			pacY--;
		else if(pacman.getDirection() == DOWN)
			pacY++;
			
		window.drawMap();
		window.drawPacman(pacX, pacY, pacman);
		window.display();
		window.setFramerate(30);
	}
}
