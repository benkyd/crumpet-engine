#include "renderer.h"

Renderer::Renderer(std::string title, int width, int height) {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cout << "SDL could not initialize, SDL ERROR: " << SDL_GetError() << std::endl;
	}

	m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	SDLRenderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(SDLRenderer, 66, 134, 244, 255);

	isClosed = false;
}

void Renderer::Update() {
	SDL_RenderClear(SDLRenderer);
	SDL_RenderPresent(SDLRenderer);
}

bool Renderer::IsClosed() {
	return isClosed;
}

void Renderer::Close() {
	isClosed = true;
}

Renderer::~Renderer() {
	isClosed = true;
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}
