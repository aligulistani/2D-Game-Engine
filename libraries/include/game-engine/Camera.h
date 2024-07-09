#pragma once
#include<Box2D/Box2D.h>
struct Camera {
	Camera();
	b2Vec2 pos;
	float zoom_scale = 1.0f;
	void follow(Entity* e);
};

