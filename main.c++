#include <SDL.h>
#include <iostream>
#include "window.h"
#include "fractal.h"

#define LOG(x) std::cout << x << std::endl


void pollEvents(Window &window, Fractal &fractal)
{
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
        window.pollEvents(event);
        fractal.pollEvents(event);
    }
}


int main(int argv, char* noob[])
{
    Window window(300, 300, "Complex Fractals");
    Fractal fractal(300, 300);

    while (window.IsOpen()) {
        pollEvents(window, fractal);
        fractal.calculate_fractal();
        // LOG(fractal._world[150*300+150]);
        window.render(fractal);
        // window.movement();
    }

    return 0;
}