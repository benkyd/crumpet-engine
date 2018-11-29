#include "texturemanager.h"

TextureManager::TextureManager(Renderer* renderer) {
    m_renderer = renderer;
}

bool TextureManager::registerTexture(std::string textureSource, std::string textureName) {
    SDL_Texture* texture;
	SDL_Surface* loadSurface = IMG_Load(textureSource.c_str());
	if (loadSurface == NULL) {
		std::cout << "ERROR LOADING SURFACE " << SDL_GetError() << std::endl;
        return false;
	}
	texture = SDL_CreateTextureFromSurface(m_renderer->SDLRenderer, loadSurface);
	if (texture == NULL) {
		std::cout << "ERROR LOADING TEXTURE " << SDL_GetError() << std::endl;
        return false;
    }
	SDL_FreeSurface(loadSurface);

    m_textureSources[textureName] = textureSource;
    m_registerdTextures[textureName] = texture;

    return true;
}

void TextureManager::unregisterTexture(std::string textureName) {
    SDL_DestroyTexture(m_registerdTextures[textureName]);

    delete &m_textureSources[textureName];
    delete &m_registerdTextures[textureName];
}

SDL_Texture* TextureManager::getTexture(std::string textureName) {
    return m_registerdTextures[textureName];
}

std::string TextureManager::getTextureSource(std::string textureName) {
    return m_textureSources[textureName];
}

TextureManager::~TextureManager() {
    for (std::map<std::string, SDL_Texture*>::iterator it = m_registerdTextures.begin(); it != m_registerdTextures.end(); it++) {
        SDL_DestroyTexture(m_registerdTextures[it->first]);
    }
}
