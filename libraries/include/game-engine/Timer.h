#pragma once
#include<SDL2/SDL.h>
#include<game-engine/main.h>

class Timer{
    public:
        Timer();
        void startTimer();
        float endTimer();
        float time_now;
        float time_end;

        float currentTime;
        float previousTime;
        float tick_time;
        bool open = true;
};
