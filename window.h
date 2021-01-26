#pragma once

#include <string>
#include <SDL.h>
#include "fractal.h"


class Window
{
public:
    Window(int w, int h, std::string title);
    ~Window();
    inline bool IsOpen() { return _open; };
    void pollEvents(SDL_Event &event);
    void render(Fractal &fractal);
    // void movement();

private:
    std::string _title;
    int _w, _h;
    int _cx, _cy;
    float _color;
    bool _open;

    // float x = 0;
    // float y = 100;

    SDL_Window* _window = nullptr;
    SDL_Renderer* _renderer = nullptr;

    bool init();
};