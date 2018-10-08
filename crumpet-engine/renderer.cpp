#include "renderer.h"
#include "entity.h"

Renderer::Renderer(std::string title, int width, int height, int targetFramerate) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL could not initialize, SDL ERROR: " << SDL_GetError() << std::endl;
	}
	std::cout << "SDL initialized" << std::endl;

	m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	std::cout << "SDL window created" << std::endl;

	if (targetFramerate == 0)
		SDLRenderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
	if (targetFramerate == 1)
		SDLRenderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
	
	this->Width = width;
	this->Height = height;

	isClosed = false;
}

void Renderer::RenderEntity(Entity* entity) {
	entity->Render();
}

void Renderer::RenderSprite(Sprite* sprite, SpriteState state) {
	sprite->Spritestate = state;
	sprite->Render();
}

void Renderer::RenderSprite(Sprite* sprite) {
	sprite->Render();
}

void Renderer::SetRendererColour(Vec4* col) {
	SDL_SetRenderDrawColor(SDLRenderer, col->x, col->y, col->z, col->w);
}

void Renderer::RenderEmptyRect(Rect* rect) {
	SDL_RenderDrawRect(SDLRenderer, rect->ToSDLRect);
}

void Renderer::RenderFilledRect(Rect* rect) {
	SDL_RenderFillRect(SDLRenderer, rect->ToSDLRect);
}

void Renderer::RenderLines(std::vector<Vec4*> points) {
	for (unsigned int i = 0; i < points.size(); i++) {
		SDL_RenderDrawLine(SDLRenderer, points[i]->x, points[i]->y, points[i]->z, points[i]->w);
	}
}

void Renderer::RenderTexture(Rect* fromRect, Rect* toRect, SDL_Texture* texture) {
	SDL_RenderCopy(SDLRenderer, texture, fromRect->ToSDLRect(), toRect->ToSDLRect());
}

void Renderer::RenderTexture(Rect* fromRect, Rect* toRect, SDL_Surface* surface) {
	SDL_Texture* texture = SDL_CreateTextureFromSurface(SDLRenderer, surface);
	SDL_RenderCopy(SDLRenderer, texture, fromRect->ToSDLRect(), toRect->ToSDLRect());
	SDL_DestroyTexture(texture);
}

void Renderer::RenderTexture(Rect* fromRect, Rect* toRect, SDL_Texture* texture, const double angle, Vec2* rotationCenter) {
	SDL_Point temp = { rotationCenter->x, rotationCenter->y };
	SDL_Point* center = new SDL_Point(temp);
	SDL_RenderCopyEx(SDLRenderer, texture, fromRect->ToSDLRect(), toRect->ToSDLRect(), angle, center, SDL_FLIP_NONE);
}

void Renderer::RenderTexture(Rect* fromRect, Rect* toRect, SDL_Surface* surface, const double angle, Vec2* rotationCenter) {
	SDL_Point temp = { rotationCenter->x, rotationCenter->y };
	SDL_Point* center = new SDL_Point(temp);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(SDLRenderer, surface);
	SDL_RenderCopyEx(SDLRenderer, texture, fromRect->ToSDLRect(), toRect->ToSDLRect(), angle, center, SDL_FLIP_NONE);
	SDL_DestroyTexture(texture);
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
