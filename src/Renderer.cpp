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
    // this->renderer = SDL_CreateRenderer(GameEngine::window->window,-1,0);
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
    for (int i = 0; i < this->scene->activeObjects.size(); i++) {
        GameObject* c = this->scene->activeObjects[i];

        const SDL_FRect t_rect{
            c->p.body->GetPosition().x - c->p.hx,
            c->p.body->GetPosition().y - c->p.hy,
             c->p.hx * 2,
             c->p.hy * 2
        };

        

        SDL_RenderCopyExF(this->renderer, this->scene->activeObjects[i]->sprite.texture._rawImage,
            this->scene->activeObjects[i]->animator.getCurrentDrawFrame(),
            &t_rect,
            (c->p.body->GetAngle()) * (180 / 3.14), NULL, c->animator.c_anim.sprite.flip);
        //SDL_RenderCopyExF(this->renderer, this->scene->activeObjects[i]->sprite.texture._rawImage,
        //    &(this->scene->activeObjects[i]->sprite.animation.source),
        //    &t_rect,
        //    (c->p.body->GetAngle()) * (180 / 3.14), NULL, SDL_FLIP_NONE);
    }
}