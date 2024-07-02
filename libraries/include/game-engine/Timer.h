#pragma once

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
