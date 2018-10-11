#include "crumpet-engine.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main(int argc, char** argv) {
	Game game("Crumpet engine", SCREEN_WIDTH, SCREEN_HEIGHT, 0, 1000 / 60); // 1000 / 60);
	Camera camera(SCREEN_WIDTH, SCREEN_HEIGHT);
	game.AddCamera("free", &camera);
	game.UseCamera("free");
	Timer timer;
	
	Sprite explosion("explosion", game.renderer ,SpriteType::SPRITE_ANIMATED);
	explosion.LoadSpriteTextures("/resources/explosion.png");
	explosion.UseSpriteSheet(SpriteState::STATE_DEFAULT, 1, 260, 64, 63, 0, 16);
	explosion.ResizeSpriteStateByFactor(SpriteState::STATE_DEFAULT, 4);

	Sprite woman("woman", game.renderer, SpriteType::SPRITE_ANIMATED);
	woman.LoadSpriteTextures("/resources/woman-spritesheet.png");
	woman.UseSpriteSheet(SpriteState::STATE_DEFAULT, 15, 1, 45, 105, 35, 14);
	woman.ResizeSpriteStateByFactor(SpriteState::STATE_DEFAULT, 4);
	woman.UseSpriteSheet(SpriteState::STATE_STANDING, 19, 109, 45, 105, 35, 2);
	woman.ResizeSpriteStateByFactor(SpriteState::STATE_STANDING, 4);
	woman.UseSpriteSheet(SpriteState::STATE_ACCELERATING, 19, 214, 74, 105, 1, 5);
	woman.ResizeSpriteStateByFactor(SpriteState::STATE_ACCELERATING, 4);
	woman.UseSpriteSheet(SpriteState::STATE_RUNNING, 0, 321, 77, 105, 3, 10);
	woman.ResizeSpriteStateByFactor(SpriteState::STATE_RUNNING, 4);


	woman.SetSpriteState(SpriteState::STATE_RUNNING);

	int i = 0;
	int runningDirection = 0; // 0 = standing, 1 = right, 2 = left
	while (!game.renderer->IsDisplayClosed()) {
		game.PollEvents();

		if (timer.GetTimeElapsed() >= game.TargetMsPerUpdate) { // Constant update rate, despite framerate
			const Uint8 *state = SDL_GetKeyboardState(NULL);

			if (state[SDL_SCANCODE_UP]) {
				camera.TranslateViewY(-10);
				std::cout << camera.GetRect().ToString() << std::endl;
			} 
			if (state[SDL_SCANCODE_RIGHT]) {
				camera.TranslateViewX(10);
				std::cout << camera.GetRect().ToString() << std::endl;
			}
			if (state[SDL_SCANCODE_DOWN]) {
				camera.TranslateViewY(10);
				std::cout << camera.GetRect().ToString() << std::endl;
			}
			if (state[SDL_SCANCODE_LEFT]) {
				camera.TranslateViewX(-10);
				std::cout << camera.GetRect().ToString() << std::endl;
			}

			if (timer.ticks % 5 == 0) {
				// explosion.TickAninmation();

				i++;
				// Slower animation speed for standing than everything else
				if (woman.Spritestate == SpriteState::STATE_STANDING) {
					if (timer.ticks % 60 == 0) {
						woman.TickAninmation();
					}
				} else {
					woman.TickAninmation(); 
				}
				// After inital loading sprite, switches to silouette
				if (i > 14 && woman.Spritestate == SpriteState::STATE_DEFAULT) {
					woman.SetSpriteState(SpriteState::STATE_STANDING);
					i = 0;
				}
			}

			timer.Tick();
		}

		game.renderer->RenderClear();

		// explosion.Render();
		woman.Render();

		game.renderer->RenderUpdate();
	}

	return 0;
}

//if (state[SDL_SCANCODE_A]) mario.Pos.x -= 10;			
