#include "drawing.hpp"

void startGame(Window &window)
{
	sf::Event event;
	enum Direction {
		Up,
		Down,
		Left,
		Right
	};
	
	window.startWindow("Pacman");
	int pacX = 20;
	int pacY = 17;
	while(window.isOpened()) {
		window.clear("white");
		while(window.checkEvent(event)) {
			if(window.isClosed(event)) {
				window.close();
			}
			else if(window.arrowKeyPressed(event)) {
				std::cout << "Arrow key Pressed\n";
				
			}
		}
		window.drawMap();
		window.drawPacman(pacX,pacY);
		window.display();
		pacX++;
		window.setFramerate(10);
	}
}
