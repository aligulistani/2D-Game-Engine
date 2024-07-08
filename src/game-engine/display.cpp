#include<game-engine/main.h>


Display::Display(){};
Display::Display(const char* title, int w, int h){
    this->title = title;
    this->width = w;
    this->height = h;
    this->window = SDL_CreateWindow(this->title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);
}
void Display::cleanup(){
	SDL_DestroyWindow(this->window);
	SDL_DestroyRenderer(GameEngine::renderer.get());
	SDL_Quit();
}
void Display::windowResize(int w, int h){
    this->width = w;
    this->height = h;
}
