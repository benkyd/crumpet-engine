#include "game.h"

#undef main

#define SCREEN_WIDTH 1920 // 800
#define SCREEN_HEIGHT 1080 // 600

int main(int argc, char** argv) {
	Game game("Crumpet engine", SCREEN_WIDTH, SCREEN_HEIGHT, 1, 1000 / 60);
	Timer timer;

	Entity mario("mario", game.SDLRenderer);
	mario.LoadTexture("/resources/charicter.png");

	Sprite sans("sans", game.SDLRenderer, SpriteType::SPRITE_ANIMATED);
	sans.LoadSpriteTextures("/resources/sans-undertale-spritesheet.png");
	// sans.UseSpriteSheet

	int ground = 300;
	bool isOnGround = false;
	float vY = 0;
	float g = 9.81;

	while (!game.IsDisplayClosed()) {
		// game.PollEvents();
		if (timer.GetTimeElapsed() >= game.TargetMsPerUpdate) { // Constant update rate, despite framerate
			// game logic
			std::cout << "Is Mario on ground: ";
			std::cout << isOnGround << std::endl;
			std::cout << "Mario's velocity: ";
			std::cout << vY << std::endl;

			if (!isOnGround) {
				vY += g;
				mario.Pos.y += vY;
				if (mario.Pos.y >= ground) {
					isOnGround = true;
					mario.Pos.y = ground;
				}
			}

			const Uint8 *state = SDL_GetKeyboardState(NULL);

			if (state[SDL_SCANCODE_A]) mario.Pos.x -= 10;
			if (state[SDL_SCANCODE_D]) mario.Pos.x += 10;

			while (SDL_PollEvent(&game.m_event) != 0) {
				if (game.m_event.type == SDL_QUIT)
					game.CloseDisplay();
				
				if (game.m_event.key.keysym.sym == SDLK_SPACE) {
					if (isOnGround) {
						isOnGround = false;
						vY = -100;
					}
				}
			};

			timer.Tick();
		}

		game.RenderClear();
		game.RenderEntity(&dave);
		game.RenderEntity(&mario);
		game.RenderUpdate();
	}

	return 0;
}
