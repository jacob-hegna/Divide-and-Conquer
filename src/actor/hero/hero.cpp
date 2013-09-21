#include "hero.h"
#include "../actors.h"

void Hero::init(float x, float y,
				float w, float h,
				float speed,
				float health)
{
	Bullet::initGuns();
	_bullet = nullptr;
	_bullet = new std::vector<Bullet*>;

	_x       = x;
	_y       = y;
	_w       = w;
	_h       = h;
	_speed   = speed;
	_health  = health;
	_gunType = 1;
	_dead    = false;
	_theta   = 0.f;
}

void Hero::render(void) {

	for(int i = (_bullet->size() > 1000) ? _bullet->size() - 1000 : 0; i < _bullet->size(); ++i) {
		_bullet->at(i)->render();
	}

	glColor3f(5.f/_health, 0.f, _health/100.f);
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

	rotate(nullptr, (float)mx + engine->getData<Actors>()->camX-_x-_w/2, (float)my + engine->getData<Actors>()->camY-_y-_h/2, engine->getData<Actors>()->camX, engine->getData<Actors>()->camY, engine);

	_keys(engine);
	shoot(engine);
	_getDamage(engine);
}

void Hero::_keys(Mode::Engine *engine) {
	if(engine->getWindow()->getKey(GLFW_KEY_W)) _y -= _speed/engine->getInstFps();
	if(engine->getWindow()->getKey(GLFW_KEY_S)) _y += _speed/engine->getInstFps();
	if(engine->getWindow()->getKey(GLFW_KEY_A)) _x -= _speed/engine->getInstFps();
	if(engine->getWindow()->getKey(GLFW_KEY_D)) _x += _speed/engine->getInstFps();
}

void Hero::_getDamage(Mode::Engine *engine) {
	Actors *actors = engine->getData<Actors>();
	for(int i = 0; i < actors->getEnemyAmt(); ++i) {
		if(!actors->getEnemy(i)->getDead() && // Let's make sure that the enemy is alive
		   (actors->getEnemy(i)->getX() + actors->getEnemy(i)->getW()/2 > _x && // Now we will check to see if the enemy's center is inside of us
		   actors->getEnemy(i)->getX() + actors->getEnemy(i)->getW()/2 < _x + _w &&
		   actors->getEnemy(i)->getY() + actors->getEnemy(i)->getH()/2 > _y &&
		   actors->getEnemy(i)->getY() + actors->getEnemy(i)->getH()/2 < _y + _h)) {
			   _health -= actors->getEnemy(i)->getDamage()/engine->getInstFps();
			   if(_health <= 0) {
			        _dead = true;
			   }
		}
	}
}

void Hero::shoot(Mode::Engine *engine) {
	if(glfwGetMouseButton(engine->getWindow()->getWindow(), GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
		if(guns[_gunType].delay != -1) {
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

	int ww = engine->getWindow()->getW(),
		wh = engine->getWindow()->getH();

	bool canClear = true;
	for(int i = (_bullet->size() > 1000) ? _bullet->size() - 1000 : 0; i < _bullet->size(); ++i) {
		_bullet->at(i)->move(engine);
		if(canClear && (_bullet->at(i)->getX() < ww/2 + _x && 
			_bullet->at(i)->getX() > -ww/2 + _x && 
			_bullet->at(i)->getY() < wh/2 + _y &&
			_bullet->at(i)->getY() > -wh/2 + _y) &&
			!_bullet->at(i)->getDead()) {
			canClear = false;
		}
	}
	if(canClear) _bullet->clear();
}

void Hero::free(void) {
	_bullet->clear();
}