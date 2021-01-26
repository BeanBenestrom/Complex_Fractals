#include <iostream>
#include "window.h"


Window::Window(int w, int h, std::string title) :
_w(w), _h(h), _title(title), _cx(w/2), _cy(h/2)
{
    _open = init();
}

Window::~Window()
{
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);  
    SDL_Quit();  
}

bool Window::init()
{
    if (SDL_Init(SDL_INIT_VIDEO)) {
        std::cerr << "Failed to initialize SDL VIDEO\n"; return false;
    }

    _window = SDL_CreateWindow(_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _w, _h, 0);

    if (_window == nullptr) {
        std::cerr << "Failed to create a window\n"; return false;
    }

    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

    if (_renderer == nullptr) {
        std::cerr << "Failed to create renderer\n"; return false;
    }

    return true;
}

void Window::pollEvents(SDL_Event &event)
{
    switch (event.type)
    {
    case SDL_QUIT:
        _open = false;
        break;
    
    default:
        break;
    }
}

// void Window::movement()
// {
//     x += 0.01;
// }

void Window::render(Fractal &fractal)
{
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 0);
    SDL_RenderClear(_renderer);

    for (int i=0; i<_h; i++) {
        for (int j=0; j<_w; j++) {
            _color = fractal._world[i*_w+j];
            SDL_SetRenderDrawColor(_renderer, _color, _color, _color, 255);
            SDL_RenderDrawPoint(_renderer, j, _cy*2-i);
        }
    }
    SDL_RenderPresent(_renderer);
}