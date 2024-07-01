#pragma once
#include "GameObject.h"

class GameScene{
    public:
        GameScene();
        std::vector<GameObject*> activeObjects;

        void addObjectToScene(GameObject* obj);
        void update();
        void clearScene();
};
