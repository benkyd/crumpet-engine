#include "texturemanager.h"

#include <SDL2/SDL_image.h>

TextureManager::TextureManager(Renderer* renderer) {
    m_renderer = renderer;
}

bool TextureManager::registerTexture(std::string textureSource, std::string textureName) {
    SDL_Texture* texture;
	SDL_Surface* loadSurface = IMG_Load(textureSource.c_str());
	if (loadSurface == NULL) {
		Logger::error("ERROR LOADING SURFACE");
        Logger::panic(SDL_GetError());
        return false;
	}
	texture = SDL_CreateTextureFromSurface(m_renderer->SDLRenderer, loadSurface);
	if (texture == NULL) {
		Logger::error("ERROR LOADING TEXTURE");
        Logger::panic(SDL_GetError());
        return false;
    }
	SDL_FreeSurface(loadSurface);

    Texture* temp = new Texture(textureName, textureSource, texture);
    m_registerdTextures[textureName] = temp;

    Logger::info("Loaded texture " + textureSource + " as " + textureName);

    return true;
}

void TextureManager::unregisterTexture(std::string textureName) {
    SDL_DestroyTexture(m_registerdTextures[textureName]->texture);
    delete &m_registerdTextures[textureName];
}

Texture* TextureManager::getTexture(std::string textureName) {
    return m_registerdTextures[textureName];
}

SDL_Texture* TextureManager::getSDLTexture(std::string textureName) {
    return m_registerdTextures[textureName]->texture;
}

std::string TextureManager::getTextureSource(std::string textureName) {
    return m_registerdTextures[textureName]->source;
}

TextureManager::~TextureManager() {
    for (std::map<std::string, Texture*>::iterator it = m_registerdTextures.begin(); it != m_registerdTextures.end(); it++) {
        SDL_DestroyTexture(m_registerdTextures[it->first]->texture);
        delete m_registerdTextures[it->first];
    }
}
