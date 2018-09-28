#include "entity.h"

Entity::Entity(std::string name, SDL_Renderer* SDLRenderer, EntityType mode) {
	this->m_name = name;
	this->m_SDLRenderer = SDLRenderer;
	this->RenderType = mode;
}

bool Entity::LoadTexture(std::string path) {
	SDL_Surface* loadedSurface = IMG_Load((PATH + path).c_str());
	if (loadedSurface == NULL) {
		std::cout << "Unable to load image from:" << (PATH + path).c_str() << " IMG ERROR: " << IMG_GetError() << std::endl;
		return false;
	}

	m_texture = SDL_CreateTextureFromSurface(m_SDLRenderer, loadedSurface);
	if (m_texture == NULL) {
		std::cout << "Unable to create texture from:" << (PATH + path).c_str() << " SDL ERROR: " << SDL_GetError() << std::endl;
		return false;
	}
	SDL_FreeSurface(loadedSurface);
	return true;
}

void Entity::Render() {
	if (RenderType == EntityType::MODE_TEXTURE)
		SDL_RenderCopy(m_SDLRenderer, m_texture, NULL, NULL);
	// if (RenderType == EntityType::MODE_POLYGON)
		
}

Entity::~Entity() {

}
