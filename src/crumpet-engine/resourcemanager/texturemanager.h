#pragma once 

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <logger.h>
#include <string>
#include <map>

#include "../renderengine/renderer.h"

struct Texture {
    Texture(std::string name, std::string source, SDL_Texture* texture) 
        : name(name), source(source), texture(texture) { }
    Texture(std::string name, std::string source) 
        : name(name), source(source) { }
    std::string name;
    std::string source;
    SDL_Texture* texture;
};

class TextureManager {
public:
    TextureManager(Renderer* renderer);

    bool registerTexture(std::string textureSource, std::string textureName);
    void unregisterTexture(std::string textureName);
    SDL_Texture* getTexture(std::string textureName);
    std::string getTextureSource(std::string textureName);

    virtual ~TextureManager();
private:
    std::map<std::string, Texture*> m_registerdTextures;
    Renderer* m_renderer;
};
