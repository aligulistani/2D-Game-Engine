#pragma once
#include<game-engine/GameObject.h>
#include<vector>
class GameScene{
    public:
        GameScene();
        std::vector<GameObject*> activeObjects;
        std::vector<GameObject> array;
        void addObjectToScene(GameObject* obj);
        void addArrayToScene(std::vector<GameObject> array);
        void update();
        void clearScene();
};