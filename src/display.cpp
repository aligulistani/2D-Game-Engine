#include<game-engine/main.h>


Display::Display(){
    //DEFAULT WINDOW SETTINGS
    //These will apply if not given any parameters when called
};
Display::Display(const char* title, int w, int h,Renderer renderer,SDL_Window* window){
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
    this->game_scene = GameScene();
    this->renderer = Renderer(this->window,-1,0, &this->game_scene);
}
void Display::update(){
    SDL_RenderClear(this->renderer.get());
}
void Display::cleanup(){
	SDL_DestroyWindow(this->window);
	SDL_DestroyRenderer(this->renderer.get());
	SDL_Quit();
}
void Display::windowResize(int w, int h){
    this->width = w;
    this->height = h;
}
