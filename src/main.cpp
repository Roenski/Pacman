#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Map.hpp"
#include "Window.hpp"
#include "drawing.hpp"

int main()
{
	Window test("../images/Map2.png", "../images/Map2_tech.png");
	startGame(test);
}
