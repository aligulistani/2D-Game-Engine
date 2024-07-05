
#include<game-engine/main.h>
GameObject::GameObject() {
    this->p = PhysicsComponent();
    this->animator = AnimationController();
};
GameObject::GameObject(PhysicsComponent p){
    this->p = p;
};
GameObject::GameObject(float x, float y){ this->pos = {x,y};};
GameObject::GameObject(float x, float y, Sprite t){
    this->pos = {x,y};
    this->sprite = t;
};

void GameObject::InitializeAsBasicBox(b2Vec2 size) {
    this->p.def.position.Set(GameEngine::window->width/2,GameEngine::window->height/2);
    this->p.def.type = b2_dynamicBody;
    this->p.shape = b2PolygonShape();
    this->p.hx = size.x / 2;
    this->p.hy = size.y / 2;
    this->p.shape.SetAsBox(this->p.hx, this->p.hy);
    this->p.fixture_def = b2FixtureDef();
    this->p.fixture_def.shape = &this->p.shape;
    this->p.fixture_def.density = 1.0f;
    //this->p.fixture_def.friction = 0.25f;
    this->p.body = GameEngine::main_physics_world.physics_world->CreateBody(&this->p.def);
    this->p.fixture = this->p.body->CreateFixture(&this->p.fixture_def);
};

void GameObject::Destroy() {
    GameEngine::main_physics_world.physics_world->DestroyBody(this->p.body);
};

void GameObject::setPos(b2Vec2 pos){
    this->pos = pos;
}
