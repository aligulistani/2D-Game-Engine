#include <game-engine/display.h>

Display::Display(){
    //DEFAULT WINDOW SETTINGS
    //These will apply if not given any parameters when called
    
};
Display::Display(const char* title, int w, int h,SDL_Renderer* render,SDL_Window* winder){
    this->title = title;
    this->width = w;
    this->height = h;
    this->renderer = renderer;
    this->window = window;
}
Display::Display(const char* title, int w, int h){
    this->title = title;
    this->width = w;
    this->height = h;
    this->window = SDL_CreateWindow(this->title,50,50,w,h,SDL_WINDOW_RESIZABLE);
    this->renderer = SDL_CreateRenderer(this->window,-1,0);
}
void Display::update(){
    SDL_RenderClear(this->renderer);
}
void Display::renderObjects(){
    SDL_SetRenderDrawColor(this->renderer, 3, 255, 83, 255);
    // SDL_RenderFillRect(main_window.renderer,NULL);
    SDL_SetRenderDrawColor(this->renderer, 3, 255, 255, 255);
    SDL_RenderPresent(this->renderer);
}

void Display::cleanup(){
	SDL_DestroyWindow(this->window);
	SDL_DestroyRenderer(this->renderer);
	SDL_Quit();
}

void Display::windowResize(int w, int h){
    this->width = w;
    this->height = h;
}
