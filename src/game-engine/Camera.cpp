#include<game-engine/main.h>

Camera::Camera() {
	this->pos = b2Vec2(0.0f,0.0f);
}
void Camera::follow(GameObject* g) {
	this->pos = b2Vec2(g->p.body->GetPosition().x - GameEngine::window->width/2, g->p.body->GetPosition().y - GameEngine::window->height / 2);
};