#include<game-engine/main.h>
#include"imgui.h"
#include <Box2D/Box2D.h>
#include <game-engine/Physics.h>


/*
 *
 *
 *
 *
 */


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

b2BodyDef groundBodyDef;
b2Body* body;
b2Vec2 gravity(0.0f, 9.81f);
b2World world(gravity);

GameObject physics_square;
GameObject physics_ground;

float timeStep = 1.0f / 60.0f;
int32 velocityIterations = 6;
int32 positionIterations = 2;

int main(int argc,char **argv){
	main_window = Display(window_title,WINDOW_WIDTH,WINDOW_HEIGHT);
	GameEngine::initialize(&main_window);

	//Physics Testing
	groundBodyDef.position.Set(10.0f, 500.0f);
	b2Body* groundBody = world.CreateBody(&groundBodyDef);
	b2PolygonShape groundBox;
	groundBox.SetAsBox(50.0f, 50.0f);
	groundBody->CreateFixture(&groundBox, 0.0f);

	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(10.0f, 50.0f);
	body = world.CreateBody(&bodyDef);

	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(50.0f, 50.0f);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;
	body->CreateFixture(&fixtureDef);

	blasphemous_sprite = Sprite("./res/blasphemous/test_sprite.png", main_window.renderer.get(),6);
	player = GameObject(200.0f, 100.0f, blasphemous_sprite, true);
	physics_square = GameObject(body);
	physics_ground = GameObject(groundBody);
	//Testing Physics class, method that applies a force at point on object, 0,0 is center of mass --> 0 Torque
	b2Vec2 force = b2Vec2(500000000.0, 500000000.0);
	//object.AppliedForce(force, point, body);
	for (int32 i = 0; i < 60; ++i)
	{
		//world.Step(timeStep, velocityIterations, positionIterations);
		b2Vec2 position = body->GetPosition();
		float angle = body->GetAngle();
		//printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
	}

	GameEngine::set_main_game_loop(game_loop,-1, &handler);
	return 0;
}

bool a;
void game_loop(){
	EventHandler DetectKey;
	Physics object;
	DetectKey.pollEvents();
	if (DetectKey.keyPressed(SDL_SCANCODE_SPACE)){
		cout<<"Pressed Spacebar"<<endl;
		object.Jump(body);
	}
	ImGui::ShowDemoWindow();
	b2Vec2 position = body->GetPosition();
	float angle = body->GetAngle();
	//printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
	world.Step(timeStep, velocityIterations, positionIterations);

	ImGui::Begin("Animations");
	// // if(	ImGui::Button("Attack 1")) {
	// // 	player.sprite = ninja_attack1;
	// // }
	// // if(	ImGui::Button("Attack 2")) {
	// // 	player.sprite = ninja_attack2;
	// // }mai
	// // if(	ImGui::Button("Run")) {
	// // 	player.sprite = ninja_run;
	// // }
	// // if(	ImGui::Button("Death")) {
	// // 	player.sprite = ninja_death;
	// // }
	// // if(	ImGui::Button("Idle")) {
	// // 	player.sprite = ninja_idle;
	// // } 
	if(ImGui::DragInt("Speed (ms)", &player.sprite.animation.animation_speed, 1.0f, 1, 1000, "%d")){}
	ImGui::End();
	physics_square.updateRect();
	//cout << physics_square.rect.y << endl;
	main_window.game_scene.addObjectToScene(&physics_square);
	main_window.game_scene.addObjectToScene(&physics_ground);
	main_window.game_scene.addObjectToScene(&player);

}