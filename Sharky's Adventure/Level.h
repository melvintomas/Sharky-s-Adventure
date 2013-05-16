#pragma once
#ifndef LEVEL_H
#define LEVEL_H

#include <SFML/Graphics.hpp>


class Level{

private:

public:
	Level();
	std::vector<sf::RectangleShape> obs;

	void addPlat(sf::Vector2f size, sf::Color color, sf::Vector2f position);
	void addPlat(float sX, float sY, float pX, float pY);
	void Level::addPlat(float sX, float sY, float pX, float pY,sf::Color color);
	void loadLevel();
	void draw(sf::RenderWindow *rw);
	

};

#endif LEVEL_H