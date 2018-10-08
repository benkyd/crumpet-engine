#include "sprite.h"

Sprite::Sprite(std::string name, SDL_Renderer* SDLRenderer, SpriteType mode)
	: Entity(name) {

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

// TODO: get this and the next method done correct
//at the moment the SpriteState(i) will just check for
//sprites with that state, and if they exist it will
//resize them, it needs to resize only the sprites
//in the std::map m_spriteSize
void Sprite::ResizeSprites(Vec2* newSize) {
	for (unsigned int i = 0; i < m_spriteSize.size(); i++) {
		m_spriteSize[SpriteState(i)]->x = newSize->x;
		m_spriteSize[SpriteState(i)]->y = newSize->y;
	}
}

void Sprite::ResizeSpritesByFactor(float factor) {
	for (unsigned int i = 0; i < m_spriteSize.size(); i++) {
		m_spriteSize[SpriteState(i)]->x *= factor;
		m_spriteSize[SpriteState(i)]->y *= factor;
	}
}

//These 2 methods work as they change a spesific and predefined
//sprite state
void Sprite::ResizeSpriteState(SpriteState state, Vec2* newSize) {
	m_spriteSize[state]->x = newSize->x;
	m_spriteSize[state]->y = newSize->y;
}

void Sprite::ResizeSpriteStateByFactor(SpriteState state, float factor) {
	m_spriteSize[state]->x *= factor;
	m_spriteSize[state]->y *= factor;
}

void Sprite::Move(Vec2* offset) {
	Pos.x += offset->x;
	Pos.y += offset->y;
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
