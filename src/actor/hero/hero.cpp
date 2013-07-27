#include "hero.h"

void Hero::init(float x, float y,
				float w, float h,
				float speed,
				float health)
{
	Bullet::initGuns();
	_bullet = new std::vector<Bullet*>;

	_x      = x;
	_y      = y;
	_w      = w;
	_h      = h;
	_speed  = speed;
	_health = health;
	_gunType = GATLING;
}

void Hero::render(void) {

	for(int i = 0; i < _bullet->size(); ++i) {
		_bullet->at(i)->render();
	}

	glColor3f(0.f, 0.f, 1.f);
	glBegin(GL_QUADS);
		for(int i = 0; i < 4; ++i) {
			glVertex2f(_coords.x[i], _coords.y[i]);
		}
	glEnd();
}

void Hero::move(Mode::Engine *engine) {
	Window *window = engine->getWindow();
	double mx, my;
	glfwGetCursorPos(window->getWindow(), &mx, &my);

	rotate(nullptr, (float)mx, (float)my);

	_keys(engine);
	shoot(engine);
}

void Hero::_keys(Mode::Engine *engine) {
	if(engine->getWindow()->getKey(GLFW_KEY_W)) _y -= _speed/engine->getFps();
	if(engine->getWindow()->getKey(GLFW_KEY_S)) _y += _speed/engine->getFps();
	if(engine->getWindow()->getKey(GLFW_KEY_A)) _x -= _speed/engine->getFps();
	if(engine->getWindow()->getKey(GLFW_KEY_D)) _x += _speed/engine->getFps();
}

void Hero::shoot(Mode::Engine *engine) {
	if(engine->getWindow()->getKey(GLFW_KEY_SPACE)) {
		_bullet->push_back(new Bullet(_x, _y, (_theta*-1)-M_PI/4, _gunType));
	}

	for(int i = 0; i < _bullet->size(); ++i) {
		_bullet->at(i)->move(engine);
	}
}

void Hero::free(void) {
	_bullet->clear();
}