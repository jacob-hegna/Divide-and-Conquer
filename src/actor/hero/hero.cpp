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
	if(glfwGetMouseButton(engine->getWindow()->getWindow(), GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
		if(gun[_gunType].delay != -1) {
			_bullet->push_back(new Bullet(cos(_theta*-1 - M_PI/4)*_w/2+_x+_w/2, sin(_theta*-1 - M_PI/4)*_h/2+_y+_h/2, (_theta*-1)-M_PI/4, _gunType));
		} else {
			if(!_mouseBuffer) {
				_bullet->push_back(new Bullet(cos(_theta*-1 - M_PI/4)*_w/2+_x+_w/2, sin(_theta*-1 - M_PI/4)*_h/2+_y+_h/2, (_theta*-1)-M_PI/4, _gunType));
				_mouseBuffer = true;
			}
		}
	} else if(glfwGetMouseButton(engine->getWindow()->getWindow(), GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE) {
		_mouseBuffer = false;
	}

	bool canClear = true;
	for(int i = 0; i < _bullet->size(); ++i) {
		_bullet->at(i)->move(engine);
		if(canClear && (_bullet->at(i)->getX() < 400 + _x && 
			_bullet->at(i)->getX() > -400 + _x && 
			_bullet->at(i)->getY() < 300 + _y &&
			_bullet->at(i)->getY() > -300 + _y)) {
			canClear = false;
		}
	}
	if(canClear) _bullet->clear();
}

void Hero::free(void) {
	_bullet->clear();
}