#include<game-engine/main.h>

Camera::Camera() {
	this->pos = b2Vec2(0.0f,0.0f);
}
void Camera::follow(Entity* e) {
	this->pos = b2Vec2(e->GetRigidbody()->GetRawBody()->GetPosition().x - GameEngine::window->width/2,e->GetRigidbody()->GetRawBody()->GetPosition().y - GameEngine::window->height / 2);
};