#include <game-engine/main.h>
#include<game-engine/GameScene.h>

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
void Display::renderObjects(GameScene scene){
    SDL_SetRenderDrawColor(this->renderer,255, 255, 255, 255);
    for(int i=0;i<scene.activeObjects.size();i++){
        scene.activeObjects[i]->move({scene.activeObjects[i]->velocity[0],scene.activeObjects[i]->velocity[1]});
        SDL_RenderFillRectF(this->renderer,&scene.activeObjects[i]->rect);
    }
    SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
    // SDL_RenderCopyEx(this->renderer, e.getTexture()), &source, &dest, 0, NULL, NULL);
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
