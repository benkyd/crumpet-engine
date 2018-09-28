#include "entity.h"

Entity::Entity(std::string name, SDL_Renderer* SDLRenderer) {
	this->m_name = name;
	this->m_SDLRenderer = SDLRenderer;
}

bool Entity::LoadTexture(std::string path) {
	SDL_Surface* loadedSurface; // TODO: IMG_Load(path.c_str());
	if (loadedSurface == NULL) {
		std::cout << "Unable to load image from:" << path << " IMG ERROR: "; // TODO: << IMG_GetError() << std::endl;
		return false;
	}

	m_texture = SDL_CreateTextureFromSurface(m_SDLRenderer, loadedSurface);
	if (m_texture == NULL) {
		std::cout << "Unable to create texture from:" << path << " SDL ERROR: " << SDL_GetError() << std::endl;
		return false;
	}
	SDL_FreeSurface(loadedSurface);
	return true;
}

Entity::~Entity() {

}
