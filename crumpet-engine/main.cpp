#include "game.h"

#undef main

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main(int argc, char** argv) {
	Game game("Crumpet engine", SCREEN_WIDTH, SCREEN_HEIGHT, 1, 1000 / 60); // 1000 / 60);
	Timer timer;

	Sprite sans("sans", game.SDLRenderer, SpriteType::SPRITE_ANIMATED);
	sans.LoadSpriteTextures("/resources/sans-undertale-spritesheet.png");
	sans.UseSpriteSheet(SpriteState::STATE_FRONT, 30, 9, 230, 300, 10, 4);
	sans.UseSpriteSheet(SpriteState::STATE_RIGHT, 30, 320, 170, 300, 10, 4);
	sans.UseSpriteSheet(SpriteState::STATE_LEFT, 40, 640, 170, 300, 10, 4);
	sans.Pos = Vec2(100, 100);

	Sprite explosion("explosion", game.SDLRenderer, SpriteType::SPRITE_ANIMATED);
	explosion.LoadSpriteTextures("/resources/explosion.png");
	explosion.UseSpriteSheet(SpriteState::STATE_DEFAULT, 1, 260, 65, 63, 0, 16);
	explosion.ResizeSpriteStateByFactor(SpriteState::STATE_DEFAULT, 4);

	while (!game.IsDisplayClosed()) {
		game.PollEvents();

		if (timer.GetTimeElapsed() >= game.TargetMsPerUpdate) { // Constant update rate, despite framerate

			const Uint8 *state = SDL_GetKeyboardState(NULL);
			if (state[SDL_SCANCODE_D]) sans.Spritestate = SpriteState::STATE_RIGHT;
			else if (state[SDL_SCANCODE_A]) sans.Spritestate = SpriteState::STATE_LEFT;
			else sans.Spritestate = SpriteState::STATE_FRONT;
			
			if (timer.ticks % 5 == 0) {
				sans.TickAninmation();
				explosion.TickAninmation();
			}

			timer.Tick();
		}

		game.RenderClear();
		game.RenderSprite(&sans);
		game.RenderSprite(&explosion);
		game.RenderUpdate();
	}

	return 0;
}

//if (state[SDL_SCANCODE_A]) mario.Pos.x -= 10;			
