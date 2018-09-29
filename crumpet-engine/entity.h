#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include "mathHelper.h"

enum struct RenderType {
	MODE_DEFAULT,
	MODE_TEXTURE,
	MODE_POLYGON
};

enum struct PolyDrawType {
	DRAW_DEFAULT,
	DRAW_FILLED_RECT,
	DRAW_OUTLINE_RECT,
	DRAW_LINES
};

class Entity {
public:
	Entity(std::string name, SDL_Renderer* SDLRenderer, RenderType mode); // Texture overload
	// Entity(); // Polygon overload

	RenderType Rendertype = RenderType::MODE_DEFAULT;
	PolyDrawType Drawtype = PolyDrawType::DRAW_DEFAULT;

	bool LoadTexture(std::string path);

	void SetVecPoints(std::vector<Vec2> polyPoints);
	void AddVecPoint(Vec2 point);
	void SetPolyDrawType(PolyDrawType type);
	
	void Render();

	virtual ~Entity();
private:
	std::string m_name;

	std::vector<Vec2> m_polyPoints;
	SDL_Texture* m_texture;

	std::string PATH = "C:/Users/Ben/Desktop/crumpet-engine";
	// std::string PATH = "E:/Games/crumpet-engine";

	SDL_Renderer* m_SDLRenderer;
};

