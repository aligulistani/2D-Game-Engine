#pragma once

#include "display.h"
#include "eventHandler.h"

class GameEngine{
    public:
        GameEngine();
        static void initialize(Display* w);
        static void start_main_game_loop(void (*game_loop_func)(), int fps_cap, EventHandler* handler);
        static Renderer* r;
        void init();
};
