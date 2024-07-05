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