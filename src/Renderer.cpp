#include <iostream>
#include<game-engine/Renderer.h>

Renderer::Renderer() = default;

Renderer::Renderer(SDL_Window* w, int index, int flags, GameScene* scene) {
    this->renderer = SDL_CreateRenderer(w,index,flags);
    this->current_scene = scene;
}

SDL_Renderer* Renderer::get() {
    return this->renderer;
}
void Renderer::update(GameScene* s){
    this->current_scene = s;
}
void Renderer::renderObjects(){
    for(int i=0;i<this->current_scene->activeObjects.size();i++){
        this->current_scene->activeObjects[i]->sprite.animation.animate();

        SDL_RenderCopyEx(this->renderer,this->current_scene->activeObjects[i]->sprite.texture._rawImage,
            &(this->current_scene->activeObjects[i]->sprite.animation.source),
            &(this->current_scene->activeObjects[i]->sprite.animation.dest),
            0,NULL,SDL_FLIP_NONE);
    }

}