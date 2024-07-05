#include<game-engine/main.h>

void game_loop();

// Window Settings
int WINDOW_WIDTH = 1280;
int WINDOW_HEIGHT = 720;
int max_fps = 50;
const char* window_title = "Game-Engine Test";

Display main_window;

Sprite blasphemous_sprite;

void load_assets() {
	SpriteSheetCollection blasphemous_sprites = SpriteSheetCollection("./res/blasphemous/");
	//blasphemous_sprites.setFrames();
}

PhysicsComponent ground;
b2Body* ground_bp;
b2Fixture* ground_f;
b2PolygonShape ground_shape;

int main(int argc,char **argv){
	main_window = Display(window_title,WINDOW_WIDTH,WINDOW_HEIGHT);
	GameEngine::initialize(&main_window);

	// Sprite loading currenlty broken
	//
	//load_assets();
	Sprite square_sprite = Sprite("./res/square.png",1,"square");



	GameObject box_ = GameObject();
	box_.sprite = square_sprite;
	box_.InitializeAsBasicBox(b2Vec2(100.0f, 100.0f));

	GameObject ground_ = GameObject();
	ground_.InitializeAsBasicBox(b2Vec2(WINDOW_WIDTH,100.0f));
	ground_.p.body->SetType(b2_staticBody);
	ground_.p.body->SetTransform(b2Vec2(0.0f,WINDOW_HEIGHT-100.0f),0);

	GameEngine::renderer.scene->addObjectToScene(&box_);
	GameEngine::renderer.scene->addObjectToScene(&ground_);

	GameEngine::start_main_game_loop(game_loop,max_fps);
	return 0;
}


void game_loop(){
	ImGui::ShowDemoWindow();
}