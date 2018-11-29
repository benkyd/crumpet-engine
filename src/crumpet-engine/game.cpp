#include "game.h"

Game::Game()
    : input(&renderer) 
    , resourceManager(&renderer) 
    , textureManager(resourceManager.textureManager) 
    , entityManager(&resourceManager) {

}

Game::~Game() {

}
