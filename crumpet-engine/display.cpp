#include "display.h"

Display::Display(unsigned int width, unsigned int height, std::string name) {
	SDL_Init(SDL_INIT_VIDEO);

	SDL_GL_SetSwapInterval(0);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	_window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
	_glContext = SDL_GL_CreateContext(_window);

	GLenum status = glewInit();
	if (status != GLEW_OK) {
		std::cout << "GLEW Failed to initialize" << std::endl;
	}

	// SDL_WarpMouseInWindow(_window, width / 2, height / 2);
	// SDL_SetRelativeMouseMode(SDL_TRUE);

	_isClosed = false;
}

void Display::Update() {
	SDL_GL_SwapWindow(_window);
}

bool Display::IsClosed() {
	return _isClosed;
}

Display::~Display() {
	SDL_GL_DeleteContext(_glContext);
	SDL_DestroyWindow(_window);
	SDL_Quit();
	_isClosed = true;
}
