#include "sprite.h"

Sprite::Sprite(std::string name, SDL_Renderer* SDLRenderer, SpriteType mode)
	: Entity(name, SDLRenderer),
	  Pos(0, 0),
	  Size(0, 0) {

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

void Sprite::UseSpriteSheet(SpriteState state, int startX, int startY, int width, int height, int separation, int frames) {
	for (int i = 1; i <= frames; i++) {
		if (i == 1) {
			std::cout << startX << " " << startY << " " << width << " " << i << std::endl;
			SDL_Rect temp1 = { startX, startY, width, height };
			SDL_Rect* temp = new SDL_Rect(temp1);
			m_spriteMaps[state][i] = temp;
		} else {
			int x = (width * i) + startX + (separation * i - separation) - width;
			std::cout << x << " " << startY << " " << width << " " << i << std::endl;
			SDL_Rect temp1 = { x, startY, width, height };
			SDL_Rect* temp = new SDL_Rect(temp1);
			m_spriteMaps[state][i] = temp;
		}
	}

	std::cout << std::endl;
	Vec2 temp1(width, height);
	Vec2* temp = new Vec2(temp1);
	m_spriteSize[state] = temp;
}

void Sprite::TickAninmation() {
	if (m_lastSpritestate == Spritestate) {
		m_currentFrame++;
	} else {
		m_lastSpritestate = Spritestate;
		m_currentFrame = 1;
	}
	if (m_currentFrame > m_spriteMaps[Spritestate].size()) m_currentFrame = 1;
}

void Sprite::Render() {
	SDL_Rect* currentFrameClip = m_spriteMaps[Spritestate][m_currentFrame];
	Vec2* currentRenderSize = m_spriteSize[Spritestate];
	SDL_Rect  currentFrameDest = { Pos.x, Pos.y, currentRenderSize->x, currentRenderSize->y};

	SDL_RenderCopy(m_SDLRenderer, m_spriteSheetTexture, currentFrameClip, &currentFrameDest);
}

Sprite::~Sprite() {
	SDL_DestroyTexture(m_spriteSheetTexture);
}
