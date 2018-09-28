#pragma once

#include <string>
#include <SDL.h>
#include "renderer.h"
#include "entity.h"

class Game : public Renderer {
public:
	Game(std::string title, int width, int height, int targetFramerate, int targetUpdaterate);

	void PollEvents();

	virtual ~Game();
private:
	int targetFramerate;  // If 0, the engine will try as many as possibe, if 1, it will use vsync
	int targetUpdaterate; // If 0, the engine will try as many as possible

	int framerate;  // Current framerate
	int updaterate; // Current updaterate

	SDL_Event m_event;
};
