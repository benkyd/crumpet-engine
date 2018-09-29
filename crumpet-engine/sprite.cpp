#include "sprite.h"

Sprite::Sprite(std::string name, SDL_Renderer* SDLRenderer, SpriteType mode) 
	: Entity(name, SDLRenderer) {

}

Sprite::~Sprite() {

}
