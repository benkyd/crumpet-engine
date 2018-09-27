#include "game.h"

Game::Game(std::string title, int width, int height)
		: m_display(title, width, height) {

	std::cout << "Engine initialized" << std::endl;
}

void Game::UpdateDisplay() {
	m_display.Update();
}

void Game::CloseDisplay() {
	m_display.Close();
}

bool Game::IsDisplayClosed() {
	return m_display.IsClosed();
}

Display Game::GetDisplay() {
	return m_display;
}

Game::~Game() {}
