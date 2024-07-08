#include<game-engine/main.h>



PhysicsComponent::PhysicsComponent() {
	this->def = b2BodyDef();
	def.type = b2_staticBody; // DEFAULT BODY TYPE
	this->shape = b2PolygonShape();
	this->fixture_def = b2FixtureDef();
};

void PhysicsWorld::NextStep(){
	this->physics_world->Step(this->timeStep,this->velocityIterations,this->positionIterations);
};

void PhysicsComponent::changeSizeofPhysicsBox(b2Vec2 size) {
	this->body->DestroyFixture(&this->body->GetFixtureList()[0]);
	b2PolygonShape new_shape;
	new_shape.SetAsBox(size.x /2, size.y /2);
	b2FixtureDef new_fixtureDef;
	new_fixtureDef.shape = &new_shape;
	new_fixtureDef.density = 1;
	new_fixtureDef.friction = 0.3f;
	this->body->CreateFixture(&new_fixtureDef);
}