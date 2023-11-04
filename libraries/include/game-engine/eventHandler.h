#pragma once
#include<SDL2/SDL.h>

class EventHandler{
    public:
        SDL_Event current_event;
        EventHandler();
        bool pollEvents(); // Must be called every tick!
};