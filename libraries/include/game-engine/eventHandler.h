#pragma once

class EventHandler{
    public:
        SDL_Event current_event;
        const Uint8* keystates;
        EventHandler();
        bool pollEvents(); // Must be called every tick!
        bool keyReleased(Uint8 scancode);
        bool keyPressed(Uint8 scancode);
        bool MousePressed(Uint8 index);
};