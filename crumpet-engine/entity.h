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
	Entity(std::string name, SDL_Renderer* SDLRenderer); // Texture overload
	Entity(std::string name, SDL_Renderer* SDLRenderer, PolyDrawType drawType); // Polygon overload

	RenderType Rendertype = RenderType::MODE_DEFAULT;
	PolyDrawType Drawtype = PolyDrawType::DRAW_DEFAULT;

	bool LoadTexture(std::string path);
	bool LoadTexture(SDL_Surface* image);

	void SetDrawColour(Vec4 col);

	void SetRect(Vec2 pos, Vec2 size);

	void SetVecPoints(std::vector<Vec4> points);
	void AddVecPoint(Vec4 point);

	void Render();

	Vec2 Pos;
	Vec2 Size;
	
	virtual ~Entity();
protected:
	std::string PATH = "C:/Users/Ben/Desktop/crumpet-engine";
	// std::string PATH = "E:/Games/crumpet-engine";
private:
	std::string m_name;

	Vec2 m_rectPos;
	Vec2 m_rectSize;
	SDL_Rect m_rect;

	Vec4 m_col;

	std::vector<Vec4> m_linePoints;
	SDL_Texture* m_texture;
	int m_textureW;
	int m_textureH;

	SDL_Renderer* m_SDLRenderer;
};

