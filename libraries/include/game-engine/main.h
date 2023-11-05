#pragma once
#include<SDL2/SDL.h>
#include<vector>
#include<game-engine/display.h>
#include<game-engine/eventHandler.h>
#include<game-engine/GameObject.h>
#include<game-engine/GameScene.h>
#include<game-engine/Texture.h>
#include<game-engine/Timer.h>


class GameEngine{
public:
    GameEngine();
    static void initialize();
    static void set_main_game_loop(void (*game_loop_func)(), int fps_cap);
};