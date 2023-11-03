#pragma once
#include<SDL2/SDL.h>
#include<game-engine/display.h>
#include<game-engine/eventHandler.h>
#include<game-engine/GameObject.h>
#include<game-engine/GameScene.h>

class GameEngine{
public:
    GameEngine();
    static void initialize();
};