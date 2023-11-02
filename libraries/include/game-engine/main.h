#pragma once
#include<SDL2/SDL.h>
#include<game-engine/display.h>
#include<game-engine/eventHandler.h>
#include<game-engine/GameObject.h>

class GameEngine{
public:
    GameEngine();
    static void initialize();
};