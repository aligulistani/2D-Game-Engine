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
Display::Display(const char* title, int w, int h,SDL_Renderer* render){
    this->title = title;
    this->width = w;
    this->height = h;
    this->renderer = renderer;
}
Display::cleanup(){
	SDL_DestroyWindow(this->window);
	SDL_DestroyRenderer(this->renderer);
	SDL_Quit();
}
