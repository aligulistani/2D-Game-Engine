/*
Rendering Class 
    - Must be able to render multiple types of game objects at once
    - All entities/objects that are going to be rendered are going to be apart of the GameObjects class, whether it is iherited class or not
    - 

*/


#pragma once
#include<game-engine/GameScene.h>

class Renderer {
public:
    std::vector<GameObject*> activeObjects;
    SDL_Renderer* renderer;
    int fps_cap = -1;
    GameScene* current_scene;
    Renderer();
    Renderer(SDL_Window* w, int index, int flags, GameScene* scene);
    void cleanup();
    void update(GameScene* s);
    SDL_Renderer* get();
    void renderObjects();
    void clear();
private:
};