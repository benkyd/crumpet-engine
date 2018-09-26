#pragma once

#include <string>

#include "display.h"

class Game {
public:
	Game(std::string title, int width, int height);
	bool IsDisplayClosed();
	virtual ~Game();
private:
	Display m_display;
};
