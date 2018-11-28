#include "crumpet-engine/crumpet-engine.h"

int main(int argc, char** argv) {
	Game game;
	game.renderer.createWindow("Crumpet Engine", 600, 400, SCREEN_MODE_VSYNC);

	while (!game.renderer.isWindowClosed()) {
		game.renderer.clear();
		game.input.poll();
		game.renderer.update();
	}
}
