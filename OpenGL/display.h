#pragma once

#include <sdl2/SDL.h>
#include <string>

class Display {
public:
	Display(int width, int height, const std::string& title);

	void Update();
	bool isClosed();

	virtual ~Display();
private:
	SDL_Window* m_window;
	SDL_GLContext m_glContext;

	bool m_isClosed;
};
