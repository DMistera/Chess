#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include "Game.h"

int main() {
	unsigned int windowSize = Piece::PIECE_SIZE * 8;
	sf::RenderWindow window(sf::VideoMode(windowSize, windowSize), "Chess");
	Game game(&window);
	while (window.isOpen()) {
		game.update();
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		game.draw();
		window.display();
	}

	return 0;
}