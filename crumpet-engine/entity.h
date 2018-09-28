#pragma once

#include <string>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

enum struct EntityType {
	MODE_DEFAULT,
	MODE_TEXTURE,
	MODE_POLYGON
};

class Entity {
public:
	Entity(std::string name, SDL_Renderer* SDLRenderer, EntityType mode); // Texture overload
	// Entity(); // Polygon overload

	EntityType RenderType = EntityType::MODE_DEFAULT;

	bool LoadTexture(std::string path);
	void Render();

	virtual ~Entity();
private:
	std::string m_name;

	// std::string PATH = "C:/Users/Ben/Desktop/crumpet-engine";
	std::string PATH = "E:/Games/crumpet-engine";

	SDL_Texture* m_texture;
	SDL_Renderer* m_SDLRenderer;
};

