#pragma once

#include <iostream>
#include <string>
#include <SDL.h>
#include "entity.h"
#include "sprite.h"

class Renderer {
public:
	Renderer(std::string title, int width, int height, int targetFramerate);

	SDL_Renderer *SDLRenderer;
	
	void RenderEntity(Entity* entity);

	void TickSpriteAnimation(Sprite* sprite);
	void RenderSprite(Sprite* sprite, SpriteState state);
	void RenderSprite(Sprite* sprite);

	void RenderUpdate();
	void RenderClear();

	bool IsDisplayClosed();
	void CloseDisplay();
	virtual ~Renderer();
private:
	SDL_Window *m_window;
	bool isClosed;
};

