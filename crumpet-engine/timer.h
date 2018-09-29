#pragma once

#include <iostream>
#include <string>
#include <SDL.h>

class Timer {
public:
	Timer() { pastTicks = SDL_GetTicks(); };

	void Tick() { pastTicks = SDL_GetTicks(); this->ticks++; }
	int GetTimeElapsed() { return SDL_GetTicks() - pastTicks; }
private:
	int ticks = 0;
	int pastTicks;
};
