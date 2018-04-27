#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include "Game.h"
#include "Stoper.h"

int main() {
	unsigned int windowSize = Piece::PIECE_SIZE * 8;
	sf::RenderWindow window(sf::VideoMode(windowSize, windowSize), "Chess");
	Game game(&window);
	Stoper stoper;
	double deltaTime = 0;
	while (window.isOpen()) {
		stoper.start();
		game.update(deltaTime);
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		game.draw();
		window.display();
		stoper.stop();
		deltaTime = stoper.elapsedTime();
	}

	return 0;
}