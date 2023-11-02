#pragma once
#include<SDL2/SDL.h>

struct EventHandler{
public:
    SDL_Event event;
    void initHandler();
};