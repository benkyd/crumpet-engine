#pragma once

#include "game.h"

class Entity {
public:
	Entity(std::string name, SDL_Renderer* SDLRenderer); // Texture overload
	// Entity(); // Polygon overload

	bool LoadTexture(std::string path);

	virtual ~Entity();
private:
	std::string m_name;

	SDL_Renderer* m_SDLRenderer;
	SDL_Texture* m_texture;
};

