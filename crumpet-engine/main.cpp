#include "game.h"

#undef main

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main(int argc, char** argv) {
	Game game("Crumpet engine", SCREEN_WIDTH, SCREEN_HEIGHT, 0, 60);

	

	while (!game.IsDisplayClosed()) {
		game.PollEvents();
		

		game.UpdateDisplay();
	}

	return 0;
}
