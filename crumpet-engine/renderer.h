#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <SDL.h>
#include "entity.h"
#include "sprite.h"
#include "rect.h"

class Renderer {
public:
	Renderer(std::string title, int width, int height, int targetFramerate);

	SDL_Renderer *SDLRenderer;
	
	void RenderEntity(Entity* entity);

	void RenderSprite(Sprite* sprite, SpriteState state);
	void RenderSprite(Sprite* sprite);

	void SetRendererColour(Vec4* col);

	void RenderEmptyRect(Rect* rect);
	void RenderFilledRect(Rect* rect);
	void RenderLines(std::vector<Vec4*> points);
	void RenderTexture(Rect* fromRect, Rect* toRect, SDL_Texture* texture);
	void RenderTexture(Rect* fromRect, Rect* toRect, SDL_Surface* surface);
	void RenderTexture(Rect* fromRect, Rect* toRect, SDL_Texture* surface, const double angle, Vec2* rotationCenter);
	void RenderTexture(Rect* fromRect, Rect* toRect, SDL_Surface* surface, const double angle, Vec2* rotationCenter);

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
