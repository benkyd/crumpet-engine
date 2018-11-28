#include "input.h"

Input::Input(Renderer* renderer) {
    m_renderer = renderer;
}

void Input::poll() {
    while (SDL_PollEvent(&m_event) != 0) {
        if (m_event.type == SDL_QUIT) {
            m_renderer->destroyWindow();
        }
    }
}

Input::~Input() {
    
}
