#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <SDL.h>
#include <SDL_image.h>
#include "entity.h"

enum struct SpriteType {
	SPRITE_DEFAULT,
	SPRITE_ANIMATED,
	SPRITE_STATIC
};

enum struct SpriteState {
	STATE_DEFAULT,
	STATE_LEFT,
	STATE_RIGHT,
	STATE_UP,
	STATE_DOWN,
	STATE_TOP,
	STATE_BOTTOM,
	STATE_FRONT,
	STATE_BACK,
	STATE_JUMP,
	STATE_CROUCH,
	STATE_ATTACKING,
};

class Sprite : public Entity {
public:
	Sprite(std::string name, SDL_Renderer* SDLRenderer, SpriteType mode);
	
	SpriteType Spritetype = SpriteType::SPRITE_DEFAULT;
	SpriteState Spritestate = SpriteState::STATE_DEFAULT;

	bool LoadSpriteTextures(std::string path);
	void UseSpriteSheet(SpriteState state, int startX, int startY, int width, int height, int seperation, int frames);
	void AnimateSprite(SpriteState state);
	void Move();

	void Render();

	virtual ~Sprite();
private:
	std::map<SpriteState, std::vector<SDL_Rect*>> m_spriteMaps;

	SDL_Renderer* m_SDLRenderer;
	SDL_Texture* m_spriteSheetTexture;
	
	int m_spriteSheetW;
	int m_spriteSheetH;
};

