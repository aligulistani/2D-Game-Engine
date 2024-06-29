#pragma once

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>

#include<game-engine/GameScene.h>
#include<game-engine/display.h>
#include<game-engine/eventHandler.h>
#include<game-engine/Texture.h>
#include<game-engine/Timer.h>
#include<game-engine/Animation.h>
#include<game-engine/GameObject.h>
#include<game-engine/Sprite.h>
#include<game-engine/Renderer.h>

#include<vector>
#include<iostream>
#include<string>


class GameObject;
class GameScene;
class EventHandler;
class Display;
class Animation;
class Texture;
class Sprite;
class Timer;
class Renderer;


class GameEngine{
public:
    GameEngine();
    static void initialize(Display* w);
    static void set_main_game_loop(void (*game_loop_func)(), int fps_cap, EventHandler* handler);
};