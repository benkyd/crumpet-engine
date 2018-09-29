#include "game.h"

#undef main

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main(int argc, char** argv) {
	Game game("Crumpet engine", SCREEN_WIDTH, SCREEN_HEIGHT, 0, 60);

	Entity mario("mario", game.SDLRenderer);
	mario.LoadTexture("/resources/mario.png");

	Entity box("box", game.SDLRenderer, PolyDrawType::DRAW_FILLED_RECT);
	box.SetDrawColour(Vec4(0xFF, 0x00, 0x00, 0xFF));
	box.SetRect(Vec2(SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4), Vec2(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2));

	Entity outlineBox("bigger green box", game.SDLRenderer, PolyDrawType::DRAW_OUTLINE_RECT);
	outlineBox.SetDrawColour(Vec4(0x00, 0xFF, 0x00, 0xFF));
	outlineBox.SetRect(Vec2(SCREEN_WIDTH / 6, SCREEN_HEIGHT / 6), Vec2(SCREEN_WIDTH * 2 / 3, SCREEN_HEIGHT * 2 / 3));

	while (!game.IsDisplayClosed()) {
		game.PollEvents();
		
		game.RenderClear();
		
		game.RenderEntity(&mario);

		game.RenderEntity(&box);
		game.RenderEntity(&outlineBox);

		game.RenderUpdate();
	}

	return 0;
}
