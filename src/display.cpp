// #include<game-engine/main.h>

// INCLUDES
#include<SDL2/SDL.h>
#include<game-engine/GameScene.h>
#include<game-engine/display.h>
#include<vector>


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
        // scene.activeObjects[i]->animation.dest.x = (int)&scene.activeObjects[i]->pos[0];
        // scene.activeObjects[i]->animation.dest.y = (int)&scene.activeObjects[i]->pos[1];
        // scene.activeObjects[i]->sprite.animation.animate();
        // scene.activeObjects[i]->sprite.animation.dest.x =  scene.activeObjects[i]->pos[0] - scene.activeObjects[i]->sprite.animation.source.w; // TEMP VALUES, NEED TO BE VARIABLES
        // scene.activeObjects[i]->sprite.animation.dest.y = scene.activeObjects[i]->pos[1] - scene.activeObjects[i]->sprite.animation.source.h;
        // scene.activeObjects[i]->sprite.animation.dest.w = (scene.activeObjects[i]->sprite.texture.w/scene.activeObjects[i]->sprite.animation.frame_count) * 2;
        // scene.activeObjects[i]->sprite.animation.dest.h = scene.activeObjects[i]->sprite.texture.h * 2;
        // scene.activeObjects[i]->sprite.animation.animation_current_frame = 1;

        // Rendering Animations
        // SDL_RenderCopyEx(this->renderer,scene.activeObjects[i]->sprite.texture._rawImage,&(scene.activeObjects[i]->sprite.animation.source),&(scene.activeObjects[i]->sprite.animation.dest),0,NULL,SDL_FLIP_NONE);
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
