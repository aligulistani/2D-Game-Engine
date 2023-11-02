#include<SDL2/SDL.h>
#include<iostream>
#include<string>
#include<game-engine/main.h>


int WINDOW_WIDTH = 1280;
int WINDOW_HEIGHT = 720;
int max_fps = 120;
const char* window_title = "Game-Engine Test";

Display main_window;
GameObject rectangle = GameObject(50,50);
SDL_Rect rect_sdl;



void clean_up();

int main(int argc,char **argv){
	GameEngine::initialize();
	main_window = Display(window_title,WINDOW_WIDTH,WINDOW_HEIGHT);

	rect_sdl.x = 50;
	rect_sdl.y = 50;
	rect_sdl.w = 50;
	rect_sdl.h = 50;
	// GAME LOOP
	while (true){
		SDL_Event event;
		if (SDL_PollEvent(&event)){
			if (event.type == SDL_QUIT){break;}
		}
		main_window.update();
		SDL_RenderPresent(main_window.renderer);
	}
	clean_up();
	return 0;		
}
void clean_up(){
	main_window.cleanup();
}