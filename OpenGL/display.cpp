#include <GL/glew.h>
#include <iostream>

#include "display.h"

Display::Display(int width, int height, const std::string& title) {
	SDL_Init(SDL_INIT_VIDEO);

	SDL_GL_SetSwapInterval(0);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
	m_glContext = SDL_GL_CreateContext(m_window);

	GLenum status = glewInit();
	if (status != GLEW_OK) {
		std::cerr << "GLEW Failed to initialize" << std::endl;
	}

	SDL_WarpMouseInWindow(m_window, width / 2, height / 2);
	SDL_SetRelativeMouseMode(SDL_TRUE);

	m_isClosed = false;
	std::cout << "Display initialized and gl context successfuly created" << std::endl;
}

void Display::Update() {
	SDL_GL_SwapWindow(m_window);
}

bool Display::isClosed() {
	return m_isClosed;
}

Display::~Display() {
	SDL_GL_DeleteContext(m_glContext);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
	m_isClosed = true;
}
