
#include<game-engine/main.h>

EventHandler::EventHandler(){}
bool EventHandler::pollEvents(){
    //This Functions needs to be called everyt tick to poll events
    if(SDL_PollEvent(&current_event) != 0){
        return true;
    }
    return false;
}
bool EventHandler::keyPressed(Uint8 scancode){
    if(this->current_event.key.keysym.scancode == scancode){
        return true;
    }else{
        return false;
    }
}