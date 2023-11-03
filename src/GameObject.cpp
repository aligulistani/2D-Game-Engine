#include<SDL2/SDL.h>
#include<game-engine/main.h>

GameObject::GameObject(int x, int y){
    this->x = x;
    this->y = y;
};
GameObject::GameObject(int x, int y,int w,int h, SDL_Rect temp_rect){
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->rect = SDL_Rect();
};