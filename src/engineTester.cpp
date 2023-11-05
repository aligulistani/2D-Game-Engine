#include<game-engine/main.h>

int WINDOW_WIDTH = 1280;
int WINDOW_HEIGHT = 720;
int max_fps = 120;
const char* window_title = "Game-Engine Test";

GameScene scene;
Display main_window;

GameObject rectangle;
Sprite ninja_sprite;
GameObject ninja;

void game_loop();
void clean_up();

float clock_temp_start;


int main(int argc,char **argv){
	GameEngine::initialize();

	main_window = Display(window_title,WINDOW_WIDTH,WINDOW_HEIGHT);
	scene = GameScene();

	ninja_sprite = Sprite("./res/ninja/Idle.png");
	// rectangle = GameObject(50.0f,100.0f,25,25);

	GameEngine::set_main_game_loop(game_loop,-1);
	clean_up();
	return 0;		
}

const float force_gravity = 9.81f;

// // Tick Clock Algorithm
// - Beginning of Tick is 0 seconds
// - End of Tick is measured
// - should get how long tick lasts in millisec.onds

// Time Variables

float previous_tick_t = 0;
float current_tick_t = 0;
float tick_time;

Timer clock = Timer();

// TIMER VARIABLES
float timer_start;
float timer_end;

// TEMP PHYSICS
float force_friction = 0.005f;
float inital_throw_force = 5.0f;

std::vector<int> x; 
std::vector<int> y; 

void game_loop(){
	//You can grab the up-time of last tick at the beginning of each new tick

	clock.startTimer();

	scene.addObjectToScene(&rectangle);

	// rectangle.setPos({SDL_GetTicks()/50.0f,200.0f*sin(rectangle.pos[0]/5.0f)+WINDOW_HEIGHT/2});
	float acceleration = force_gravity * clock.previousTime/1000.0f;

	if(inital_throw_force > 0.0f && !clock.open){
		inital_throw_force -= force_friction;
	}

	if(inital_throw_force < 0){
		inital_throw_force = 0;
	}


	rectangle.setVel(std::vector<float>{inital_throw_force, acceleration});
	if(clock.open){
		x.push_back(rectangle.pos[0]);
		y.push_back(rectangle.pos[1]);
	}

	// std::cout << inital_throw_force << std::endl;

	if(rectangle.pos[1] >= WINDOW_HEIGHT ){// BOTTOM WALL
		rectangle.pos[1] = WINDOW_HEIGHT-50;
		clock.endTimer();
		acceleration = 0.0f;
	}else if(rectangle.pos[1] <= 0){ // TOP WALL
		rectangle.pos[1] = 0;
	}else if(rectangle.pos[0]+50 >= WINDOW_WIDTH){// RIGHT WALL
		rectangle.pos[0] = WINDOW_WIDTH-50;
		rectangle.velocity[0] = 0;
	}else if(rectangle.pos[0] <= 0){// LEFT WALL
		rectangle.pos[0] = 0;
	}

	previous_tick_t = current_tick_t;
	current_tick_t = SDL_GetTicks();
	tick_time = current_tick_t - previous_tick_t;
	// std::cout << tick_time << std::endl; // How long every frame/tick takes in milliseconds


	main_window.update();
	SDL_SetRenderDrawColor(main_window.renderer,255, 255, 255, 255);
    for(int i=0;i<x.size();i++){
        SDL_RenderDrawPoint(main_window.renderer, x[i],y[i]);
    }
	main_window.renderObjects(scene);
	scene.clearScene();
}
void clean_up(){
	main_window.cleanup();
}