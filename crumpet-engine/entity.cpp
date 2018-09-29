#include "entity.h"

Entity::Entity(std::string name, SDL_Renderer* SDLRenderer, RenderType mode) {
	this->m_name = name;
	this->m_SDLRenderer = SDLRenderer;
	this->Rendertype = mode;
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

void Entity::SetVecPoints(std::vector<Vec2> polyPoints) {
	this->m_polyPoints = polyPoints;
}

void Entity::AddVecPoint(Vec2 point) {
	this->m_polyPoints.push_back(point);
}

void Entity::SetPolyDrawType(PolyDrawType type) {
	this->Drawtype = type;
}

void Entity::Render() {
	if (Rendertype == RenderType::MODE_TEXTURE)
		SDL_RenderCopy(m_SDLRenderer, m_texture, NULL, NULL);
	// if (RenderType == EntityType::MODE_POLYGON)
		
}

Entity::~Entity() {

}
