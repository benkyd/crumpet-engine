#pragma once 

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
#include <map>

#include "../renderengine/renderer.h"

class TextureManager {
public:
    TextureManager(Renderer* renderer);

    bool registerTexture(std::string textureSource, std::string textureName);
    void unregisterTexture(std::string textureName);
    SDL_Texture* getTexture(std::string textureName);
    std::string getTextureSource(std::string textureName);

    virtual ~TextureManager();
private:
    std::map<std::string, std::string> m_textureSources;
    std::map<std::string, SDL_Texture*> m_registerdTextures;
    Renderer* m_renderer;
};
