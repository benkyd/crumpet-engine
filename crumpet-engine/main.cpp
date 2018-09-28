#include "game.h"

#undef main

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main(int argc, char** argv) {
	Game game("Crumpet engine", SCREEN_WIDTH, SCREEN_HEIGHT, 0, 60);

	Entity mario("mario", game.SDLRenderer, EntityType::MODE_TEXTURE);
	mario.LoadTexture("/resources/mario.png");

	Entity box("box", game.SDLRenderer, EntityType::MODE_POLYGON);


	while (!game.IsDisplayClosed()) {
		game.PollEvents();
		
		game.RenderClear();
		game.RenderEntity(&mario);
		game.RenderUpdate();
	}

	return 0;
}
