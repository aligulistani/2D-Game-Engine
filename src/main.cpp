#include<game-engine/main.h>
#include<SDL2/SDL.h>

GameEngine::GameEngine(){};
void GameEngine::initialize(){
    SDL_Init(SDL_INIT_EVERYTHING);
}