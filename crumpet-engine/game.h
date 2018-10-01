#pragma once

#include <string>
#include <SDL.h>
#include "renderer.h"
#include "timer.h"
#include "entity.h"
#include "sprite.h"

class Game : public Renderer {
public:
	Game(std::string title, int width, int height, int targetFramerate, int targetUpdaterate);

	void PollEvents();

	int TargetMsPerFrame;  // If 0, the engine will try as many as possibe, if 1, it will use vsync
	int TargetMsPerUpdate; // If 0, the engine will try as many as possible
	int MsPerFrame;        // Current framerate
	int MsPerUpdate;       // Current updaterate

	virtual ~Game();
	SDL_Event m_event;
};
