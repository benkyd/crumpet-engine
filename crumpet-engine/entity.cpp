#include "entity.h"

Entity::Entity(std::string name) {

	this->m_name = name;
	this->Rendertype = RenderType::MODE_TEXTURE;
}

Entity::Entity(std::string name, PolyDrawType drawType) {

	this->m_name = name;
	this->Drawtype = drawType;
	this->Rendertype = RenderType::MODE_POLYGON;
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

	this->m_textureW = loadedSurface->w;
	this->m_textureH = loadedSurface->h;

	this->Size.x = loadedSurface->w;
	this->Size.y = loadedSurface->h;

	SDL_FreeSurface(loadedSurface);
	return true;
}

bool Entity::LoadTexture(SDL_Surface* image) {
	m_texture = SDL_CreateTextureFromSurface(m_SDLRenderer, image);
	if (m_texture == NULL) {
		std::cout << "Unable to create texture SDL ERROR: " << SDL_GetError() << std::endl;
		return false;
	}

	SDL_FreeSurface(image);
	return true;
}

void Entity::SetDrawColour(Vec4 col) {
	
}

void Entity::SetRect(Rect* rect) {
	this->m_rect = rect;
}

void Entity::SetVecPoints(std::vector<Vec4*> points) {
	this->m_linePoints = points;
}

void Entity::AddVecPoint(Vec4* point) {
	this->m_linePoints.push_back(point);
}

void Entity::Render() {
	if (Rendertype == RenderType::MODE_TEXTURE) {
		SDL_Rect renderQuad = { Pos.x, Pos.y, Size.x, Size.y };
		SDL_RenderCopy(m_SDLRenderer, m_texture, NULL, &renderQuad);
	}


	if (Rendertype == RenderType::MODE_POLYGON) {
		SDL_SetRenderDrawColor(m_SDLRenderer, m_col.x, m_col.y, m_col.z, m_col.w);
		if (Drawtype == PolyDrawType::DRAW_FILLED_RECT)
			SDL_RenderFillRect(m_SDLRenderer, &m_rect);
		if (Drawtype == PolyDrawType::DRAW_OUTLINE_RECT)
			SDL_RenderDrawRect(m_SDLRenderer, &m_rect);

		if (Drawtype == PolyDrawType::DRAW_LINES) {
			for (unsigned int i = 0; i < m_linePoints.size(); i++) {
				SDL_RenderDrawLine(m_SDLRenderer, m_linePoints[i].x, m_linePoints[i].y, m_linePoints[i].z, m_linePoints[i].w);
			}
		}
	}
}

Entity::~Entity() {
	SDL_DestroyTexture(m_texture);
}
