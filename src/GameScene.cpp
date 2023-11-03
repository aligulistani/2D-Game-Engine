#include<SDL2/SDL.h>
#include<game-engine/main.h>
#include<game-engine/GameScene.h>
#include<iostream>

GameScene::GameScene(){}
void GameScene::addObjectToScene(GameObject obj){
        this->activeObjects.push_back(obj);

}