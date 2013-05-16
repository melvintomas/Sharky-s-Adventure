#include "Enemies.h"
#include <SFML/Graphics.hpp>
#include <iostream>


Enemies::Enemies(){
	if(!text.loadFromFile("images/enemySprite.png"))
		std::cout << "ERROROROROROR" << std::endl;

	animPos = 0;
	width = text.getSize().x/4;
	height = text.getSize().y;

	for(int i = 0; i < 4; ++i){
		spritePos.push_back(i*width);
	}
	xVelocity = 1;

};

void Enemies::addEnemy(sf::Vector2f position, sf::Vector2i destination){
	enemy.setTexture(text);
	enemy.setPosition(position);
	badies.push_back(enemy);
}

void Enemies::addEnemy(sf::Vector2f position){
	enemy.setTexture(text);
	enemy.setPosition(position);
	badies.push_back(enemy);
}

void Enemies::draw(sf::RenderWindow *rw){
	animate();
	move();
	for(unsigned int i = 0; i < badies.size(); ++i){
		rw->draw(badies.at(i));
	}
	
	
}

void Enemies::move(){
	for(unsigned int i = 0; i < badies.size(); ++i){
		badies.at(i).move(-xVelocity, 0);
	}
}

void Enemies::animate(){
	if (animPos >= 8){
		animPos = 0;
	}
	for(unsigned int i = 0; i < badies.size(); ++i){
		badies.at(i).setTextureRect(sf::IntRect(spritePos[animPos/2],0,width,height));
	}
	animPos++;
}