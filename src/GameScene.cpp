#include<game-engine/main.h>

GameScene::GameScene(){}
void GameScene::addObjectToScene(GameObject* obj){ this->activeObjects.push_back(obj); }
void GameScene::clearScene(){ this->activeObjects.clear(); }

