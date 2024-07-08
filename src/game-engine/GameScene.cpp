#include<game-engine/main.h>

GameScene::GameScene(){}
void GameScene::addObjectToScene(GameObject* obj){ this->activeObjects.push_back(obj); }
void GameScene::clearScene(){ 
	for (int i = 0; i < this->activeObjects.size(); i++) {
		if (this->activeObjects[i]->p.body->GetType() != b2_staticBody) {
			this->activeObjects[i]->Destroy();
			activeObjects.erase(activeObjects.begin() + i);
		};
	}

}

