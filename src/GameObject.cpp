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
    this->rect = {this->x,this->y,this->w,this->h};
};

void GameObject::changeX(int x){
    this->rect.x = x;
}
void GameObject::changeY(int y){
    this->rect.y = y;
}