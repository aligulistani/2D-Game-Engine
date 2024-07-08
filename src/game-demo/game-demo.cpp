#include<game-engine/main.h>

void game_loop();

// Window Settings
int WINDOW_WIDTH = 1024;
int WINDOW_HEIGHT = 580;
int max_fps = 50;
const char* window_title = "Game-Engine Test";

Display main_window;

AnimationFrame platform_sprite;
AnimationFrame bg_sprite;

GameObject enemy;
GameObject ninja;
GameObject ground_;
GameObject background;

void load_assets() {
	platform_sprite = AnimationFrame(Sprite("./res/risk/platform.png", "platform"), 1);
	bg_sprite = AnimationFrame(Sprite("./res/risk/s_bg.png", "background"), 1);
	ground_.animator.animations.push_back(platform_sprite);
	background.animator.animations.push_back(bg_sprite);
	//Player
	ninja.animator.animations.push_back(AnimationFrame(Sprite("./res/risk/huntress_idle.png", "idle"), 12, b2Vec2(6.0f,1.0f)));
	ninja.animator.animations.push_back(AnimationFrame(Sprite("./res/risk/shoot1.png", "shoot1"), 9, b2Vec2(22.0f,6.0f)));
	ninja.animator.animations.push_back(AnimationFrame(Sprite("./res/risk/shoot2.png", "shoot2"), 9, b2Vec2(22.0f, 6.0f)));
	ninja.animator.animations.push_back(AnimationFrame(Sprite("./res/ninja/Death.png", "ninja_death"), 6));
	ninja.animator.animations.push_back(AnimationFrame(Sprite("./res/risk/huntress_fall.png", "ninja_fall"), 1));
	ninja.animator.animations.push_back(AnimationFrame(Sprite("./res/risk/huntress_jump.png", "ninja_jump"), 1));
	ninja.animator.animations.push_back(AnimationFrame(Sprite("./res/risk/huntress_walk.png", "ninja_run"), 8));
	ninja.animator.animations.push_back(AnimationFrame(Sprite("./res/ninja/Take Hit.png", "ninja_takehit"), 4));

									
	//Enemy
	enemy.animator.animations.push_back(AnimationFrame(Sprite("./res/enemy/Idle.png", "enemy_idle"), 4));
	enemy.animator.animations.push_back(AnimationFrame(Sprite("./res/enemy/Attack1.png", "enemy_attack1"), 4));
	enemy.animator.animations.push_back(AnimationFrame(Sprite("./res/enemy/Attack2.png", "enemy_attack2"), 4));
	enemy.animator.animations.push_back(AnimationFrame(Sprite("./res/enemy/Death.png", "enemy_death"), 7));
	enemy.animator.animations.push_back(AnimationFrame(Sprite("./res/enemy/Fall.png", "enemy_fall"), 2));
	enemy.animator.animations.push_back(AnimationFrame(Sprite("./res/enemy/Jump.png", "enemy_jump"), 2));
	enemy.animator.animations.push_back(AnimationFrame(Sprite("./res/enemy/Run.png", "enemy_run"), 8));
	enemy.animator.animations.push_back(AnimationFrame(Sprite("./res/enemy/Hit.png", "enemy_takehit"), 3));
}


int main(int argc,char **argv){
	main_window = Display(window_title,WINDOW_WIDTH,WINDOW_HEIGHT);
	GameEngine::initialize(&main_window);

	background = GameObject();
	background.InitializeAsBasicBox(b2Vec2(WINDOW_WIDTH,WINDOW_HEIGHT));
	background.p.body->SetType(b2_staticBody);
	background.p.body->SetTransform(b2Vec2(0.0f,500.0f), 0);
	GameEngine::main_physics_world.physics_world->DestroyBody(background.p.body);
	background.world_pos = b2Vec2(0.0f, 500.0f);


	ninja = GameObject();
	ninja.InitializeAsBasicBox(b2Vec2(20.0f,25.0f));
	ninja.p.fixture->SetFriction(1.0f);
	ninja.p.body->SetFixedRotation(true);
	ninja.size_scale = 3.0f;


	enemy = GameObject();
	enemy.InitializeAsBasicBox(b2Vec2(200.0f, 100.0f));
	enemy.p.fixture->SetFriction(1.0f);
	enemy.p.body->SetFixedRotation(true);
	enemy.p.body->SetTransform(b2Vec2(WINDOW_WIDTH/2 - 300.0f,WINDOW_HEIGHT/2),0);

	ground_ = GameObject();
	ground_.InitializeAsBasicBox(b2Vec2(WINDOW_WIDTH/2,50.0f));
	ground_.p.body->SetType(b2_staticBody);
	ground_.p.body->SetTransform(b2Vec2(WINDOW_WIDTH / 2, WINDOW_HEIGHT - 100.0f), 0);

	load_assets();

	GameEngine::renderer.scene->addObjectToScene(&background);
	GameEngine::renderer.scene->addObjectToScene(&ninja);
	GameEngine::renderer.scene->addObjectToScene(&enemy);
	GameEngine::renderer.scene->addObjectToScene(&ground_);

	GameEngine::start_main_game_loop(game_loop,max_fps);
	return 0;
}

float ninja_speed = 20.0f;
bool ninja_grounded = false;

void game_loop(){
	ImGui::ShowDemoWindow();

	ground_.animator.runAnimation("square",-1);
	background.animator.runAnimation("background",-1);
	enemy.animator.runAnimation("enemy_idle",-1);

	if (ninja.p.body->GetLinearVelocity().y == 0.0f) {
		// check to see if player is touching the ground by checking it's y velocity value, if true then we are allowed to jump
		ninja_grounded = true;
	}
	ninja.animator.runAnimation("idle", -1);
	//PLAYER MOVEMENT
	if (GameEngine::handler.keyPressed(SDL_SCANCODE_A)) {
		ninja.animator.runAnimation("ninja_run",-1);
		ninja.animator.flip_state = SDL_FLIP_HORIZONTAL;
		ninja.p.body->SetLinearVelocity(b2Vec2( -1*ninja_speed, ninja.p.body->GetLinearVelocity().y));
	}
	if (GameEngine::handler.keyPressed(SDL_SCANCODE_D)) {
		ninja.animator.runAnimation("ninja_run", -1);
		ninja.animator.flip_state = SDL_FLIP_NONE;
		ninja.p.body->SetLinearVelocity(b2Vec2(ninja_speed, ninja.p.body->GetLinearVelocity().y));
	}

	GameEngine::main_camera.follow(&ninja);


	/*JUMP FUNCTION*/
	if (GameEngine::handler.keyPressed(SDL_SCANCODE_SPACE)) {
		if (ninja_grounded) {
			ninja_grounded = false;
			ninja.animator.runAnimation("ninja_jump", -1);
			ninja.p.body->ApplyLinearImpulseToCenter(b2Vec2(0.0f, ninja.p.body->GetMass() * -70), true);
		}
	}
	if (ninja.p.body->GetLinearVelocity().x == 0.0f) {
		// Check to see if player is moving, if not moving then run the idle animation
		ninja.animator.runAnimation("idle", -1);
	};

	// other animation switches and checks
	if (ninja.p.body->GetLinearVelocity().y > 5.0f) {
		ninja.animator.runAnimation("ninja_fall", -1);
	}
	if (GameEngine::handler.keyPressed(SDL_SCANCODE_J)) {
		ninja.animator.runAnimation("shoot1", 1);
		printf("ATTACK 1 PRESSED\n");
	}
	if (GameEngine::handler.keyPressed(SDL_SCANCODE_K)) {
		ninja.animator.runAnimation("shoot2", 1);
		printf("ATTACK 2 PRESSED\n");
	}

	ImGui::Begin("Debug Menu");
	ImGui::SliderFloat("Size of HX (Animation)", &ninja.hitbox_size.x, 1.0f, 1000.0f);
	ImGui::SliderFloat("Size of HY (Animation)", &ninja.hitbox_size.y, 1.0f, 1000.0f);
	ImGui::SliderFloat("Size Scale", &ninja.size_scale, 1.0f, 50.0f);
	ImGui::SliderFloat("Player Shoot1 Offset X:", &ninja.animator.c_anim->offset.x, -50.0f, 50.0f);
	ImGui::SliderFloat("Player Shoot1 Offset Y:", &ninja.animator.c_anim->offset.y, -50.0f, 50.0f);
	ImGui::SliderFloat("Camera Zoom", &GameEngine::main_camera.zoom_scale, 0.0f, .9999f);
	ImGui::Text("Player Velocity: (%f, %f)",ninja.p.body->GetLinearVelocity().x, ninja.p.body->GetLinearVelocity().y);
	ImGui::Text("Player Pos: (%f,%f)", ninja.p.body->GetPosition().x , ninja.p.body->GetPosition().y );
	ImGui::Text("Current Animation Frame: (%i)", ninja.animator.c_anim->animation_current_frame);
	ImGui::SliderInt("Animation Speed", &ninja.animator.c_anim->animation_speed, 1.0f, 1000.0f);
	ImGui::Text("Camera Pos: (%f,%f)", GameEngine::main_camera.pos.x, GameEngine::main_camera.pos.y);
	ImGui::Text("Enemy Pos: (%f,%f)", enemy.p.body->GetPosition().x , enemy.p.body->GetPosition().y );
	ImGui::End();
}