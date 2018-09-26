#pragma once

#include <iostream>
#include <string>
#include <SDL.h>

class Display {
public:
	Display(std::string title, int width, int height);
	bool IsClosed();
	virtual ~Display();
private:
	SDL_Window *m_window;
	bool isClosed;
};

