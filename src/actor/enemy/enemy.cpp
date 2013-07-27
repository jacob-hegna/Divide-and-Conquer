#include "enemy.h"
#include "../actors.h"

#include <cmath>

void Enemy::init(float x, float y,
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
	_dead = false;
}

void Enemy::move(Mode::Engine *engine) {
	Hero *hero = engine->getData<Actors>()->getHero(0);
	rotate(hero, 0, 0);

	std::vector<Bullet*> *bullet = hero->getBullet();

	for(int i = 0; i < bullet->size(); ++i) {
		if(bullet->at(i)->getX() > _x &&
		bullet->at(i)->getX() < _x + _h &&
		bullet->at(i)->getY() > _y &&
		bullet->at(i)->getY() < _y + _h) {
			(_health > 0) ? _health-=gun[bullet->at(i)->getType()].damage : _dead = true;
			bullet->at(i)->die();
			_x=0;
			_y=0;
			_w=0;
			_h=0;
		}
	}

	if(!_dead) {
		_x += (_speed * cos(_theta + 3.1415/4))/engine->getFps();
		_y -= (_speed * sin(_theta + 3.1415/4))/engine->getFps();
	}
}