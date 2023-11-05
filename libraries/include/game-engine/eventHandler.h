#pragma once
#include<game-engine/main.h>

class EventHandler{
    public:
        SDL_Event current_event;
        EventHandler();
        bool pollEvents(); // Must be called every tick!
};