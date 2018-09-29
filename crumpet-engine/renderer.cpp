#include "renderer.h"
#include "entity.h"

Renderer::Renderer(std::string title, int width, int height, int targetFramerate) {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cout << "SDL could not initialize, SDL ERROR: " << SDL_GetError() << std::endl;
	}

	m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	
	if (targetFramerate == 0)
		SDLRenderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
	if (targetFramerate == 1)
		SDLRenderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
	
	isClosed = false;
}

void Renderer::RenderEntity(Entity* entity) {
	entity->Render();
}

void Renderer::RenderUpdate() {
	SDL_SetRenderDrawColor(SDLRenderer, 66, 134, 244, 255);
	SDL_RenderPresent(SDLRenderer);
}

void Renderer::RenderClear() {
	SDL_RenderClear(SDLRenderer);
}

bool Renderer::IsDisplayClosed() {
	return isClosed;
}

void Renderer::CloseDisplay() {
	isClosed = true;
}

Renderer::~Renderer() {
	isClosed = true;
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}
