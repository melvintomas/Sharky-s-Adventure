#pragma once
#ifndef ENEMIES_H
#define ENEMIES_H

#include <SFML/Graphics.hpp>
#include "GameObject.h"


class Enemies : public GameObject{

private:

public:
	Enemies();
	std::vector<sf::Sprite> badies;
	std::vector<sf::Vector2i> path;
	void addEnemy(sf::Vector2f position);
	void addEnemy(sf::Vector2f position, sf::Vector2i destination);
	void loadEnemies();
	void draw(sf::RenderWindow *rw);
	void animate();
	void Enemies::move();

	sf::Texture text;
	sf::Sprite enemy;
	std::vector<int> spritePos;
	int width;
	int height;
	int animPos;
	int xVelocity;

	

};

#endif LEVEL_H