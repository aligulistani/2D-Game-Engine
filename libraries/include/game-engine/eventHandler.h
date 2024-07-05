#pragma once

class EventHandler{
    public:
        SDL_Event current_event;
        EventHandler();
        bool pollEvents(); // Must be called every tick!
        bool keyPressed(Uint8 scancode);
        bool MousePressed(Uint8 index);
};