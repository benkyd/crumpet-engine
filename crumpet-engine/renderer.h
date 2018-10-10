#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <SDL.h>
#include "camera.h"

class Renderer {
public:
	Renderer(std::string title, int width, int height, int targetFramerate);

	SDL_Renderer *SDLRenderer;
	Camera* ActiveCamera;

	void SetRendererColour(Vec4* col);
	void RenderEmptyRect(Rect* rect);
	void RenderFilledRect(Rect* rect);
	void RenderLines(std::vector<Vec4*> points);
	void RenderTexture(Rect* fromRect, Rect* toRect, SDL_Texture* texture);
	void RenderTexture(Rect* fromRect, Rect* toRect, SDL_Surface* surface);
	void RenderTexture(Rect* fromRect, Rect* toRect, SDL_Texture* surface, const double angle, Vec2* rotationCenter);
	void RenderTexture(Rect* fromRect, Rect* toRect, SDL_Surface* surface, const double angle, Vec2* rotationCenter);

	void ApplyCameraToScene(Camera* camera);

	void RenderUpdate();
	void RenderClear();

	bool IsDisplayClosed();
	void CloseDisplay();

	int Width, Height;

	virtual ~Renderer();
private:
	SDL_Window *m_window;
	bool isClosed;
};
