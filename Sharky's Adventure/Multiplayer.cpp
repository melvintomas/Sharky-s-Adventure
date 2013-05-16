#include "Multiplayer.h"
#include <SFML/Network.hpp>
#include <iostream>
#include <sstream>
#include <string>




Multiplayer::Multiplayer()
: sendThread(&Multiplayer::sendPosition, this), receiveThread(&Multiplayer::getHostPos, this){

	 // Create a socket and bind it to the port 55001

	ip = "127.0.0.1";
	//ip= "10.4.2.135";
	//ip = "10.4.1.136";
	 //ip = "10.4.1.60";
	 // Send a message to 192.168.1.50 on port 55002
	 //std::string message = "Hi, I am " + sf::IpAddress::getLocalAddress().toString();
	 //socket.send(message.c_str(), message.size() + 1, ip, sendPort);

	isRunning = false;
	isShoot = false;
	connected = false;
 }

void Multiplayer::switchMode(int newMode){
	//0 = off
	//1 = Server
	//2 = Client
	mode = newMode;
	if(isRunning){stop(); }
	switch(newMode){
	case 0:
		break;
	case 1:
		receivePort = 55002;
		sendPort = 55001;
		launch();
		break;
	case 2:
		receivePort = 55001;
		sendPort = 55002;
		launch();
		break;
	}
}


void Multiplayer::launch(){
	if(!isRunning){
		isRunning = true;
		socket.bind(receivePort);
		sendThread.launch();
		receiveThread.launch();
	}
}

void Multiplayer::stop(){
	sendThread.terminate();
	receiveThread.terminate();
	mode = 0;
}

void Multiplayer::updatePos(sf::Vector2f pos){
	position = pos;	
}

void Multiplayer::updateAnim(sf::Uint8 pos, bool rFace){
	animPos = pos;
	rightFace = rFace;
}

void Multiplayer::sendPosition(){
	while(isRunning && !connected && mode == CLIENT){
		connect();
		sf::sleep(sf::milliseconds(25));
	}

	while(isRunning && !connected && mode == SERVER){
		
		sf::sleep(sf::milliseconds(25));
	}

	while(isRunning){
		packet.clear();
		packet << POSITION << position.x << position.y;
		
		socket.send(packet,ip, sendPort);

		packet.clear();
		
		packet << ANIMATION << animPos << rightFace;		
		socket.send(packet,ip, sendPort);
		//std::cout << "SENDING" << ANIMATION << ": " << animPos << " " << rightFace << std::endl;
		//socket.send(&position, sizeof(position), ip, sendPort);
		sf::sleep(sf::milliseconds(25));
	}
}

void Multiplayer::shoot(sf::Vector2f origin, sf::Vector2i mouse){
	sf::Packet packet;
	packet.clear();
	packet << SHOOT << origin.x << origin.y << mouse.x << mouse.y;
	socket.send(packet,ip, sendPort);
}

void Multiplayer::reply(){
	sf::Packet packet;
	packet.clear();
	packet << REPLY;
	socket.send(packet,ip, sendPort);
}

void Multiplayer::connect(){
	sf::Packet packet;
	packet.clear();
	
	if(ip == "127.0.0.1"){
		clientIP =  sf::IpAddress::LocalHost.toInteger();
	}else{
		clientIP =  sf::IpAddress::getLocalAddress().toInteger();
	}
	packet << SETUP << clientIP;
	socket.send(packet,ip, sendPort);
}

void Multiplayer::getHostPos(){
	
	while(isRunning){
		sf::Packet packet2;
		sf::Vector2f buffer;
		std::size_t received = 0;
		sf::IpAddress sender;		
		float x,y;
		unsigned short port;

		packet2.clear();

		socket.receive(packet2, sender, port);
		
		
		if(mode == 1 && !connected){

		}
		
		
		
		packet2 >> header; 
		//std::cout << "RECIEVED: " <<header << std::endl;
		
		switch (header){
		case POSITION:
			packet2 >> x >> y;
			hostPosition = sf::Vector2f(x, y);
			//std::cout << "RECEIVED POSITION\n";
			break;
		case ANIMATION:
			packet2 >> hostAnimPos >> hostRightFace;
			break;
		case SHOOT:
			isShoot = true;
			packet2 >> originX >> originY >> targetX >> targetY;
			hostOrigin = sf::Vector2f(originX,originY);
			hostTarget = sf::Vector2i(targetX,targetY);
			break;
		case SETUP:			
			packet2 >> clientIP;
			ip = sf::IpAddress(clientIP);
			connected = true;
			reply();
			break;
		case REPLY:
			connected = true;
			break;
		}


		
		
		//socket.receive(&buffer, sizeof(buffer),received,sender,port);
		//std::cout << sender.toString() << " said: " << buffer.x << " " << buffer.y << std::endl;
		//hostPosition = buffer;
		
		
		//std::cout << packet.getDataSize() << " ";

		//packet >> header;
		//std::cout << header << std::endl;
		//hostPosition = sf::Vector2f(x, y);

		//hostPosition = buffer;
		
		
	}
	socket.unbind();
}