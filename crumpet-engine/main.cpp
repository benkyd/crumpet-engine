#include <iostream>
#include <string>
#include <SDL.h>

#include "game.h"

#undef main

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main(int argc, char **argv) {

	Game game("Crumpet engine", SCREEN_WIDTH, SCREEN_HEIGHT);

	while (!game.IsDisplayClosed()) {
	
	}

	return 0;
}
