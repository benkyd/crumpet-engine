#pragma once

#include <string>
#include "display.h"

class Game {
public:
	Game(std::string title, int width, int height);

	void UpdateDisplay();
	void CloseDisplay();
	bool IsDisplayClosed();

	Display GetDisplay();

	virtual ~Game();
private:
	Display m_display;
};
