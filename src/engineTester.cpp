#include<SDL2/SDL.h>
#include<iostream>
#include<string>
#include<math.h>
#include<game-engine/main.h>


int WINDOW_WIDTH = 1280;
int WINDOW_HEIGHT = 720;
int max_fps = 120;
const char* window_title = "Game-Engine Test";

GameScene scene;
Display main_window;

GameObject rectangle;
Texture ninja;

void game_loop();
void clean_up();

int main(int argc,char **argv){
	GameEngine::initialize();

	main_window = Display(window_title,WINDOW_WIDTH,WINDOW_HEIGHT);
	rectangle = GameObject(WINDOW_WIDTH/2,100,25,25);
	scene = GameScene();

	ninja = Texture("./res/ninja/Idle.png",main_window.renderer);

	GameEngine::set_main_game_loop(game_loop,-1);
	clean_up();
	return 0;		
}
float velocity_x = 0.5f;
float velocity_y = 0.5f;
float speed = 1.0f;

float t_inital;

const float force_gravity = 4.0f;
void game_loop(){
	scene.addObjectToScene(&rectangle);

	// rectangle.setPos({SDL_GetTicks()/50.0f,200.0f*sin(rectangle.pos[0]/5.0f)+WINDOW_HEIGHT/2});
	t_inital = SDL_GetTicks()/1000.0f;
	float acceleration = force_gravity*t_inital;
	rectangle.setVel(std::vector<float>{0.0f, acceleration});


	std::cout << acceleration << std::endl;

	if(rectangle.pos[1] >= WINDOW_HEIGHT ){// BOTTOM WALL
		rectangle.pos[1] = 0;
		t_inital = 0;
		acceleration = 0;
	}else if(rectangle.pos[1] <= 0){ // TOP WALL
		rectangle.pos[1] = 0;
	}else if(rectangle.pos[0] >= WINDOW_WIDTH){// RIGHT WALL
		rectangle.pos[0] = WINDOW_WIDTH-25;
	}else if(rectangle.pos[0] <= 0){// LEFT WALL
		rectangle.pos[0] = 0;
	}


	main_window.update();
	main_window.renderObjects(scene);
	scene.clearScene();
}
void clean_up(){
	main_window.cleanup();
}