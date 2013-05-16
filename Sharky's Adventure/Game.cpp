#include <SFML/Graphics.hpp>
#include <iostream>
#include "Camera.h"
#include "Player.h"
#include "Multiplayer.h"
#include "Level.h"
#include "Enemies.h"
#include "Game.h"
#include <fstream>


Game::Game(){
	groundLevel = 600;
	isMultiplayer = false;
	player2.alterSprite();
	player2.isLocal = false;
	enemies.addEnemy(sf::Vector2f(1800,550) , sf::Vector2i(1800,550));
	level.loadLevel();
	Camera camera;
	Multiplayer multiplayer;
	Level level;
	Enemies enemies;
	Player player;
	Player player2;
	if(!text.loadFromFile("images/underwater.png"))
		std::cout << "ERROROROROROR" << std::endl;
	//if(!music.openFromFile("data/dirediredocks.ogg"))
	if(!music.openFromFile("data/music.ogg"))
		std::cout << "error\n";
	music.setLoop(true);
	music.play();
	music.setVolume(20);
	background.setTexture(text);
	background.setScale(.78f,.78f);
	output.open("output.txt",std::ios_base::app);
	design = false;
	
}

void Game::runGame(sf::RenderWindow *window){
	

		
		
		window->setView(window->getDefaultView());
		window->draw(background);
		window->setView(camera.view);
		level.draw(window);
		player.bulletCollision(&enemies.badies,&level.obs);
		player2.bulletCollision(&enemies.badies,&level.obs);
	
		player.move(&level.obs,groundLevel);
		player.moveBullets(window);

		player.draw(window);

		enemies.draw(window);
		camera.updateCam(&player);

		

		if(isMultiplayer){
			multiplayer.updatePos(player.shape.getPosition());
			multiplayer.updateAnim((sf::Uint8)player.animPos, player.facingRight);
			player2.shape.setPosition(multiplayer.hostPosition);		
			if(multiplayer.isShoot){
				player2.shootBullets(multiplayer.hostOrigin,multiplayer.hostTarget);
				multiplayer.isShoot = false;
			}
			player2.moveBullets(window);
			player2.draw(window, multiplayer.hostAnimPos, multiplayer.hostRightFace);
		}

		
}

void Game::pollGame(sf::Event event, sf::RenderWindow *window){
	player.pollEvent(event);
	if(event.type == sf::Event::KeyReleased){
		switch(event.key.code){
		case sf::Keyboard::Num0:
			multiplayer.switchMode(0);
			isMultiplayer = false;
			break;
		case sf::Keyboard::Num1:
			multiplayer.switchMode(1);
			isMultiplayer = true;
			break;
		case sf::Keyboard::Num2:
			std::cout << "Enter ip address: ";
			std::cin >> multiplayer.ip;
			multiplayer.switchMode(2);
			isMultiplayer = true;
			break;
		case sf::Keyboard::Num3:
			design = !design;
			if(design) std::cout << "Design mode on\n";
			else std::cout << "Design mode off\n";
			break;
		}

	}

	if(event.type == sf::Event::MouseButtonPressed){
		if(event.mouseButton.button == sf::Mouse::Left){
			player.shootBullets(player.shape.getPosition(),sf::Vector2i(sf::Mouse::getPosition(*window).x + (camera.view.getCenter().x - 400),sf::Mouse::getPosition(*window).y));
			if(isMultiplayer){
				multiplayer.shoot(player.shape.getPosition(),sf::Vector2i(sf::Mouse::getPosition(*window).x + (camera.view.getCenter().x - 400),sf::Mouse::getPosition(*window).y));
			}
		}
		if(event.mouseButton.button == sf::Mouse::Right){
			sf::Vector2f p(sf::Mouse::getPosition(*window).x + (camera.view.getCenter().x - 400), sf::Mouse::getPosition(*window).y);
			enemies.addEnemy(p);
				
		}
	}
	if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Middle && design){
		mx1 = sf::Mouse::getPosition(*window).x+ camera.view.getCenter().x - 400;
		my1 = sf::Mouse::getPosition(*window).y;
	}
	if(event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Middle && design){
		int mx2 = sf::Mouse::getPosition(*window).x +camera.view.getCenter().x - 400;
		int my2 = sf::Mouse::getPosition(*window).y;
				
		level.addPlat((mx2-mx1),(my2-my1),mx1,my1);
		std::cout << "addPlat("<<(mx2-mx1)<<","<<(my2-my1)<<","<<mx1<<","<<my1<<");\n";//",sf::Color::Blue);\n";
		output << "addPlat("<<(mx2-mx1)<<","<<(my2-my1)<<","<<mx1<<","<<my1<<");\n";//<<",sf::Color::Blue);\n";
				
	}
}


