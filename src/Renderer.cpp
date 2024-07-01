#include <iostream>
#include<game-engine/Renderer.h>

/*
 * Features:
 *      - Must be able to handle any time of gameobject for rendering
 *
 *
 *
 */



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
        if(this->current_scene->activeObjects[i]->type == 1) {
            SDL_SetRenderDrawColor(this->renderer, 108, 66, 245, SDL_ALPHA_OPAQUE);
            SDL_RenderFillRectF(this->renderer, &this->current_scene->activeObjects[i]->rect);
        }else {
            this->current_scene->activeObjects[i]->sprite.animation.animate();
            // this->current_scene->activeObjects[i]->sprite.animation.dest.x =  this->current_scene->activeObjects[i]->pos[0] - this->current_scene->activeObjects[i]->sprite.animation.source.w; // TEMP VALUES, NEED TO BE VARIABLES
            // this->current_scene->activeObjects[i]->sprite.animation.dest.y = this->current_scene->activeObjects[i]->pos[1] - this->current_scene->activeObjects[i]->sprite.animation.source.h;
            // this->current_scene->activeObjects[i]->sprite.animation.dest.w = (this->current_scene->activeObjects[i]->sprite.texture.w/this->current_scene->activeObjects[i]->sprite.animation.frame_count) * 2;
            // this->current_scene->activeObjects[i]->sprite.animation.dest.h = this->current_scene->activeObjects[i]->sprite.texture.h * 2;
            SDL_RenderCopyEx(this->renderer,this->current_scene->activeObjects[i]->sprite.texture._rawImage,
                &(this->current_scene->activeObjects[i]->sprite.animation.source),
                &(this->current_scene->activeObjects[i]->sprite.animation.dest),
                0,NULL,SDL_FLIP_NONE);
        }
    }
}