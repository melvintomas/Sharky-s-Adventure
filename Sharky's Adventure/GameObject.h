#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>


class GameObject{
private:	

public:
	//Image Sprite or Shape
	sf::Sprite shape;

	bool collides(GameObject *gob); //checks for collision of two objects
	void draw(sf::RenderWindow *rw);

	void collision(std::vector<GameObject *>);
	GameObject();
	

};
#endif GAMEOBJECT_H