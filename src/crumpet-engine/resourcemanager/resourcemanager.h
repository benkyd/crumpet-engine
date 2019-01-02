#ifndef _RESOURCEMANAGER_RESOURCEMANAGER_H_
#define _RESOURCEMANAGER_RESOURCEMANAGER_H_

#include "texturemanager.h"

class ResourceManger {
public:
    ResourceManger(Renderer* renderer) : textureManager(renderer) {};

    TextureManager textureManager;

    virtual ~ResourceManger() {};
};

#endif
