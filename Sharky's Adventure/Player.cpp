#include "Player.h"
#include <vector>


Player::Player(){
	facingRight = true;
	facingLeft = false;
	onSurface = false;
	bulletTimer = 0;
	bulletTimeout = 10;
	width;
	height;
	animTimer = 0;
	animTimeout = 2;
	animPos = 0;
	isLocal = true;
	
	leftPressed = false;
	rightPressed = false;
	upPressed = false;
	downPressed = false;
	hitTop = false;
	gravity = 1;

	xVelocity = 0;
	yVelocity = 0;

	if(!text.loadFromFile("images/sharkySprite.png"))
		std::cout << "ERROROROROROR" << std::endl;
	shape.setTexture(text);
	
	if(!bulletText.loadFromFile("images/sharkbullet.png"))
		std::cout << "ERROROROROROR" << std::endl;

	if(!sfxjumpbuffer.loadFromFile("data/jump.wav")){
		std::cout << "Could not load sound" << std::endl;
	}
	sfxjump.setBuffer(sfxjumpbuffer);
	sfxjump.setVolume(50);

	width = text.getSize().x/8;
	height = text.getSize().y;

	for(int i = 0; i < 8; ++i){
		spritePos.push_back(i*width);
	}
	shape.setTextureRect(sf::IntRect(spritePos[0],0,width,height));
	bulletSpeed = 20;
	//shape.setScale(sf::Vector2f(50,100));
	//shape.setColor(sf::Color::Red);
	shape.setPosition(100,500);
	shape.setOrigin(width/2,0);
	collisionBox.setSize(sf::Vector2f(50,100));
	collisionBox.setOrigin(25,0);
	collisionBox.setPosition(shape.getOrigin());
	collisionBox.setFillColor(sf::Color::Red);
}
void Player::shootBullets(sf::Vector2f origin, sf::Vector2i mouse){
	if(bulletTimer <= 0){
		sf::Sprite bullet;
		bullet.setTexture(bulletText);
		//bullet.setRadius(10);
		//bullet.setFillColor(sf::Color::Yellow);
		bullet.setPosition(origin);
	
		

		float x = mouse.x - origin.x;
		float y = origin.y - mouse.y;

		bullet.rotate(atan(-y/x)*180/(22/7));
		//std::cout << bullet.getRotation() << std::endl;

		if (x < 0) {
			bullet.setScale(-1.0f,1.0f);
		}

		

		bullets.push_back(bullet);
		//std::cout << mouse.x << ", " << mouse.y << "\t" << origin.x << ", " << origin.y << "\t" << x << ", " << y << std::endl;

		bulletVelocity.push_back(sf::Vector2f(x/(abs(x)+abs(y))*bulletSpeed,y/(abs(y)+abs(x))*bulletSpeed));
		
		bulletTimer = bulletTimeout;
		
	}
}

void Player::alterSprite(){
		if(!text.loadFromFile("images/sharky2.png"))
		std::cout << "ERROROROROROR" << std::endl;
}

void Player::moveBullets(sf::RenderWindow *rw){
	for(unsigned int i = 0; i < bullets.size(); i++){
		bullets[i].move(bulletVelocity[i].x,0-bulletVelocity[i].y);
		rw->draw(bullets[i]);
	}

}
void Player::draw(sf::RenderWindow *rw){
	animate();
	rw->draw(shape);
	
	//rw->draw(collisionBox);
}

void Player::draw(sf::RenderWindow *rw, sf::Uint8 aPos, bool rFace){
	if(bulletTimer > 0){
		bulletTimer--;
	}
	//std::cout << "draw" << std::endl;
	if(facingLeft && rFace){
		shape.scale(-1.0f,1.0f);
		facingLeft = false;
		facingRight = true;
	} else if(facingRight && !rFace){
		shape.scale(-1.0f,1.0f);
		facingLeft = true;
		facingRight = false;
	}
	if (aPos >= 8) aPos = 0; 
	shape.setTextureRect(sf::IntRect(spritePos[aPos],0,width,height));
	
	
	//std::cout << bullets.size() << std::endl;
	rw->draw(shape);
	//rw->draw(collisionBox);
}


void Player::animate(){
	if(bulletTimer > 0){
		bulletTimer--;
	}
	if(xVelocity > 0 && facingLeft){
		shape.scale(-1.0f,1.0f);
		facingLeft = false;
		facingRight = true;
	} else if(xVelocity < 0 && facingRight){
		shape.scale(-1.0f,1.0f);
		facingLeft = true;
		facingRight = false;
	}
	if(xVelocity != 0){
		if(animTimer > 0){
			animTimer--;
		} else{
			shape.setTextureRect(sf::IntRect(spritePos[animPos],0,width,height));
			animPos++;
			if(animPos >= 8){
				animPos = 0;
			}
		}
	}else{
		animPos = 0;
		shape.setTextureRect(sf::IntRect(spritePos[animPos],0,width,height));
	}
	if(yVelocity > 0){
		animPos = 2;
		shape.setTextureRect(sf::IntRect(spritePos[2],0,width,height));
	}
}

void Player::bulletCollision(std::vector<sf::Sprite> *badies,std::vector<sf::RectangleShape> *obs){
	for(unsigned int i = 0; i < bullets.size(); i++){
			
			//if bullet hits bad guy			
			for(unsigned int j=0;j<badies->size();j++){
				if((badies->at(j)).getGlobalBounds().intersects(shape.getGlobalBounds())){
							std::cout << "YOU LOSE\n";
					}
				if((badies->at(j)).getGlobalBounds().intersects(bullets[i].getGlobalBounds())){
					badies->erase(badies->begin() + j);
					//std::cout << j << std::endl;
					bullets.erase(bullets.begin() + i);
					bulletVelocity.erase(bulletVelocity.begin() + i);
					i--;
					j = badies->size();
				} 
				
			}

			//if bullets get off screen, remove them
			if(i < bullets.size()){
				if(bullets[i].getPosition().y < -50 || bullets[i].getPosition().y > 650){
					bullets.erase(bullets.begin() + i);
					bulletVelocity.erase(bulletVelocity.begin() + i);
					i--;
				}
			}


			//remove bullets if collide with objects
			if(i < bullets.size()){
				std::cout << i << " i\n";
				for(unsigned int j=0;j<obs->size();j++){
					if((obs->at(j)).getGlobalBounds().intersects(bullets[i].getGlobalBounds())){
						bullets.erase(bullets.begin() + i);
						bulletVelocity.erase(bulletVelocity.begin() + i);
						i--;
						j = obs->size();
					}
				}
			}

		
		}
}

void Player::move(std::vector<sf::RectangleShape> *obs, float groundLevel){
	//Logic
		if(leftPressed&&!rightPressed) {
			xVelocity = -7;
		}else if(!leftPressed&&rightPressed){
			xVelocity = 7;
		}else xVelocity = 0;


		if(upPressed && onSurface){
			onSurface = false;
			yVelocity = 20;
			upPressed = false;
			sfxjump.play();
		}
		
		yVelocity -= gravity;
		if(yVelocity <= -20){
			yVelocity = -20;
		}
		if(hitTop){
			yVelocity = -1;
			hitTop = false; 
		}

	//Move x
	collisionBox.move(xVelocity,0);

	//Handle x collision
	for(unsigned int i=0 ; i < obs->size();++i){
		while(collisionBox.getGlobalBounds().intersects(obs->at(i).getGlobalBounds())){
				if(xVelocity > 0){
					collisionBox.move(-1,0);
				}
				else{
					collisionBox.move(1,0);
				}
				
			}
	}

	//Move y
	collisionBox.move(0,-yVelocity);
	//Handle y collision
	
	
	for(unsigned int i=0 ; i < obs->size();++i){
		while(collisionBox.getGlobalBounds().intersects(obs->at(i).getGlobalBounds())){
			if(yVelocity > 0 ){
				collisionBox.move(0,1);
				hitTop = true;
			} else if(yVelocity < 0){
				onSurface = true;
				collisionBox.move(0,-1);
			}
				
		}
		
	}
	
	
	//Hits the ground
	if(collisionBox.getPosition().y + collisionBox.getGlobalBounds().height > groundLevel){
			onSurface=true;
			yVelocity=0;
			collisionBox.setPosition(collisionBox.getPosition().x,groundLevel - collisionBox.getGlobalBounds().height);
	} /*else if(onSurface && collisionBox.getPosition().y + collisionBox.getGlobalBounds().height < groundLevel){
			for(int i=0;i<obs->size();++i){ //if player is not 1 pixel above an object, it falls
				if(!obs->at(i).getGlobalBounds().contains(collisionBox.getPosition().x,collisionBox.getGlobalBounds().top + collisionBox.getGlobalBounds().height+1) ){
					yVelocity-=1; //yVelocity -= gravity;
					collisionBox.move(0,-yVelocity);
					onSurface=false;
				}


			}
	}

	//General y collision
	for(int i = 0; i < obs->size(); ++i){
		if(collisionBox.getGlobalBounds().intersects(obs->at(i).getGlobalBounds())){

			if(yVelocity>0){
				yVelocity = 0;
				collisionBox.setPosition(collisionBox.getPosition().x,obs->at(i).getPosition().y+obs->at(i).getSize().y);
			}
			else{
				onSurface = true;
				yVelocity=0;
				collisionBox.setPosition(collisionBox.getPosition().x,obs->at(i).getPosition().y-collisionBox.getGlobalBounds().height);
			}			
		}	
	}*/
	
	shape.setPosition(collisionBox.getPosition());
}

void Player::pollEvent(sf::Event event){

		if(event.type == sf::Event::KeyPressed)
		{
			switch(event.key.code){
			case sf::Keyboard::A:
				leftPressed = true;
				break;
			case sf::Keyboard::D:
				rightPressed = true;
				break;
			case sf::Keyboard::W:
				upPressed = true;
				break;
			case sf::Keyboard::S:
				downPressed = true;
				break;
			case sf::Keyboard::Escape:
				break;
			case sf::Keyboard::Space:
				upPressed = true;
				break;
			case sf::Keyboard::Left:
				leftPressed = true;
				break;
			case sf::Keyboard::Right:
				rightPressed = true;
				break;
			case sf::Keyboard::Up:
				upPressed = true;
				break;
			}

		}
		if(event.type == sf::Event::KeyReleased){
			switch(event.key.code){
			case sf::Keyboard::A:
				leftPressed = false;
				break;
			case sf::Keyboard::D:
				rightPressed = false;
				break;
			case sf::Keyboard::W:
				upPressed = false;
				break;
			case sf::Keyboard::S:
				downPressed = false;
				break;
			case sf::Keyboard::Space:
				upPressed = false;
				break;
			case sf::Keyboard::Left:
				leftPressed = false;
				break;
			case sf::Keyboard::Right:
				rightPressed = false;
				break;
			case sf::Keyboard::Up:
				upPressed = false;
				break;
			}

		}

}
