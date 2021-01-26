#include <complex>
#include <iostream>
#include "fractal.h"


Fractal::Fractal(int w, int h) :
_w(w), _h(h), _cx(w/2), _cy(h/2)
{
    this->_world = new float[w*h];
}

Fractal::~Fractal()
{
    delete[] _world;
}

float Fractal::get_pixel(float real, float imag)
{
    float color = 255;
    std::complex<float> vector(0.0f, 0.0f);
    std::complex<float> start(real, imag);

    for (int i=0; i<_iterations; i++) {
        vector = vector * vector + start;
        // std::cout << i << "\n";
        if (abs(std::real(vector)) + abs(std::imag(vector)) > 4)
        {
            break;
        }
        color -= 255/_iterations;
    }
    return color;
}

void Fractal::calculate_fractal()
{
    float color;

    for (int iY=0; iY<_h; iY++) {
        for (int iX=0; iX<_w; iX++) {
            // (iX-x)*distance+x
           _world[iY*_w+iX] = get_pixel((iX-_x)*_zoom+_x-_cx*_zoom, (iY-_y)*_zoom+_y-_cy*_zoom); 
        }
    }
}

void Fractal::pollEvents(SDL_Event &event)
{
    switch (event.type)
    {
    case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
        case SDLK_w:
            _y += _zoom;
            break;

        case SDLK_a:
            _x -= _zoom;
            break;

        case SDLK_s:
            _y -= _zoom;
            break;

        case SDLK_d:
            _x += _zoom;
            break;

        case SDLK_q:
            _zoom = _zoom*1.1;
            break;

        case SDLK_e:
            _zoom = _zoom*0.9;
            break;
        }
        break;
    }
}