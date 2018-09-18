#include <iostream>
#include "game.h"

#undef main

int main() {
	Game game(600, 600, "BEsT GamE", 60);
	glClearColor(0.1f, 0.45f, 0.9f, 1.0f);

	while (!game.display.IsClosed()) {
		glClear(GL_COLOR_BUFFER_BIT);

		SDL_Event event;
		while (SDL_PollEvent(&event) != 0) {}
		game.Update();
	}

	game.~Game();
	return 0;
}
