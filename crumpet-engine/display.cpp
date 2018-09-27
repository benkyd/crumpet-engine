#include "display.h"

Display::Display(std::string title, int width, int height) {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cout << "SDL could not initialize! SDL_Error: %s\n" << SDL_GetError() << std::endl;
	}

	m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	m_screenSurface = SDL_GetWindowSurface(m_window);

	isClosed = false;
}

bool Display::IsClosed() {
	return isClosed;
}

Display::~Display() {
	isClosed = true;
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}
