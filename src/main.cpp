#include "crumpet-engine/crumpet-engine.h"

int main(int argc, char** argv) {
	Game game;
	game.renderer.createWindow("Crumpet Engine", 600, 400, SCREEN_MODE_VSYNC);

	SDL_Texture* texture;
	SDL_Surface* loadSurface = IMG_Load("./resources/mario.png");
	if (loadSurface == NULL) {
		std::cout << "ERROR LOADING SURFACE " << SDL_GetError() << std::endl;
	}
	texture = SDL_CreateTextureFromSurface(game.renderer.SDLRenderer, loadSurface);
	if (texture == NULL) {
		std::cout << "ERROR LOADING TEXTURE " << SDL_GetError() << std::endl;
	}
	SDL_FreeSurface(loadSurface);

	while (!game.renderer.isWindowClosed()) {
		game.renderer.clear();
		game.input.poll();
		SDL_RenderCopy(game.renderer.SDLRenderer, texture, NULL, NULL);
		game.renderer.update();
	}
}
