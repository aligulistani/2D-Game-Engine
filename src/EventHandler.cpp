#include<game-engine/main.h>
#include<SDL2/SDL.h>

EventHandler::EventHandler(){}
bool EventHandler::pollEvents(){
    //This Functions needs to be called everyt tick to poll Events!
    if(SDL_PollEvent(&current_event) != 0){
        return true;
    }
    return false;
}