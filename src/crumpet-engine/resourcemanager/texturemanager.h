#ifndef _RESOURCEMANAGER_TEXTUREMANAGER_H_
#define _RESOURCEMANAGER_TEXTUREMANAGER_H_

#include <SDL2/SDL.h>
#include <vector>
#include <string>
#include <map>

#include <logger.h>
#include <math.h>
#include "../renderengine/renderer.h"

struct Texture {
    Texture(std::string name, std::string source, SDL_Texture* texture) 
        : name(name), source(source), texture(texture) { }
    Texture(std::string name, std::string source) 
        : name(name), source(source) { }
    std::string name;
    std::string source;
    SDL_Texture* texture;
    // Vec2<int>* textureDimensions;
};

struct TextureMap {
    std::vector<Texture*> textures;
};

class TextureManager {
public:
    TextureManager(Renderer* renderer);

    bool registerTexture(std::string textureSource, std::string textureName);
    void unregisterTexture(std::string textureName);
    Texture* getTexture(std::string textureName);
    SDL_Texture* getSDLTexture(std::string textureName);
    std::string getTextureSource(std::string textureName);

    virtual ~TextureManager();
private:
    std::map<std::string, Texture*> m_registerdTextures;
    Renderer* m_renderer;
};

#endif
