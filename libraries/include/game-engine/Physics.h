#pragma once
#include<Box2D/Box2D.h>

struct Hitbox {
	//SDL_FRect f_rect;
};

struct PhysicsWorld {
	b2World* physics_world;
	float timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;
	void NextStep();
};
struct PhysicsComponent
{
	PhysicsComponent();
	b2BodyDef def;
	b2PolygonShape shape;
	b2FixtureDef fixture_def;

	b2Body* body;
	b2Fixture* fixture;
	void changeSizeofPhysicsBox(b2Vec2 size);
};



