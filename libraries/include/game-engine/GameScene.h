#pragma once
#include "GameObject.h"

// Container Class
class GameScene{
    public:
        GameScene();
        std::vector<GameObject*> activeObjects;

        void addObjectToScene(GameObject* obj);
        void clearScene();
};
