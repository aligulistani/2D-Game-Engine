#include<SDL2/SDL.h>

#include<iostream>
#include<string>
#include<game-engine/display.h>


int WINDOW_WIDTH = 0;
int WINDOW_HEIGHT = 0;
int max_fps = 0;
char* window_title = NULL;

float delta_time;
Display main_window;
SDL_Renderer* renderer;

void clean_up();

<<<<<<< HEAD

int main(int argc,char **argv){
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Event event;
	SDL_PollEvent(&event);

	// main_window = Display("Game-Engine Test", 1280, 720, );
	// renderer = SDL_CreateRenderer(main_window, -1,0);
	while (true)
	{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT){break;}
	}
	// SDL_SetRenderDrawColor(renderer, 3, 255, 255, 255);
	// SDL_RenderClear(renderer);
	// SDL_RenderPresent(renderer);
	}
	clean_up();
=======
int main(){
	std::cout << "Fuck you Istifatty!" << std::endl;
>>>>>>> d219c172e78d0219166bd7df99dd91e8cfc7e740
	return 0;		
}

void game_loop(){

}
void update(){}
void render(){}
void clean_up(){
	main_window.cleanup();
}