#include "game.h"

#undef main

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main(int argc, char** argv) {
	Game game("Crumpet engine", SCREEN_WIDTH, SCREEN_HEIGHT, 1, 1000 / 60);
	Timer timer;

	Sprite sans("sans", game.SDLRenderer, SpriteType::SPRITE_ANIMATED);
	sans.LoadSpriteTextures("/resources/sans-undertale-spritesheet.png");
	sans.UseSpriteSheet(SpriteState::STATE_RIGHT, 10, 10, 200, 200, 50, 4);
	sans.Spritestate = SpriteState::STATE_RIGHT;

	while (!game.IsDisplayClosed()) {
		// game.PollEvents();
		if (timer.GetTimeElapsed() >= game.TargetMsPerUpdate) { // Constant update rate, despite framerate
			// game logic

			const Uint8 *state = SDL_GetKeyboardState(NULL);
			// if (state[SDL_SCANCODE_A]) mario.Pos.x -= 10;

			while (SDL_PollEvent(&game.m_event) != 0) {
				if (game.m_event.type == SDL_QUIT)
					game.CloseDisplay();
			};
			
			sans.AnimateSprite();

			timer.Tick();
		}

		game.RenderClear();
		game.RenderSprite(&sans);
		game.RenderUpdate();
	}

	return 0;
}
