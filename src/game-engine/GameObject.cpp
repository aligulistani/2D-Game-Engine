
#include<game-engine/main.h>
GameObject::GameObject() {
    this->p = PhysicsComponent();
    this->animator = AnimationController();
};
GameObject::GameObject(PhysicsComponent p){ this->p = p; };
GameObject::GameObject(float x, float y){ this->world_pos = {x,y};};

void GameObject::InitializeAsBasicBox(b2Vec2 size) {
    this->p.def.position.Set(GameEngine::window->width/2,GameEngine::window->height/2);
    this->p.def.type = b2_dynamicBody;
    this->p.shape = b2PolygonShape();
    this->rendering_size.x = size.x;
    this->rendering_size.y = size.y;
    this->hitbox_size.x = size.x;
    this->hitbox_size.y = size.y;
    this->p.shape.SetAsBox(this->hitbox_size.x/2, hitbox_size.y/2);
    this->p.fixture_def = b2FixtureDef();
    this->p.fixture_def.shape = &this->p.shape;
    this->p.fixture_def.density = 1.0f;
    //this->p.fixture_def.friction = 0.25f;
    this->p.body = GameEngine::main_physics_world.physics_world->CreateBody(&this->p.def);
    this->p.fixture = this->p.body->CreateFixture(&this->p.fixture_def);
};

void GameObject::update() {
    this->world_pos = this->p.body->GetPosition();

    this->p.changeSizeofPhysicsBox(b2Vec2(this->hitbox_size.x * size_scale, this->hitbox_size.y * size_scale));

    SDL_FRect h;
    h.x = this->p.body->GetPosition().x - this->hitbox_size.x * size_scale / 2;
    h.y = this->p.body->GetPosition().y - this->hitbox_size.y * size_scale / 2;
    h.w = this->hitbox_size.x * size_scale;
    h.h = this->hitbox_size.y * size_scale;
    this->Hitbox = h;


    SDL_FRect t;
    if (this->animator.c_anim->sprite.identifer == "shoot1") {
        t.x = (this->world_pos.x - this->hitbox_size.x * size_scale / 2) - 15.0f * size_scale;
        t.y = (this->world_pos.y - this->hitbox_size.y * size_scale / 2) - 8.0f * size_scale;
    }else if (this->animator.c_anim->sprite.identifer == "shoot2") {
        t.x = (this->world_pos.x - this->hitbox_size.x * size_scale / 2) - 14.0f * size_scale;
        t.y = (this->world_pos.y - this->hitbox_size.y * size_scale / 2) - 8.0f * size_scale;
    }
    else {
        t.x = (this->world_pos.x - this->hitbox_size.x * size_scale / 2);
        t.y = (this->world_pos.y - this->hitbox_size.y * size_scale / 2);
    }
    t.w = (this->animator.c_anim->sprite.texture.w / this->animator.c_anim->frame_count) * size_scale ;
    t.h = (this->animator.c_anim->sprite.texture.h) * size_scale;
    //t.w = this->rendering_size.x * size_scale;
    //t.h = this->rendering_size.y * size_scale;
    this->rendering_data = t;
};
SDL_FRect GameObject::getRenderingData() {
    return this->rendering_data;
};

void GameObject::Destroy() {
    GameEngine::main_physics_world.physics_world->DestroyBody(this->p.body);
};

void GameObject::setPos(b2Vec2 pos){
    this->world_pos = pos;
}
