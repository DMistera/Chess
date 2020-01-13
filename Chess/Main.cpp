//#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include "Application.h"
#include "Stoper.h"
#include "AppConsts.h"
#include <iostream>

int main() {
	std::cout << "Start!\n";
	unsigned int windowSize = Piece::PIECE_SIZE * 8;
	sf::RenderWindow& window = AppConsts::RENDER_WINDOW;
	window.setFramerateLimit(60);
	Application application;
	Stoper stoper;
	double deltaTime = 0;
	while (window.isOpen()) {
		stoper.start();
		application.update(deltaTime);
		sf::Event event;
		if (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			application.handleEvent(event);
		}
		window.clear();
		window.draw(application);
		window.display();
		stoper.stop();
		deltaTime = stoper.elapsedTime();
	}
	return 0;
}