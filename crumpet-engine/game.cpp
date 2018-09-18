#include "game.h"

Game::Game(unsigned int width, unsigned int height, std::string name, unsigned int updateRate) {

	this->display = Display(width, height, name);
	this->_update = updateRate;

	glClearColor(0.1f, 0.45f, 0.9f, 1.0f);


	State = GameState::MENU;
	_running = true;
}

void Game::Update() {
	display.Update();
}

Game::~Game() {
	
	
	display.~Display();
	State = GameState::QUIT;
	_running = false;
}
