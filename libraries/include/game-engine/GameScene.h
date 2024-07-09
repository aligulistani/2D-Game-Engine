#pragma once
#include "GameObject.h"

// Container Class
class GameScene{
    public:
        GameScene();
        std::vector<Entity*> activeObjects;

        void addObjectToScene(Entity* obj);
        void clearScene();
};
