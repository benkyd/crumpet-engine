#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "renderengine/renderer.h"
#include "input/input.h"

class Game {
public:
    Game();

    Renderer renderer;
    Input input;

    // Input instance
    // Entity list <- Renderer renders from this
    // Camera list and switching and adding

    virtual ~Game();
};
