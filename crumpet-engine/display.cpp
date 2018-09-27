#include "display.h"

Display::Display(std::string title, int width, int height) {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cout << "SDL could not initialize, SDL ERROR: " << SDL_GetError() << std::endl;
	}

	m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(m_renderer, 123, 122, 0, 255);

	isClosed = false;
}

void Display::Update() {

}

bool Display::IsClosed() {
	return isClosed;
}

void Display::Close() {
	isClosed = true;
}

Display::~Display() {
	isClosed = true;
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}
