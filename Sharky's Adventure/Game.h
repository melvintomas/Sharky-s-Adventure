#pragma once
#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <SFML/Audio.hpp>


class Game{
private:	

public:

	Game();
	void Game::pollGame(sf::Event event, sf::RenderWindow *rw);
	void runGame(sf::RenderWindow *rw);
	
	
	sf::Music music;
	sf::Texture text;
	sf::Sprite background;
	Camera camera;
	Multiplayer multiplayer;
	Level level;
	Enemies enemies;
	Player player;
	Player player2;
	bool isMultiplayer;
	int groundLevel;
	int mx1;
	int my1;
	std::ofstream output;
	bool design;

};
#endif GAME_H