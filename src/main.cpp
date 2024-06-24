
#include<game-engine/main.h>

#include "imgui.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"

Display* window;
GameEngine::GameEngine(){};
void GameEngine::initialize(Display* w){
    //Initilialize SDL Festures
    window = w;
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        std::cout<<"SDL Succesfully Initialized!"<<std::endl;
    }else{
        std::cout<<"SDL failed to Initialize!"<<std::endl;
    }

    // Initilize Handlers
}

float previous_tick_t = 0;
float current_tick_t = 0;
float tick_time;

void GameEngine::set_main_game_loop(void (*game_loop_func)(), int fps_cap, EventHandler* handler){
    bool open = 1;

    //Start a game loop
    while(open){

        handler->pollEvents();
        ImGui_ImplSDL2_ProcessEvent(&handler->current_event); // Forward your event to backend
        if(handler->current_event.type == SDL_QUIT){
            break;
        }
        previous_tick_t = current_tick_t;
        current_tick_t = SDL_GetTicks();
        tick_time = current_tick_t - previous_tick_t;

        window->renderer.update(&window->game_scene);
        window->game_scene.clearScene();
        game_loop_func();

        //window->update();
       // window->renderObjects(window->game_scene);
        //window->game_scene.clearScene();

    }
    ImGui_ImplSDLRenderer2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
    window->cleanup();

}