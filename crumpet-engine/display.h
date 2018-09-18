#pragma once

#include <iostream>
#include <string>
#include <sdl2/SDL.h>
#include <GL/glew.h>

class Display {
public:
	Display(unsigned int width, unsigned int height, std::string name);
	
	void Update();
	bool IsClosed();
	
	virtual ~Display();
private:
	SDL_Window* _window;
	SDL_GLContext _glContext;

	bool _isClosed;
};

