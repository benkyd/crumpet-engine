#include "game.h"

Game::Game(std::string title, int width, int height)
	: m_display(title, width, height) {

	std::cout << "Engine initialized" << std::endl;
}

bool Game::IsDisplayClosed() {
	return m_display.IsClosed();
}

Game::~Game() {
	m_display.~Display();
}
