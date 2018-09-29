#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include "entity.h"

enum struct SpriteType {
	SPRITE_DEFAULT,
	SPRITE_ANIMATED,
	SPRITE_STATIC
};

class Sprite : public Entity {
public:
	Sprite(std::string name, SDL_Renderer* SDLRenderer, SpriteType mode);
	
	SpriteType Spritetype = SpriteType::SPRITE_DEFAULT;
	
	bool LoadSpriteTextures(std::string path);

	virtual ~Sprite();
private:
	SDL_Texture *m_spriteSheetTexture;
};

