#ifndef _GAME_H_
#define _GAME_H_

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "renderengine/renderer.h"
#include "resourcemanager/resourcemanager.h"
#include "entitymanager/entitymanager.h"
#include "input/input.h"

class Game {
public:
    Game();

    ResourceManger resourceManager;
    TextureManager textureManager;
    EntityManager entityManager;
    Renderer renderer;
    Input input;

    // Entity list <- Renderer renders from this
    // Camera list and switching and adding

    virtual ~Game();
};

#endif
