#include "renderer.h"

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

void Renderer::SetRendererColour(Vec4* col) {
	SDL_SetRenderDrawColor(this->SDLRenderer, col->x, col->y, col->z, col->w);
}

void Renderer::RenderEmptyRect(Rect* rect) {
	SDL_Rect temp{ rect->GetX() - ActiveCamera->GetX(), rect->GetY() - ActiveCamera->GetY(), rect->GetW(), rect->GetH() };
	SDL_RenderDrawRect(this->SDLRenderer, &temp);
}

void Renderer::RenderFilledRect(Rect* rect) {
	SDL_Rect temp{ rect->GetX() - ActiveCamera->GetX(), rect->GetY() - ActiveCamera->GetY(), rect->GetW(), rect->GetH() };
	SDL_RenderFillRect(this->SDLRenderer, &temp);
}

void Renderer::RenderLines(std::vector<Vec4*> points) {
	for (unsigned int i = 0; i < points.size(); i++) {
		SDL_RenderDrawLine(this->SDLRenderer, points[i]->x - ActiveCamera->GetX(), points[i]->y - ActiveCamera->GetY(), points[i]->z - ActiveCamera->GetX(), points[i]->w - ActiveCamera->GetY());
	}
}

void Renderer::RenderTexture(Rect* fromRect, Rect* toRect, SDL_Texture* texture) {
	//Zoom implimentation (BROKEN)
	// SDL_Rect toSDLRect{ toRect->GetX() - ActiveCamera->GetX(), toRect->GetY() - ActiveCamera->GetY(), toRect->GetW() * ActiveCamera->Zoom, toRect->GetH() * ActiveCamera->Zoom };
	SDL_Rect toSDLRect{ toRect->GetX() - ActiveCamera->GetX(), toRect->GetY() - ActiveCamera->GetY(), toRect->GetW(), toRect->GetH() };
	SDL_RenderCopy(SDLRenderer, texture, fromRect->ToSDLRect(), &toSDLRect);
}

//TODO: apply camera renderer to these next 3 methiods
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

void Renderer::ApplyCameraToScene(Camera* camera) {
	this->ActiveCamera = camera;
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
