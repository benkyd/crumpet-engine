#pragma once

#include <string>
#include <map>
#include <SDL.h>
#include "renderer.h"
#include "camera.h"

class Game {
public:
	Game(std::string title, int width, int height, int targetFramerate, int targetUpdaterate);

	Renderer* renderer;
	std::map<std::string, Camera*> Cameras;

	void AddCamera(std::string name, Camera* camera);
	void UseCamera(std::string name);

	void PollEvents();

	int TargetMsPerFrame;  // If 0, the engine will try as many as possibe, if 1, it will use vsync
	int TargetMsPerUpdate; // If 0, the engine will try as many as possible
	int MsPerFrame;        // Current framerate
	int MsPerUpdate;       // Current updaterate

	virtual ~Game();
	SDL_Event m_event;
};
