#include "crumpet-engine/crumpet-engine.h"
#include "crumpet-engine/rect.h"

#include <logger.h>

int main() {
	Game game;
	game.renderer.createWindow("Crumpet Engine", 600, 400, SCREEN_MODE_VSYNC);

	game.textureManager.registerTexture("./resources/eldritch-ts.png", "Eldritch");

	while (!game.renderer.isWindowClosed()) {
		game.renderer.clear();
		game.input.poll();
		Rect rectfrom(0, 0, 100, 100);
		Rect rectTo(0, 0, 400, 400);
		SDL_RenderCopy(	game.renderer.SDLRenderer, 
						game.textureManager.getSDLTexture("Eldritch"), 
						rectfrom.ToSDLRect(), 
						rectTo.ToSDLRect());
		game.renderer.update();
	}
}
