#include "renderer.h"

Renderer::Renderer() {

}

void Renderer::createWindow(std::string title, int width, int height, ScreenMode mode) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL could not initialize, SDL ERROR: " << SDL_GetError() << std::endl;
	}
	std::cout << "SDL initialized" << std::endl;

	m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	std::cout << "SDL window created" << std::endl;

	if (mode == SCREEN_MODE_DEFAULT)
		SDLRenderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
	if (mode == SCREEN_MODE_VSYNC)
		SDLRenderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);

	SDL_SetRenderDrawColor(SDLRenderer, 66, 134, 244, 255);
	m_isWindowClosed = false;
}

bool Renderer::isWindowClosed() {
    return m_isWindowClosed;
}

void Renderer::destroyWindow() {
    m_isWindowClosed = true;
	SDL_DestroyWindow(m_window);
	SDL_Quit();
    std::cout << "SDL uninitialized" << std::endl;
}

void Renderer::clear() {
	SDL_RenderClear(SDLRenderer);
}

void Renderer::update() {
	SDL_SetRenderDrawColor(SDLRenderer, 66, 134, 244, 0);
	SDL_RenderPresent(SDLRenderer);
}

Renderer::~Renderer() {
    if (!m_isWindowClosed) {
        this->destroyWindow();
    }
}
