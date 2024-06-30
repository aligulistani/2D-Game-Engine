
// #include<game-engine/main.h>
#include<SDL2/SDL.h>
#include<game-engine/Timer.h>
Timer::Timer(){};

void Timer::startTimer(){
    if(open){
        this->previousTime = currentTime - time_end;
        this->currentTime = SDL_GetTicks();    
    }
    // std::cout << previousTime << std::endl;
}

float Timer::endTimer(){
    this->time_end = SDL_GetTicks() - time_now;// time when clock started, in milliseconds
    this->previousTime = 0;
    this->currentTime = 0;
    this->tick_time = 0;
    open = false;
    return 0.0f;
}