#pragma once
#include<game-engine/main.h>

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
        // SDL_RenderFillRectF(this->renderer,&scene.activeObjects[i]->rect);

        // scene.activeObjects[i]->animation.dest.x = (int)&scene.activeObjects[i]->pos[0];
        // scene.activeObjects[i]->animation.dest.y = (int)&scene.activeObjects[i]->pos[1];

        // Rendering Animations
        // SDL_RenderCopyEx(this->renderer,scene.activeObjects[i]->animation.image,scene.activeObjects[i]->animation.source,scene.activeObjects[i]->animation.dest,0,NULL,SDL_FLIP_NONE);
    }



    for(int i=0;i<1280;i++){
        SDL_RenderDrawPoint(this->renderer, i, 720-25);
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
