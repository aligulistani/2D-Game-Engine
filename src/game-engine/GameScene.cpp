#include<game-engine/main.h>

GameScene::GameScene(){}
void GameScene::addObjectToScene(Entity* obj){ this->activeObjects.push_back(obj); }
void GameScene::clearScene(){ 
	for (int i = 0; i < this->activeObjects.size(); i++) {
		this->activeObjects[i]->Destroy();
		activeObjects.erase(activeObjects.begin() + i);
	}

}

