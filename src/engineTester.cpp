#include<game-engine/main.h>

void game_loop();

// Window Settings
int WINDOW_WIDTH = 1280;
int WINDOW_HEIGHT = 720;
int max_fps = 50;
const char* window_title = "Game-Engine Test";

Display main_window;

void load_assets() {
	SpriteSheetCollection blasphemous_sprites = SpriteSheetCollection("./res/blasphemous/");
	//blasphemous_sprites.setFrames();
}

GameObject box_;
GameObject ground_;

Animation square_sprite;

Animation ninja_idle;
Animation ninja_attack1;
Animation ninja_attack2;
Animation ninja_death;
Animation ninja_fall;
Animation ninja_jump;
Animation ninja_run;
Animation ninja_takehit;


GameObject ninja;

int main(int argc,char **argv){
	main_window = Display(window_title,WINDOW_WIDTH,WINDOW_HEIGHT);
	GameEngine::initialize(&main_window);

	// Sprite loading currenlty broken
	//
	//load_assets();
	
	square_sprite = Animation(Sprite("./res/square.png", "square"),1);

	ninja_idle = Animation(Sprite("./res/ninja/Idle.png", "ninja_idle"), 8);
	ninja_attack1 =	Animation(Sprite("./res/ninja/Attack1.png", "ninja_attack1"), 6);
	ninja_attack2 =	Animation(Sprite("./res/ninja/Attack2.png", "ninja_attack2"),6);
	ninja_death =	Animation(Sprite("./res/ninja/Death.png", "ninja_death"),6);
	ninja_fall =	Animation(Sprite("./res/ninja/Fall.png", "ninja_fall"),2);
	ninja_jump =	Animation(Sprite("./res/ninja/Jump.png", "ninja_jump"),2);
	ninja_run =		Animation(Sprite("./res/ninja/Run.png", "ninja_run"),8);
	ninja_takehit =	Animation(Sprite("./res/ninja/Take Hit.png", "ninja_takehit"),4);


	ninja = GameObject();
	ninja.animator.animations.push_back(&ninja_idle);
	ninja.animator.animations.push_back(&ninja_attack1);
	ninja.animator.animations.push_back(&ninja_attack2);
	ninja.animator.animations.push_back(&ninja_death);
	ninja.animator.animations.push_back(&ninja_fall);
	ninja.animator.animations.push_back(&ninja_jump);
	ninja.animator.animations.push_back(&ninja_run);
	ninja.animator.animations.push_back(&ninja_takehit);

	ninja.InitializeAsBasicBox(b2Vec2((ninja.sprite.texture.w/8), ninja.sprite.texture.h));
	ninja.p.fixture->SetFriction(1.0f);
	ninja.p.body->SetFixedRotation(true);
	//box_ = GameObject();
	//box_.sprite = square_sprite;
	//box_.InitializeAsBasicBox(b2Vec2(50.0f, 50.0f));

	ground_ = GameObject();
	ground_.InitializeAsBasicBox(b2Vec2(WINDOW_WIDTH/2,50.0f));
	ground_.p.body->SetType(b2_staticBody);
	ground_.p.body->SetTransform(b2Vec2(WINDOW_WIDTH/2,WINDOW_HEIGHT-100.0f),0);
	ground_.animator.animations.push_back(square_sprite);

	//GameEngine::renderer.scene->addObjectToScene(&box_);
	GameEngine::renderer.scene->addObjectToScene(&ninja);
	GameEngine::renderer.scene->addObjectToScene(&ground_);

	GameEngine::start_main_game_loop(game_loop,max_fps);
	return 0;
}

float ninja_speed = 20.0f;
bool ninja_grounded = false;
b2Vec2 ninja_vel(0.0f,0.0f);
const Uint8* keystates = SDL_GetKeyboardState(NULL);

void game_loop(){
	ImGui::ShowDemoWindow();

	if (GameEngine::handler.MousePressed(1)) {
		GameObject* t = new GameObject();
		t->InitializeAsBasicBox(b2Vec2(50.0f,50.0f));
		t->animator.runAnimation("square", -1);
		t->p.body->SetTransform(b2Vec2(GameEngine::handler.current_event.button.x, GameEngine::handler.current_event.button.y),0);
		GameEngine::renderer.scene->addObjectToScene(t);
	}

	if (keystates[SDL_SCANCODE_R]) {
		GameEngine::renderer.scene->clearScene();
	}

	if (GameEngine::handler.keyPressed(SDL_SCANCODE_W)) {
		/*ninja.p.body->ApplyForce(b2Vec2(),b2Vec2(),true);*/
	}
	if (keystates[SDL_SCANCODE_A]) {
		ninja.animator.runAnimation("ninja_run",-1);
		//ninja.p.hx = ninja_run.texture.w / 2;
		ninja.sprite.flip = SDL_FLIP_HORIZONTAL;
		ninja.p.body->SetLinearVelocity(b2Vec2( -1*ninja_speed, ninja.p.body->GetLinearVelocity().y));

	}
	if (GameEngine::handler.keyPressed(SDL_SCANCODE_S)){
	}
	if (keystates[SDL_SCANCODE_D]) {
		ninja.sprite.flip = SDL_FLIP_NONE;
		ninja.animator.runAnimation("ninja_run", -1);
		ninja.p.body->SetLinearVelocity(b2Vec2(ninja_speed, ninja.p.body->GetLinearVelocity().y));

	}


	if (keystates[SDL_SCANCODE_SPACE]) {
		if (ninja_grounded) {
			ninja_grounded = false;

			ninja.animator.runAnimation("ninja_jump", -1);
			ninja.p.body->ApplyLinearImpulseToCenter(b2Vec2(0.0f, ninja.p.body->GetMass() * -50), true);
		}
	}
	if (ninja.p.body->GetLinearVelocity().y > 5.0f) {
		ninja.animator.runAnimation("ninja_fall", -1);
	}
	if (ninja.p.body->GetLinearVelocity().y == 0.0f) {
		ninja_grounded = true;
	}
	if (ninja.p.body->GetLinearVelocity() == b2Vec2(0.0f, 0.0f)) {

		ninja.animator.runAnimation("ninja_idle",-1);

	}

	if (GameEngine::handler.keyPressed(SDL_SCANCODE_J)) {
		ninja.animator.runAnimation("ninja_attack1", -1);
	}

	std::cout << ninja_grounded << std::endl;
}