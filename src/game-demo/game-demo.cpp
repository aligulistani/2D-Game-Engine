#include<game-engine/main.h>

void game_loop();

// Window Settings
int WINDOW_WIDTH = 1024;
int WINDOW_HEIGHT = 580;
int max_fps = 50;
const char* window_title = "Game-Engine Test";

Display main_window;

Entity enemy;
Entity player;
Entity ground_;
Entity background;

void load_assets() {

	//// Ground Sprite
	//ground_.GetAnimator()->AddAnimation(Animation(SpriteSheet("./res/MAIN/ground_strip.png"), 1, "ground"));
	ground_.GetAnimator()->AddAnimation(Animation(SpriteSheet("./res/MAIN/ground_strip_f.png"), 1, "ground"));
	ground_.GetAnimator()->InitializeDefaultAnimation("ground");

	// Background Image
	background.GetAnimator()->AddAnimation(Animation(SpriteSheet("./res/risk/background.png"), 1, "background"));
	background.GetAnimator()->InitializeDefaultAnimation("background");

	////Player
	player.GetAnimator()->AddAnimation(Animation(SpriteSheet("./res/risk/huntress_idle.png"), 12, "idle"));
	player.GetAnimator()->AddAnimation(Animation(SpriteSheet("./res/risk/shoot1.png"), 9, "shoot1"));
	player.GetAnimator()->AddAnimation(Animation(SpriteSheet("./res/risk/shoot2.png"), 9, "shoot2"));
	player.GetAnimator()->AddAnimation(Animation(SpriteSheet("./res/player/Death.png"), 6, "player_death"));
	player.GetAnimator()->AddAnimation(Animation(SpriteSheet("./res/risk/huntress_fall.png"), 1, "player_fall"));
	player.GetAnimator()->AddAnimation(Animation(SpriteSheet("./res/risk/huntress_jump.png"), 1, "player_jump"));
	player.GetAnimator()->AddAnimation(Animation(SpriteSheet("./res/risk/huntress_walk.png"), 8, "player_run"));
	player.GetAnimator()->AddAnimation(Animation(SpriteSheet("./res/player/Take Hit.png"), 4, "player_takehit"));
	player.GetAnimator()->InitializeDefaultAnimation("idle");
	//								
	////Golem
	enemy.GetAnimator()->AddAnimation(Animation(SpriteSheet("./res/MAIN/Golem/GolemIdle.png"), 1, "idle"));
	enemy.GetAnimator()->AddAnimation(Animation(SpriteSheet("./res/MAIN/Golem/GolemAttack1.png"), 16, "attack1"));
	enemy.GetAnimator()->AddAnimation(Animation(SpriteSheet("./res/MAIN/Golem/GolemWalk.png"), 12, "walk"));
	enemy.GetAnimator()->InitializeDefaultAnimation("idle");
}


int main(int argc,char **argv){
	main_window = Display(window_title,WINDOW_WIDTH,WINDOW_HEIGHT);
	GameEngine::initialize(&main_window);


	RB_DATA BACKGROUND_SETTINGS = RB_DATA{};
	BACKGROUND_SETTINGS.body_type = b2_staticBody;
	BACKGROUND_SETTINGS.inital_world_posiition = b2Vec2(0.0f, 0.0f);
	background = Entity(BACKGROUND_SETTINGS);
	background.ScaleSize(2.0f);

	RB_DATA PLAYER_RB_SETTINGS = RB_DATA{};
	PLAYER_RB_SETTINGS.inital_world_posiition = b2Vec2((WINDOW_WIDTH / 2) , (WINDOW_HEIGHT / 2));
	PLAYER_RB_SETTINGS.inital_hitbox_size = b2Vec2(18.0f,25.0f); // Hitbox Size, manually taken from sprite
	player = Entity(PLAYER_RB_SETTINGS);
	player.GetRigidbody()->GetRawBody()->SetFixedRotation(true);
	player.ScaleSize(2.0f);


	RB_DATA ENEMY_RB_SETTINGS = RB_DATA();
	ENEMY_RB_SETTINGS.inital_world_posiition = b2Vec2((WINDOW_WIDTH / 2) - 250.0f, (WINDOW_HEIGHT / 2) - 200.0f);
	ENEMY_RB_SETTINGS.inital_hitbox_size = b2Vec2(18.0f, 25.0f); // Hitbox Size, manually taken from sprite
	enemy = Entity(ENEMY_RB_SETTINGS);
	enemy.GetRigidbody()->GetRawBody()->SetFixedRotation(true);


	RB_DATA PLATFORM_RB_SETTINGS = RB_DATA{};
	PLATFORM_RB_SETTINGS.body_type = b2_staticBody;
	PLATFORM_RB_SETTINGS.inital_world_posiition = b2Vec2(WINDOW_WIDTH /2, WINDOW_HEIGHT + 50.0f);
	PLATFORM_RB_SETTINGS.inital_world_size = b2Vec2(500.0f,50.0f);
	PLATFORM_RB_SETTINGS.inital_hitbox_size = b2Vec2(500.0f, 50.0f);
	ground_ = Entity(PLATFORM_RB_SETTINGS);
	load_assets();

	GameEngine::renderer.scene->addObjectToScene(&background);
	GameEngine::renderer.scene->addObjectToScene(&player);
	GameEngine::renderer.scene->addObjectToScene(&enemy);
	GameEngine::renderer.scene->addObjectToScene(&ground_);

    GameEngine::start_main_game_loop(game_loop,max_fps);
	return 0;
}

float player_speed = 20.0f;
bool player_grounded = false;

void game_loop(){
	ImGui::ShowDemoWindow();

	player.GetAnimator()->PlayAnimation("idle",-1);
	enemy.GetAnimator()->PlayAnimation("attack1",-1);

	//ground_.animator.PlayAnimation("platform",-1);
	//background.animator.PlayAnimation("background",-1);
	//enemy.animator.PlayAnimation("walk",-1);

	if (player.GetRigidbody()->GetRawBody()->GetLinearVelocity().y == 0.0f) {
		// check to see if player is touching the ground by checking it's y velocity value, if true then we are allowed to jump
		player_grounded = true;
	}
	//player.animator.PlayAnimation("idle", -1);


	////PLAYER MOVEMENT
	if (GameEngine::handler.keyPressed(SDL_SCANCODE_A)) {
		player.animator.PlayAnimation("player_run",-1);
		player.animator.flip_state = SDL_FLIP_HORIZONTAL;
		player.GetRigidbody()->GetRawBody()->SetLinearVelocity(b2Vec2( -1*player_speed, player.GetRigidbody()->GetRawBody()->GetLinearVelocity().y));
	}
	if (GameEngine::handler.keyPressed(SDL_SCANCODE_D)) {
		player.animator.PlayAnimation("player_run", -1);
		player.animator.flip_state = SDL_FLIP_NONE;
		player.GetRigidbody()->GetRawBody()->SetLinearVelocity(b2Vec2(player_speed, player.GetRigidbody()->GetRawBody()->GetLinearVelocity().y));
	}

	//GameEngine::main_camera.follow(&player);


	///*JUMP FUNCTION*/
	if (GameEngine::handler.keyPressed(SDL_SCANCODE_SPACE)) {
		if (player_grounded) {
			player_grounded = false;
			player.animator.PlayAnimation("player_jump", -1);
			player.GetRigidbody()->GetRawBody()->ApplyLinearImpulseToCenter(b2Vec2(0.0f, player.GetRigidbody()->GetRawBody()->GetMass() * -70), true);
		}
	}
	if (player.GetRigidbody()->GetRawBody()->GetLinearVelocity().x == 0.0f) {
		// Check to see if player is moving, if not moving then run the idle animation
		player.animator.PlayAnimation("idle", -1);
	};

	// other animation switches and checks
	if (player.GetRigidbody()->GetRawBody()->GetLinearVelocity().y > 5.0f) {
		player.animator.PlayAnimation("player_fall", -1);
	}
	if (GameEngine::handler.keyPressed(SDL_SCANCODE_J)) {
		player.animator.PlayAnimation("shoot1", 1);
		printf("ATTACK 1 PRESSED\n");
	}
	if (GameEngine::handler.keyPressed(SDL_SCANCODE_K)) {
		player.animator.PlayAnimation("shoot2", 1);
		printf("ATTACK 2 PRESSED\n");
	}

	ImGui::Begin("Debug Menu");
	ImGui::SliderFloat("Size of HX (Animation)", &player.hitbox_size.x, 1.0f, 1000.0f);
	ImGui::SliderFloat("Size of HY (Animation)", &player.hitbox_size.y, 1.0f, 1000.0f);
	ImGui::SliderFloat("Ground POS X", &ground_.world_pos.x, 1.0f, 1000.0f);
	ImGui::SliderFloat("Ground POS Y", &ground_.world_pos.y, 1.0f, 1000.0f);
	ImGui::SliderFloat("Size Scale", &player.size_scale, 1.0f, 50.0f);
	ImGui::SliderFloat("Camera Zoom", &GameEngine::main_camera.zoom_scale, 0.0f, .9999f);
	//if (ImGui::Button("Walk")) {
	//	enemy.GetAnimator()->PlayAnimation("walk",1);
	//}
	ImGui::Text("Player Pos: (%f,%f)", player.GetWorldPosition().x, player.GetWorldPosition().y );
	ImGui::Text("Current Animation Frame: (%i)", player.animator.c_anim->animation_current_frame);
	ImGui::SliderInt("Animation Speed", &player.animator.c_anim->animation_speed, 1.0f, 1000.0f);
	ImGui::Text("Camera Pos: (%f,%f)", GameEngine::main_camera.pos.x, GameEngine::main_camera.pos.y);
	//ImGui::Text("Enemy Pos: (%f,%f)", enemy.p.body->GetPosition().x , enemy.p.body->GetPosition().y );
	ImGui::End();
}