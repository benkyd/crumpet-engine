#include "crumpet-engine/crumpet-engine.h"

int main(int argc, char** argv) {
	Game game;
	game.renderer.createWindow("Crumpet Engine", 600, 400, SCREEN_MODE_VSYNC);

	game.textureManager.registerTexture("./resources/mario.png", "mario");

	while (!game.renderer.isWindowClosed()) {
		game.renderer.clear();
		game.input.poll();
		Rect rectfrom(0, 0, 1000, 1000);
		Rect rectTo(-300, 0, 1000, 1000);
		SDL_RenderCopy(game.renderer.SDLRenderer, game.textureManager.getTexture("mario"), rectfrom.ToSDLRect(), rectTo.ToSDLRect());
		game.renderer.update();
	}
}
