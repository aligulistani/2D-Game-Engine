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
        Entity* e = this->scene->activeObjects[i];

        RenderData* r_data = e->getRenderingData();

        //if (P_e != nullptr) {
        //    //P_e->test_func();
        //}

        r_data->main_sprite.x -= GameEngine::main_camera.pos.x;
        r_data->main_sprite.y -= GameEngine::main_camera.pos.y;


        //c->Hitbox.x -= GameEngine::main_camera.pos.x;
        //c->Hitbox.y -= GameEngine::main_camera.pos.y;

        SDL_SetRenderDrawColor(GameEngine::renderer.get(), 48, 252, 3, 255);
        SDL_RenderDrawRectF(GameEngine::renderer.get(),&r_data->physics_hitbox);

        //SDL_SetRenderDrawColor(GameEngine::renderer.get(), 207, 10, 17, 255);
        //SDL_RenderDrawRectF(GameEngine::renderer.get(), &r_data->sprite_hitbox);


        SDL_RenderCopyExF(this->renderer, this->scene->activeObjects[i]->animator.c_anim->sprite.texture._rawImage,
            this->scene->activeObjects[i]->animator.getCurrentDrawFrame(),
            &r_data->main_sprite,
            0, NULL, c->animator.flip_state);
        //(c->r_b.GetRawBody()->GetAngle())* (180 / 3.14)
    }
}