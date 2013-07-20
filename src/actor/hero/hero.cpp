#include "hero.h"

void Hero::init(float x, float y,
				float w, float h,
				float speed,
				float health)
{
	_x      = x;
	_y      = y;
	_w      = w;
	_h      = h;
	_speed  = speed;
	_health = health;
	gunType = GATLING;
}

void Hero::move(Window *window) {
	double mx, my;
	glfwGetCursorPos(window->getWindow(), &mx, &my);

	rotate(nullptr, (float)mx, (float)my);

	keys(window);

	shoot(window);
}

void Hero::keys(Window *window) {
	if(window->getKey(GLFW_KEY_W)) _y -= _speed;
	if(window->getKey(GLFW_KEY_S)) _y += _speed;
	if(window->getKey(GLFW_KEY_A)) _x -= _speed;
	if(window->getKey(GLFW_KEY_D)) _x += _speed;
}

void Hero::shoot(Window *window) {
	
}