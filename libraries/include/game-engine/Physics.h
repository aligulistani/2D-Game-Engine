#pragma once
#include<Box2D/Box2D.h>


struct RB_DATA {
	// Data to initalize a rigidbody
	b2BodyType body_type = b2_dynamicBody;
	b2Vec2 inital_world_posiition = b2Vec2(0.0f, 0.0f);
	b2Vec2 inital_hitbox_size = b2Vec2(50.0f,50.0f);
	b2Vec2 inital_world_size = b2Vec2(50.0f, 50.0f);
	b2PolygonShape shape = b2PolygonShape();
	float density = 1.0f; //default
	float friction = 0.3f; //default

	b2BodyDef body_definition = b2BodyDef();
	b2FixtureDef fixture_definition = b2FixtureDef();
};
struct RigidBody {
	RigidBody();
	RigidBody(RB_DATA init_data);
	//static b2Body* CreateRawB2Body(RB_DATA d);
	b2Body* body;
	void setTransform();
	void SetSize(b2Vec2 size);
	void SetFriction(float f);
	void SetDensity(float d);
	void SetType(b2BodyType t);
	b2Vec2 GetSize();
	b2Vec2 GetWorldPosition();
	b2Fixture GetFirstFixture();
	b2Body* GetRawBody();
private:
	b2BodyType type;
	b2Vec2 size;
	float friction;
	float density;
	b2Fixture* fixture; // IS NEVER DEFINED, GetFirstFixture gets it from the b2body pointer attribute
	void update();
};

struct PhysicsWorld {
	b2World* physics_world;
	float timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;
	void NextStep();
};




