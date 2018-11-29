#pragma once

#include "texturemanager.h"

class ResourceManger {
public:
    ResourceManger(Renderer* renderer) : textureManager(renderer) {};

    TextureManager textureManager;
};
