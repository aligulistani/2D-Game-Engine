
#include<game-engine/main.h>

GameObject::GameObject(){};
GameObject::GameObject(float x, float y){ this->pos = {x,y};};
GameObject::GameObject(float x, float y, Sprite t){
    this->pos = {x,y};
    this->sprite = t;
};

void GameObject::setPos(b2Vec2 pos){
    this->pos = pos;
}
