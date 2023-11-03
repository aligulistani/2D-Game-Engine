#pragma once
#include<game-engine/main.h>
#include<game-engine/GameObject.h>
#include<SDl2/SDL.h>
#include <iostream>
#include <vector>

class GameScene{
    public:
        GameScene();
        std::vector<GameObject> activeObjects;
        void addObjectToScene(GameObject obj);
};