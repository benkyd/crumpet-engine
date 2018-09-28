#pragma once

#include <iostream>
#include <string>
#include <SDL.h>
#include "entity.h"

#define PATH "C:/Users/Ben/Desktop/crumpet-engine"

class Renderer {
public:
	Renderer(std::string title, int width, int height);

	SDL_Renderer *SDLRenderer;
	void RenderEntity(Entity* entity);

	void Update();

	bool IsClosed();
	void Close();
	virtual ~Renderer();
private:
	SDL_Window *m_window;
	bool isClosed;
};

