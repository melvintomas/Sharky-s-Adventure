#pragma once
#ifndef MULTIPLAYER_H
#define MULTIPLAYER_H

#include <SFML/Network.hpp>


class Multiplayer{

private:
	
public:
	

	void updatePos(sf::Vector2f pos);
	void sendPosition();
	void getHostPos();
	void launch();
	void stop();
	void updateAnim(sf::Uint8 pos, bool rightFace);
	void shoot(sf::Vector2f origin, sf::Vector2i mouse);
	void switchMode(int mode);
	void reply();
	void connect();
	int getMode();

	static const sf::Uint8 POSITION = 1;
	static const sf::Uint8 ANIMATION = 2;
	static const sf::Uint8 SHOOT = 3;
	static const sf::Uint8 SETUP = 4;
	static const sf::Uint8 REPLY = 5;
	

	static const sf::Uint8 OFF = 0;
	static const sf::Uint8 SERVER = 1;
	static const sf::Uint8 CLIENT = 2;


	Multiplayer();
	unsigned short sendPort;
	unsigned short receivePort;
	

	sf::Uint32 clientIP;
	sf::UdpSocket socket;
	sf::IpAddress ip;
	sf::Thread sendThread;
	sf::Thread receiveThread;
	sf::Vector2f position;
	sf::Vector2f hostPosition;
	sf::Vector2f hostOrigin;
	sf::Vector2i hostTarget;
	sf::Uint8 animPos;
	sf::Uint8 hostAnimPos;
	sf::Packet packet;
	sf::Uint8 header; 
	bool rightFace;
	bool hostRightFace;
	
	bool isRunning;
	bool isShoot;
	bool connected;
	
	float originX, originY;
	int targetX, targetY;
	int mode;


};

#endif CLIENT_H