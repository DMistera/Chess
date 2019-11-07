//#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include "Application.h"
#include "Stoper.h"

#include <iostream>

int main() {
	std::cout << "Start!\n";
	unsigned int windowSize = Piece::PIECE_SIZE * 8;
	sf::RenderWindow window(sf::VideoMode(windowSize, windowSize), "Chess");
	Application application(&window);
	Stoper stoper;
	double deltaTime = 0;
	while (window.isOpen()) {
		stoper.start();
		application.update(deltaTime);
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		application.draw();
		window.display();
		stoper.stop();
		deltaTime = stoper.elapsedTime();
	}

	return 0;
}