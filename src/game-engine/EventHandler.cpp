
#include<game-engine/main.h>

EventHandler::EventHandler(){}
bool EventHandler::pollEvents(){
    //This Functions needs to be called everyt tick to poll events
    this->keystates = SDL_GetKeyboardState(NULL);
    if(SDL_PollEvent(&current_event) != 0){
        return true;
    }
    return false;
}
bool EventHandler::keyReleased(Uint8 scancode){
    if(this->current_event.type == SDL_KEYUP && (this->current_event.key.keysym.scancode == scancode)){
        return true;
    }
    return false;
}
bool EventHandler::keyPressed(Uint8 scancode) {
    if (this->keystates[scancode]) {
        return true;
    }
    return false;
}

bool EventHandler::MousePressed(Uint8 index) {
    if (this->current_event.button.button == index) {
        return true;
    }
    else {
        return false;
    }
}