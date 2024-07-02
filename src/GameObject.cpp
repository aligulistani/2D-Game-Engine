
// #include<game-engine/main.h>
#include<SDL2/SDL.h>
#include<game-engine/GameObject.h>
// #include<game-engine/Animation.h>
#include<vector>
#include <Box2D/b2_fixture.h>
GameObject::GameObject(){};
GameObject::GameObject(float x, float y){ this->pos = {x,y};};
GameObject::GameObject(float x, float y, Sprite t){
    this->pos = {x,y};
    this->sprite = t;
};

void GameObject::setPos(b2Vec2 pos){
    this->pos = pos;
}
