#include "crumpet-engine/crumpet-engine.h"

int main(int argc, char** argv) {
	Game game;
	game.renderer.createWindow("Crumpet Engine", 600, 400, SCREEN_MODE_VSYNC);

	game.textureManager.registerTexture("./resources/mario.png", "mario");

	while (!game.renderer.isWindowClosed()) {
		game.renderer.clear();
		game.input.poll();
		SDL_RenderCopy(game.renderer.SDLRenderer, game.textureManager.getTexture("mario"), NULL, NULL);
		game.renderer.update();
	}
}
