#include <SFML/Graphics.hpp>
#include <iostream>
#include "Camera.h"
#include "Player.h"
#include "Multiplayer.h"
#include "Level.h"
#include "Enemies.h"
#include "Game.h"




	int mode;

	void startMain(sf::Sprite *mainSprite);
	void pollMenu(sf::Event *event,sf::RenderWindow *window);
	void runMenu(sf::RenderWindow *window, sf::Sprite *sprite);

int main(){

	//setup window
	sf::RenderWindow window;
	window.create(sf::VideoMode(800,600),"Game");
	window.setFramerateLimit(30);
	window.setVerticalSyncEnabled(true);
	sf::Sprite mainSprite;
	Game game;
	mode = 0;
	sf::Texture text;
	if(!text.loadFromFile("images/titleScreen.png"))
		std::cout << "ERROROROROROR" << std::endl;
	

	mainSprite.setTexture(text);
	//Game loop

	//startGame();
	while(window.isOpen()){
		window.clear();
		sf::Event event;
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed){
				game.output.close();
				window.close();
			}
			switch(mode){
			case 1:
				game.pollGame(event,&window);
				break;
			case 0:	
				pollMenu(&event, &window);
				break;
			}
		}
		switch(mode){
		case 1:
			game.runGame(&window);
			break;
		case 0:	
			runMenu(&window, &mainSprite);
			break;
		}
		
		window.display();
	}//End of Game loop
	return 0;
}

void pollMenu(sf::Event *event, sf::RenderWindow *window){	
	if(event->type == sf::Event::MouseButtonPressed){
		std::cout << sf::Mouse::getPosition(*window).x << " " << sf::Mouse::getPosition(*window).y << "\n";
		if(sf::Mouse::getPosition(*window).x >= 330 && sf::Mouse::getPosition(*window).x <= 430){
			if(sf::Mouse::getPosition(*window).y >= 350 && sf::Mouse::getPosition(*window).y <= 400){
				mode = 1;
			} else if(sf::Mouse::getPosition(*window).y >= 450 && sf::Mouse::getPosition(*window).y <= 500){
				window->close();
			}
		}
	}

}

void runMenu(sf::RenderWindow *window, sf::Sprite *sp){
	window->draw(*sp);
}


