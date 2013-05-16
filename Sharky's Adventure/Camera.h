#pragma once
#ifndef CAMERA_H
#define CAMERA_H

#include "Player.h"


class Camera{

private:

public:
	

	
	void updateCam(Player *p);
	Camera();
	sf::View view;
	int leftBoundary;
	int rightBoundary;
	int camLeftBound;
	int camRightBound;
	int camSpeed;
};

#endif CAMERA_H