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
	STATE_MISC1,
	STATE_MISC2,
	STATE_MISC3,
	STATE_MISC4,
	STATE_MISC5
};

class Sprite : public Entity {
public:
	Sprite(std::string name, SDL_Renderer* SDLRenderer, SpriteType mode);
	
	SpriteType Spritetype = SpriteType::SPRITE_DEFAULT;
	SpriteState Spritestate = SpriteState::STATE_DEFAULT;

	bool LoadSpriteTextures(std::string path);
	void UseSpriteSheet(SpriteState state, int startX, int startY, int width, int height, int seperation, int frames);
	void AnimateSprite(SpriteState state);
	void AnimateSprite();
	void Move();

	Vec2 Pos;
	Vec2 Size;
	void Render();

	virtual ~Sprite();
private:
	std::map <SpriteState, std::map<int, SDL_Rect*>> m_spriteMaps;
	std::map <SpriteState, Vec2*> m_spriteSize;

	SDL_Renderer* m_SDLRenderer;
	SDL_Texture* m_spriteSheetTexture;
	
	SpriteState m_lastSpritestate = SpriteState::STATE_DEFAULT;
	int m_spriteSheetW;
	int m_spriteSheetH;
	int m_currentFrame;
};
