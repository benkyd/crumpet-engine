#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "renderengine/renderer.h"
#include "resourcemanager/resourcemanager.h"
#include "input/input.h"

class Game {
public:
    Game();

    ResourceManger resourceManager;
    TextureManager textureManager;
    Renderer renderer;
    Input input;

    // Entity list <- Renderer renders from this
    // Camera list and switching and adding

    virtual ~Game();
};
