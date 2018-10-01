#include "sprite.h"

Sprite::Sprite(std::string name, SDL_Renderer* SDLRenderer, SpriteType mode) 
	: Entity(name, SDLRenderer) {

	this->m_SDLRenderer = SDLRenderer;
	this->Spritetype = mode;
}

bool Sprite::LoadSpriteTextures(std::string path) {
	SDL_Surface* loadedSurface = IMG_Load((PATH + path).c_str());
	if (loadedSurface == NULL) {
		std::cout << "Unable to load image from:" << (PATH + path).c_str() << " IMG ERROR: " << IMG_GetError() << std::endl;
		return false;
	}
	this->m_spriteSheetW = loadedSurface->w;
	this->m_spriteSheetH = loadedSurface->h;
	m_spriteSheetTexture = SDL_CreateTextureFromSurface(m_SDLRenderer, loadedSurface);

	SDL_FreeSurface(loadedSurface);
	return true;
}

void Sprite::UseSpriteSheet(SpriteState state, int startX, int startY, int width, int height, int seperation, int frames) {
	m_spriteMaps[state];
}

Sprite::~Sprite() {
	SDL_DestroyTexture(m_spriteSheetTexture);
}
