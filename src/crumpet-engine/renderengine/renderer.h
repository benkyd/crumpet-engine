#pragma once

#include <iostream>
#include <string>
#include <SDL2/SDL.h>

typedef enum {
    SCREEN_MODE_DEFAULT,
    SCREEN_MODE_VSYNC
} ScreenMode;

class Renderer {
public:
    Renderer();
    void createWindow(std::string title, int width, int height, ScreenMode mode);
    bool isWindowClosed();
    void destroyWindow();

    void clear();
    void update();

    SDL_Renderer* SDLRenderer;

    virtual ~Renderer();
private:
    SDL_Window* m_window;
    bool m_isWindowClosed;
};
