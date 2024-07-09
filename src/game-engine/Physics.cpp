#include<game-engine/main.h>

//b2Body* RigidBody::CreateRawB2Body(RB_DATA d){
//
//	//Body Def Init
//	d.body_definition.position.Set(d.inital_world_posiition.x, d.inital_world_posiition.y);
//	d.body_definition.type = d.body_type;
//
//	//Fixture Def Init
//	d.shape.SetAsBox(d.inital_world_size.x / 2.0f, d.inital_world_size.y / 2.0f);
//	d.fixture_definition.shape = &d.shape;
//	d.fixture_definition.density = d.density;
//	d.fixture_definition.friction = d.friction;
//	b2Body* temp_v;
//	if (GameEngine::renderer.get() != NULL) {
//		temp_v = GameEngine::main_physics_world.physics_world->CreateBody(&d.body_definition);
//		temp_v->CreateFixture(&d.fixture_definition);
//		printf("GameEngine is  initalized!, Creating Rigidbody\n");
//	}
//	else {
//		printf("GameEngine is not initalized!, Can not create Rigidbody\n");
//		temp_v = nullptr;
//	}
//	return temp_v;
//}

RigidBody::RigidBody() {
	//this->body = CreateRawB2Body(RB_DATA());
};
RigidBody::RigidBody(RB_DATA init_data) {
	//this->body = CreateRawB2Body(init_data);

	//Body Def Init
	init_data.body_definition.position.Set(init_data.inital_world_posiition.x, init_data.inital_world_posiition.y);
	init_data.body_definition.type = init_data.body_type;
	
	//Fixture Def Init
	init_data.shape.SetAsBox(init_data.inital_world_size.x / 2.0f, init_data.inital_world_size.y / 2.0f);
	init_data.fixture_definition.shape = &init_data.shape;
	init_data.fixture_definition.density = init_data.density;
	init_data.fixture_definition.friction = init_data.friction;

	this->size = b2Vec2(init_data.inital_world_size.x, init_data.inital_world_size.y);
	this->type = init_data.body_type;
	this->friction = init_data.friction;
	this->density = init_data.density;

	this->body = GameEngine::main_physics_world.physics_world->CreateBody(&init_data.body_definition);
	this->body->CreateFixture(&init_data.fixture_definition);
};

void PhysicsWorld::NextStep(){
	this->physics_world->Step(this->timeStep,this->velocityIterations,this->positionIterations);
};

void RigidBody::update() {
	this->body->DestroyFixture(&this->body->GetFixtureList()[0]);
	this->body->SetType(type);
	b2PolygonShape new_shape;
	new_shape.SetAsBox(this->size.x / 2.0f, this->size.y / 2.0f);
	b2FixtureDef new_fixtureDef;
	new_fixtureDef.shape = &new_shape;
	new_fixtureDef.density = this->density;
	new_fixtureDef.friction =this->friction;
	this->body->CreateFixture(&new_fixtureDef);
}
void RigidBody::SetSize(b2Vec2 size) {
	this->size.x = size.x;
	this->size.y = size.y;
	update();
}
void RigidBody::SetFriction(float f) {
	this->friction = f;
	update();
}
void RigidBody::SetType(b2BodyType t) {
	this->type = t;
	update();
}
void RigidBody::SetDensity(float d) {
	this->density = d;
	update();
}
b2Vec2 RigidBody::GetSize() {
	return this->size;
}
b2Body* RigidBody::GetRawBody() {
	return this->body;
};
b2Fixture RigidBody::GetFirstFixture() {
	return this->body->GetFixtureList()[0];
};
b2Vec2 RigidBody::GetWorldPosition() {
	return this->body->GetPosition();
};

