#include "game.h"

#undef main

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main(int argc, char** argv) {
	Game game("Crumpet engine", SCREEN_WIDTH, SCREEN_HEIGHT, 0, 1000 / 60);
	Timer timer;

	Entity mario("mario", game.SDLRenderer);
	mario.LoadTexture("/resources/mario.png");

	Sprite sans("sans", game.SDLRenderer, SpriteType::SPRITE_ANIMATED);
	

	while (!game.IsDisplayClosed()) {
		game.PollEvents();

		if (timer.GetTimeElapsed() >= game.TargetMsPerUpdate) {
			std::cout << timer.GetTimeElapsed() << std::endl;

			// game logic

			timer.Tick();
		}

		game.RenderClear();
		game.RenderEntity(&mario);
		game.RenderUpdate();
	}

	return 0;
}
