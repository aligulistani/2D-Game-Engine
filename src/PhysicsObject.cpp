/*
 * Main Physics Handler for the Game Enigne
 */

#include<game-engine/PhysicsObject.h>
PhysicsObject::PhysicsObject() {};
PhysicsObject::PhysicsObject(b2Vec2 pos, b2BodyType type, b2World* world, float density, float friction) {
    this->world = world;
    this->definition.position.Set(pos.x, pos.y);
    this->definition.type = type;
    this->body = this->world->CreateBody(&definition);
    b2PolygonShape groundBox;
    groundBox.SetAsBox(50.0f, 50.0f);
    this->fixture_definition.shape = &groundBox;
    this->fixture_definition.density = density;
    this->fixture_definition.friction = friction;
    this->body->CreateFixture(&this->fixture_definition);
};

float timeStep = 1.0f / 60.0f;
int32 velocityIterations = 6;
int32 positionIterations = 2;

void PhysicsObject::updateAllPhysics() {
    this->world->Step(timeStep, velocityIterations, positionIterations);
}
