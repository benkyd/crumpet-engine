#include <iostream>
#include <include.h>
#include "header.h"

#include "SDL2/SDL.h"

int main(int argc, char** argv) {
	XD().write("Epic");
	HelloWorld helloWorld;

	SDL_Window* window = NULL;
	SDL_Surface* surface = NULL;
	
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "INIT FAILED" << std::endl;
	}
	
	window = SDL_CreateWindow("crumpet-engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, NULL);
	SDL_Delay(1000);
	SDL_FreeSurface(surface);
	SDL_DestroyWindow(window);
	window = NULL;
	SDL_Quit();
}
