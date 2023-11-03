#include<SDL2/SDL.h>
#include<iostream>
#include<string>
#include<game-engine/main.h>


int WINDOW_WIDTH = 1280;
int WINDOW_HEIGHT = 720;
int max_fps = 120;
const char* window_title = "Game-Engine Test";

GameScene scene;
Display main_window;
GameObject rectangle = GameObject(WINDOW_HEIGHT/2,WINDOW_HEIGHT/2,100,100);


void clean_up();

int main(int argc,char **argv){

	GameEngine::initialize();
	main_window = Display(window_title,WINDOW_WIDTH,WINDOW_HEIGHT);
	
	scene = GameScene();
	scene.addObjectToScene(rectangle);

	// GAME LOOP
	while (true){
		SDL_Event event;
		if (SDL_PollEvent(&event)){
			if (event.type == SDL_QUIT){break;}
		}

		rectangle.x += 0.05;

		main_window.update();
		main_window.renderObjects(scene);
	}
	clean_up();
	return 0;		
}
void clean_up(){
	main_window.cleanup();
}