#include "game.h"

#undef main

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main(int argc, char** argv) {
	Game game("Crumpet engine", SCREEN_WIDTH, SCREEN_HEIGHT);

	SDL_Event e;
	while (!game.IsDisplayClosed()) {

		while (SDL_PollEvent(&e) != 0)
			if (e.type == SDL_QUIT)
				game.CloseDisplay();

		game.UpdateDisplay();
	}

	return 0;
}
