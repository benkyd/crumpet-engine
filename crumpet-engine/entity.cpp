#include "entity.h"

Entity::Entity(std::string name, Renderer* renderer) {

	this->m_name = name;
	this->Rendertype = RenderType::MODE_TEXTURE;
}

Entity::Entity(std::string name, Renderer* renderer, PolyDrawType drawType) {

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

	m_texture = SDL_CreateTextureFromSurface(m_renderer->SDLRenderer, loadedSurface);
	if (m_texture == NULL) {
		std::cout << "Unable to create texture from:" << (PATH + path).c_str() << " SDL ERROR: " << SDL_GetError() << std::endl;
		return false;
	}

	this->m_textureW = loadedSurface->w;
	this->m_textureH = loadedSurface->h;

	this->Size->x = loadedSurface->w;
	this->Size->y = loadedSurface->h;

	SDL_FreeSurface(loadedSurface);
	return true;
}

bool Entity::LoadTexture(SDL_Surface* image) {
	m_texture = SDL_CreateTextureFromSurface(m_renderer->SDLRenderer, image);
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
		Rect renderQuad(Pos->x, Pos->y, Size->x, Size->y);
		m_renderer->RenderTexture(m_rect, &renderQuad, m_texture);
	}

	if (Rendertype == RenderType::MODE_POLYGON) {
		m_renderer->SetRendererColour(m_col);
		if (Drawtype == PolyDrawType::DRAW_FILLED_RECT)
			m_renderer->RenderFilledRect(m_rect);
		if (Drawtype == PolyDrawType::DRAW_OUTLINE_RECT)
			m_renderer->RenderEmptyRect(m_rect);

		if (Drawtype == PolyDrawType::DRAW_LINES) {
			m_renderer->RenderLines(m_linePoints);
		}
	}
}

Entity::~Entity() {
	SDL_DestroyTexture(m_texture);
}
