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

	void RenderSprite(Sprite* sprite, SpriteState state);
	void RenderSprite(Sprite* sprite);

	void SetRendererColour(Vec4* col);

	void RenderEmptyRect();
	void RenderFilledRect();
	void RenderLines();
	void RenderTexture();

	void RenderUpdate();
	void RenderClear();

	bool IsDisplayClosed();
	void CloseDisplay();

	int Width, Height;

	virtual ~Renderer();
private:
	SDL_Window *m_window;
	bool isClosed;
};

