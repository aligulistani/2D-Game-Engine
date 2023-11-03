#include<SDL2/SDL.h>
#include<game-engine/main.h>

GameObject::GameObject(){};
GameObject::GameObject(int x, int y){
    this->x = x;
    this->y = y;
};
GameObject::GameObject(int x, int y,int w,int h){
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->rect = SDL_Rect();
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
};