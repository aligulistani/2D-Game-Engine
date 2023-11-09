
#include<game-engine/main.h>

GameEngine::GameEngine(){};
void GameEngine::initialize(){
    //Initilialize SDL Festures
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        std::cout<<"SDL Succesfully Initialized!"<<std::endl;
    }else{
        std::cout<<"SDL failed to Initialize!"<<std::endl;
    }

    // Initilize Handlers
}
void GameEngine::set_main_game_loop(void (*game_loop_func)(), int fps_cap, EventHandler* handler){
    //Start a game loop
    bool open = 1;
    // EventHandler handler;

    while(open){
        // std::cout << handler.current_event.type << std::endl;

        handler->pollEvents();
        if(handler->current_event.type == SDL_QUIT){
            break;
        }

        game_loop_func();
    }
}