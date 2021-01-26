#pragma once

#include <SDL.h>

class Fractal
{
public:
    float* _world;

    Fractal(int w, int h);
    ~Fractal();
    void calculate_fractal();
    void pollEvents(SDL_Event &event);

private:
    float _x = 0;
    float _y = 0;
    int _w, _h;
    int _cx, _cy;

    int _iterations = 30;
    float _zoom = 0.01;

    float get_pixel(float real, float imag);
};
