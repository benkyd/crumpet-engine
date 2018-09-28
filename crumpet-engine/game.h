#pragma once

#include <string>
#include "renderer.h"
#include "entity.h"

class Game {
public:
	Game(std::string title, int width, int height, int targetFramerate, int targetUpdaterate);

	void UpdateDisplay();
	void CloseDisplay();
	bool IsDisplayClosed();

	Renderer GetDisplay();

	void PollEvents();

	virtual ~Game();
private:
	int targetFramerate;  // If 0, the engine will try as many as possibe, if 1, it will use vsync
	int targetUpdaterate; // If 0, the engine will try as many as possible

	int framerate;  // Current framerate
	int updaterate; // Current updaterate

	Renderer m_display;
	SDL_Event m_event;
};
