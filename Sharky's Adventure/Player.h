#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"


class Player : public GameObject
{

private:

public:
	
	std::vector<sf::Sprite> bullets;
	std::vector<sf::Vector2f> bulletVelocity;
	std::vector<int> spritePos;
	sf::RectangleShape collisionBox;

	int bulletSpeed;	
	
	void shootBullets(sf::Vector2f origin, sf::Vector2i mouse);
	void alterSprite();
	void moveBullets(sf::RenderWindow *rw);	
	void draw(sf::RenderWindow *rw);
	void Player::draw(sf::RenderWindow *rw, sf::Uint8, bool rFace);
	void Player::bulletCollision(std::vector<sf::Sprite> *badies,std::vector<sf::RectangleShape> *obs);
	void move(std::vector<sf::RectangleShape> *obs, float groundLevel);
	void animate();
	void pollEvent(sf::Event event);

	//Sound
	sf::SoundBuffer sfxjumpbuffer;
	sf::Sound sfxjump;
	
	//Textures
	sf::Texture text;
	sf::Texture bulletText;
	sf::Sprite bullet;
	Player();

	int bulletTimer;
	int bulletTimeout;
	int width;
	int height;
	int animTimer;
	int animTimeout;
	int animPos;

	bool facingLeft;
	bool facingRight;
	bool hitTop;
	int xVelocity;
	int yVelocity;
	int gravity;

	bool onSurface;
	bool isLocal;

	
	bool leftPressed;
	bool rightPressed;
	bool upPressed;
	bool downPressed;

	
	


};

#endif PLAYER_H