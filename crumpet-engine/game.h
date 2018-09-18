#pragma once

#include <string>

#include "display.h"

enum class GameState {
	MENU,
	GAME_OVER,
	IN_GAME,
	QUIT
};

class Game {
public:
	Game(unsigned int width, unsigned int height, std::string name, unsigned int updateRate);
	void Update();
	
	GameState State;
	Display display;
	virtual ~Game();
private:
	bool _update;
	bool _running = false;
};

