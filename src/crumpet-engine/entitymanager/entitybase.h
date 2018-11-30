#pragma once

#include <string>
#include <math.h>

#include "../resourcemanager/resourcemanager.h"

class EntityBase {
public:
    EntityBase();

    SDL_Texture* texture;

    virtual ~EntityBase();
private:
    std::string textureRef;
    std::string textureSource;
    Vec2 textureDimensions;
};
