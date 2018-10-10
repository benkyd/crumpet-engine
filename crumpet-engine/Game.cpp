#include "game.h"

Game::Game(std::string title, int width, int height, int targetFramerate, int targetUpdaterate) {
	this->renderer = new Renderer(title, width, height, targetFramerate);

	this->TargetMsPerFrame = targetFramerate;
	this->TargetMsPerUpdate = targetUpdaterate;

	std::cout << "Engine initialized" << std::endl;
}

void Game::PollEvents() {
	while (SDL_PollEvent(&m_event) != 0)
		if (m_event.type == SDL_QUIT)
			this->renderer->CloseDisplay();
}

void Game::AddCamera(std::string name, Camera* camera) {
	Cameras[name] = camera;
}

void Game::UseCamera(std::string name) {
	renderer->ApplyCameraToScene(Cameras[name]);
}

Game::~Game() {
	
}
