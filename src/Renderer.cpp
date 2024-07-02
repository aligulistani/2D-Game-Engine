#include <iostream>
#include<game-engine/main.h>

/*
 * Features:
 *      - Must be able to handle any time of gameobject for rendering
 *
 *
 *
 */



Renderer::Renderer() {
    this->scene = new GameScene();
};

void Renderer::draw(){
    ImGui::Render();
    SDL_SetRenderDrawColor(renderer, 84, 92, 94, 255); // HARD CODED VALUE: Background Color is Defined Here
    SDL_RenderClear(renderer);
    this->renderGameSceneObjects();
    ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), renderer);
    SDL_RenderPresent(renderer);
}

SDL_Renderer* Renderer::get() {
    return this->renderer;
}
void Renderer::update(GameScene* s){
    this->scene = s;
}
void Renderer::renderGameSceneObjects(){
    for(int i=0;i<this->scene->activeObjects.size();i++){
        this->scene->activeObjects[i]->sprite.animation.animate();
        SDL_RenderCopyEx(this->renderer,this->scene->activeObjects[i]->sprite.texture._rawImage,
            &(this->scene->activeObjects[i]->sprite.animation.source),
            &(this->scene->activeObjects[i]->sprite.animation.dest),
            0,NULL,SDL_FLIP_NONE);

    }
}