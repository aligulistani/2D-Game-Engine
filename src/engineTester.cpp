#include<game-engine/main.h>
#include"imgui.h"
#include <Box2D/Box2D.h>
#include <game-engine/PhysicsObject.h>

void game_loop();

// Window Settings
int WINDOW_WIDTH = 1280;
int WINDOW_HEIGHT = 720;
int max_fps = 120;
const char* window_title = "Game-Engine Test";

using namespace std;

EventHandler handler;
Display main_window;

GameObject player;
Sprite blasphemous_sprite;

b2Vec2 gravity(0.0f, 10.0f);
b2World world(gravity);

GameObject physics_square;
GameObject physics_ground;
//
/* To Do:
 *  Reorganize all code and classes
 *
 *
 *
 */


int main(int argc,char **argv){
	main_window = Display(window_title,WINDOW_WIDTH,WINDOW_HEIGHT);
	GameEngine::initialize(&main_window);

	blasphemous_sprite = Sprite("./res/blasphemous/test_sprite.png", main_window.renderer.get(),6);

	// Initializing Player Game Object

	player = GameObject(200.0f, 100.0f, blasphemous_sprite, true);
	//physics_square = GameObject(PhysicsObject(b2Vec2(10.0f,500.0f), b2_staticBody, &world, 0.0f, 0.0f));
	//physics_ground = GameObject(PhysicsObject(b2Vec2(10.0f,10.0f), b2_dynamicBody, &world, 1.0f, 0.3f));

	GameEngine::set_main_game_loop(game_loop,-1, &handler);
	return 0;
}
bool a;
void game_loop(){
	ImGui::ShowDemoWindow();

	// ImGui::Begin("Animations");
	// if(ImGui::DragInt("Speed (ms)", &player.sprite.animation.animation_speed, 1.0f, 1, 1000, "%d")){}
	// ImGui::End();

	if(handler.keyPressed(SDL_SCANCODE_D)){}


	//physics_square.updateRect();
	//main_window.game_scene.addObjectToScene(&physics_square);
	//main_window.game_scene.addObjectToScene(&physics_ground);
	main_window.game_scene.addObjectToScene(&player);

}