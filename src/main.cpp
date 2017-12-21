#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Map.hpp"
#include "Window.hpp"
#include "drawing.hpp"

int main()
{
	Window test("../images/16x16.png");
	startGame(test);
}
