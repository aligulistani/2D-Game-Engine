#pragma once

#include "display.h"
#include "eventHandler.h"
#include "Renderer.h"
#include "Camera.h"
class GameEngine{
    public:
        GameEngine();
        static void initialize(Display* w);
        static void start_main_game_loop(void (*game_loop_func)(), int fps_cap);
        static void Shutdown();
        static Renderer renderer;
        static Display* window;
        static EventHandler handler;
        static PhysicsWorld main_physics_world;
        static Camera main_camera;
};
