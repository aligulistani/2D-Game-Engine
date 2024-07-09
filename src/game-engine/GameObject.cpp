
#include<game-engine/main.h>
GameObject::GameObject() {
    this->animator = AnimationController();
};

Entity::Entity() {}
Entity::Entity(RB_DATA rigidbody_data) {
    this->r_b = new RigidBody(rigidbody_data);
    this->hitbox_size = b2Vec2(rigidbody_data.inital_hitbox_size.x, rigidbody_data.inital_hitbox_size.y);
    //this->InitializeRigidBody(rigidbody_data);
    //this->InitializeAnimator();
    this->animator = AnimationController();
}

//void Entity::InitializeRigidBody(RB_DATA data) {
//    //this->GetRigidbody()->SetSize() = data.inital_world_size.x;
//    //this->collider_size.y = data.inital_world_size.y;
//
//    this->r_b = RigidBody(data);
//}

//void GameObject::InitializeAnimator() {
//    this->animator = AnimationController();
//}

AnimationController* GameObject::GetAnimator() {
    return &this->animator;
}

void GameObject::update() {
    
}


void GameObject::ScaleSize(float v) {
    this->size_scale = v;
}

RigidBody* Entity::GetRigidbody() {
    return this->r_b;
}

void Entity::update() {

    //ALLIGN 2 the worl positions
    this->world_pos.x = this->r_b->GetWorldPosition().x - this->r_b->GetSize().x / 2.0f;
    this->world_pos.y = this->r_b->GetWorldPosition().y - this->r_b->GetSize().y / 2.0f;

    //this->r_b->SetSize(b2Vec2(this->hitbox_size.x,this->hitbox_size.y));

    SDL_FRect pre_main_sprite;
    pre_main_sprite.x = this->world_pos.x ;
    pre_main_sprite.y = this->world_pos.y ;

    if (this->animator.c_anim->identifer == "shoot1") {
        pre_main_sprite.w = (this->world_pos.x - this->r_b->GetSize().x * size_scale / 2) - 15.0f * size_scale;
        pre_main_sprite.h = (this->world_pos.y - this->r_b->GetSize().y * size_scale / 2) - 8.0f * size_scale;
    }
    else if (this->animator.c_anim->identifer == "shoot2") {
        pre_main_sprite.w = (this->world_pos.x - this->r_b->GetSize().x * size_scale / 2) - 14.0f * size_scale;
        pre_main_sprite.h = (this->world_pos.y - this->r_b->GetSize().y * size_scale / 2) - 8.0f * size_scale;
    }
    else {
        pre_main_sprite.w = (this->world_pos.x - this->r_b->GetSize().x * size_scale / 2);
        pre_main_sprite.h = (this->world_pos.y - this->r_b->GetSize().y * size_scale / 2);
    }

    pre_main_sprite.w = (this->animator.c_anim->sprite.texture.w / this->animator.c_anim->frame_count) * size_scale;
    pre_main_sprite.h = (this->animator.c_anim->sprite.texture.h) * size_scale;

    this->r_b->SetSize(b2Vec2(pre_main_sprite.w,pre_main_sprite.h));

    SDL_FRect pre_p_hitbox;
    pre_p_hitbox.x = (this->r_b->GetRawBody()->GetPosition().x - this->r_b->GetSize().x / 2) * size_scale;
    pre_p_hitbox.y = (this->r_b->GetRawBody()->GetPosition().y - this->r_b->GetSize().y / 2) * size_scale ;
    pre_p_hitbox.w = this->r_b->GetSize().x * size_scale;
    pre_p_hitbox.h = this->r_b->GetSize().y * size_scale;


    RenderData r_data;
    r_data.main_sprite = pre_main_sprite;
    r_data.physics_hitbox = pre_p_hitbox;
    r_data.sprite_hitbox = pre_main_sprite;

    this->rendering_data = r_data;
};

RenderData* GameObject::getRenderingData() {
    return &this->rendering_data;
};

void GameObject::Destroy() {
   // GameEngine::main_physics_world.physics_world->DestroyBody(this->r_b.GetSize().x);
};

void GameObject::setWorldPosition(b2Vec2 pos){
    this->world_pos = pos;
}
b2Vec2 GameObject::GetWorldPosition() {
    return this->world_pos;
}
