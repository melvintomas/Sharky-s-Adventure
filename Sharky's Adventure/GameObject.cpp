#include "GameObject.h"

GameObject::GameObject(){
	
	
}
bool GameObject::collides(GameObject *obj){
	if (shape.getGlobalBounds().intersects(obj->shape.getGlobalBounds())){
		return true;
	}
	return false;
	
}
void GameObject::draw(sf::RenderWindow *rw){
	rw->draw(shape);
}