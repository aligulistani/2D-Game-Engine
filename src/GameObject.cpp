#include<SDL2/SDL.h>
#include<game-engine/main.h>

GameObject::GameObject(int x, int y){
    this->x = x;
    this->y = y;
};
GameObject::GameObject(int x, int y,SDL_Rect temp_rect){
    this->x = x;
    this->y = y;
    // this->rect = SDL_Rect();
};