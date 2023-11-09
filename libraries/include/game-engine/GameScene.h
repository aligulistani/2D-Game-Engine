#pragma once
#include<game-engine/GameObject.h>
#include<vector>
class GameScene{
    public:
        GameScene();
        std::vector<GameObject*> activeObjects;
        //std::vector<Entity* > activeEntities; // Make Entity Class
        void addObjectToScene(GameObject* obj);
        // void addArrayToScene(std::vector<GameObject> array);
        void update();
        void clearScene();
        std::vector<GameObject> checkCollisions();
        void handleCollisions(GameObject* obj_1,GameObject* obj_2);
};