#pragma once
#include<Box2D/Box2D.h>
struct Camera {
	Camera();
	b2Vec2 pos;
	void follow(GameObject* g);
};

