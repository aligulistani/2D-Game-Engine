#include<SDL2/SDL.h>
#include<game-engine/main.h>
#include<game-engine/GameScene.h>
#include<iostream>

GameScene::GameScene(){}
void GameScene::addObjectToScene(GameObject* obj){
        this->activeObjects.push_back(obj);
}
void GameScene::clearScene(){
    this->activeObjects.clear();
}
// void GameScene::update(){
//     for(int i=0;i<this->activeObjects.size();i++){

//     }
// }