#include "Camera.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Camera::Camera(){
	view.setSize(800,600);
	view.setCenter(400,300);

	leftBoundary = 0;
	rightBoundary =  800;

	camLeftBound = 0;
	camRightBound = 500;
	camSpeed = 0;
}


void Camera::updateCam(Player *p){
	//player moves beyond right boundry
	if(p->shape.getPosition().x > camRightBound){
		//camSpeed is less than the player's velocity
		if (camSpeed <= p->xVelocity){
			camSpeed += 1;							
		}
		if(p->shape.getPosition().x < view.getCenter().x - 50){
			camRightBound = p->shape.getPosition().x + 100;
			camLeftBound = p->shape.getPosition().x - 100;
			camSpeed = 0;
		}
	}else if(p->shape.getPosition().x < camLeftBound){
		if (camSpeed >= p->xVelocity)
			camSpeed -= 1;			
		if(p->shape.getPosition().x > view.getCenter().x + 50){
			camRightBound = p->shape.getPosition().x + 100;
			camLeftBound = p->shape.getPosition().x - 100;
			camSpeed = 0;
		}
	}
	view.move(camSpeed,0);

}



