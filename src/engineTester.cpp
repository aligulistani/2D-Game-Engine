#include<game-engine/main.h>

void game_loop();

// Window Settings
int WINDOW_WIDTH = 1280;
int WINDOW_HEIGHT = 720;
int max_fps = 50;
const char* window_title = "Game-Engine Test";

Display main_window;
GameObject ninja;
GameObject ground_;
Animation square_animation;

void load_assets() {
	square_animation = Animation(Sprite("./res/square.png", "square"), 1);
	ground_.animator.animations.push_back(square_animation);
	ninja.animator.animations.push_back(Animation(Sprite("./res/ninja/Idle.png", "ninja_idle"), 8));
	ninja.animator.animations.push_back(Animation(Sprite("./res/ninja/Attack1.png", "ninja_attack1"), 6));
	ninja.animator.animations.push_back(Animation(Sprite("./res/ninja/Attack2.png", "ninja_attack2"), 6));
	ninja.animator.animations.push_back(Animation(Sprite("./res/ninja/Death.png", "ninja_death"), 6));
	ninja.animator.animations.push_back(Animation(Sprite("./res/ninja/Fall.png", "ninja_fall"), 2));
	ninja.animator.animations.push_back(Animation(Sprite("./res/ninja/Jump.png", "ninja_jump"), 2));
	ninja.animator.animations.push_back(Animation(Sprite("./res/ninja/Run.png", "ninja_run"), 8));
	ninja.animator.animations.push_back(Animation(Sprite("./res/ninja/Take Hit.png", "ninja_takehit"), 4));
}


int main(int argc,char **argv){
	main_window = Display(window_title,WINDOW_WIDTH,WINDOW_HEIGHT);
	GameEngine::initialize(&main_window);


	ninja = GameObject();
	ninja.InitializeAsBasicBox(b2Vec2(200.0f,100.0f));
	ninja.p.fixture->SetFriction(1.0f);
	ninja.p.body->SetFixedRotation(true);

	ground_ = GameObject();
	ground_.InitializeAsBasicBox(b2Vec2(WINDOW_WIDTH/2,50.0f));
	ground_.p.body->SetType(b2_staticBody);
	ground_.p.body->SetTransform(b2Vec2(WINDOW_WIDTH / 2, WINDOW_HEIGHT - 100.0f), 0);

	load_assets();

	GameEngine::renderer.scene->addObjectToScene(&ninja);
	GameEngine::renderer.scene->addObjectToScene(&ground_);

	GameEngine::start_main_game_loop(game_loop,max_fps);
	return 0;
}

float ninja_speed = 20.0f;
bool ninja_grounded = false;

void game_loop(){
	ImGui::ShowDemoWindow();

	ground_.animator.runAnimation("square",-1);
	ground_.p.changeSizeofPhysicsBox(b2Vec2(ground_.animator.hx, ground_.animator.hy));

	ninja.animator.hx = ninja.animator.c_anim->sprite.texture.w / ninja.animator.c_anim->frame_count;
	ninja.animator.hy = ninja.animator.c_anim->sprite.texture.h;

	// SPAWNING NEW SQUARES 
	//if (GameEngine::handler.MousePressed(1)) {
	//	GameObject* t = new GameObject();
	//	t->InitializeAsBasicBox(b2Vec2(50.0f,50.0f));
	//	t->animator.animations.push_back(square_animation);
	//	t->animator.runAnimation("square", -1);
	//	t->p.body->SetTransform(b2Vec2(GameEngine::handler.current_event.button.x, GameEngine::handler.current_event.button.y),0);
	//	GameEngine::renderer.scene->addObjectToScene(t);
	//}


	if (GameEngine::handler.keyPressed(SDL_SCANCODE_R)) {
		GameEngine::renderer.scene->clearScene();
	}

	if (ninja.p.body->GetLinearVelocity().x == 0.0f) {
		// Check to see if player is moving, if not moving then run the idle animation
		ninja.animator.runAnimation("ninja_idle", -1);
	};
	if (ninja.p.body->GetLinearVelocity().y == 0.0f) {
		// check to see if player is touching the ground by checking it's y velocity value, if true then we are allowed to jump
		ninja_grounded = true;
	}

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
	//if (GameEngine::handler.keyPressed(SDL_SCANCODE_W)) {
	//	//ninja.animator.runAnimation("ninja_run",-1);
	//	//ninja.animator.flip_state = SDL_FLIP_HORIZONTAL;
	//	//ninja.p.body->SetLinearVelocity(b2Vec2( -1*ninja_speed, ninja.p.body->GetLinearVelocity().y));
	//}
	//if (GameEngine::handler.keyPressed(SDL_SCANCODE_S)) {
	//	//ninja.animator.runAnimation("ninja_run", -1);
	//	//ninja.animator.flip_state = SDL_FLIP_NONE;
	//	//ninja.p.body->SetLinearVelocity(b2Vec2(ninja_speed, ninja.p.body->GetLinearVelocity().y));
	//}

	/*JUMP FUNCTION*/
	if (GameEngine::handler.keyPressed(SDL_SCANCODE_SPACE)) {
		if (ninja_grounded) {
			ninja_grounded = false;
			ninja.animator.runAnimation("ninja_jump", -1);
			ninja.p.body->ApplyLinearImpulseToCenter(b2Vec2(0.0f, ninja.p.body->GetMass() * -50), true);
		}
	}

	// other animation switches and checks
	if (ninja.p.body->GetLinearVelocity().y > 5.0f) {
		ninja.animator.runAnimation("ninja_fall", -1);
	}
	if (GameEngine::handler.keyReleased(SDL_SCANCODE_J)) {
		ninja.animator.runAnimation("ninja_attack1", 1);
	}
	if (GameEngine::handler.keyReleased(SDL_SCANCODE_K)) {
		ninja.animator.runAnimation("ninja_attack2", 1);
	}


	ImGui::Begin("Debug Menu");
	ImGui::SliderFloat("Size of HX (Animation)", &ground_.animator.hx, 1.0f, 1000.0f);
	ImGui::SliderFloat("Size of HY (Animation)", &ground_.animator.hy, 1.0f, 1000.0f);
	ImGui::Text("Player Velocity: (%f, %f)",ninja.p.body->GetLinearVelocity().x, ninja.p.body->GetLinearVelocity().y);
	ImGui::Text("Current Animation Frame: (%i)", ninja.animator.c_anim->animation_current_frame);
	ImGui::SliderInt("Animation Speed", &ninja.animator.c_anim->animation_speed, 1.0f, 1000.0f);
	ImGui::Text("Camera Pos: (%f,%f)", GameEngine::main_camera.pos.x, GameEngine::main_camera.pos.y);
	ImGui::End();

}