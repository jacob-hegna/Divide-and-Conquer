#include "enemy.h"
#include "../actors.h"

#include <cmath>

void Enemy::init(float x, float y,
				 float w, float h,
				 float speed,
				 float health,
				 float damage)
{
	_x      = x;
	_y      = y;
	_w      = w;
	_h      = h;
	_speed  = speed;
	_health = health;
	_damage = damage;
	_dead = false;
}

void Enemy::move(Mode::Engine *engine) {
	if(!_dead && !engine->getData<Actors>()->getHeros()->empty()) {
		Hero *hero = engine->getData<Actors>()->getHero(0);
		rotate(hero);

		std::vector<Bullet*> *bullet = hero->getBullet();

		for(int i = (bullet->size() > 400) ? bullet->size() - 400 : 0; i < bullet->size(); ++i) {
			if(bullet->at(i)->getX() > _x &&
			bullet->at(i)->getX() < _x + _h &&
			bullet->at(i)->getY() > _y &&
			bullet->at(i)->getY() < _y + _h) {
				if(_health > 0) {
					_health-=gun[bullet->at(i)->getType()].damage;
				} else {
					_dead = true;
					++engine->getData<Actors>()->heroKills;
					++engine->getData<Actors>()->heroPoints;
					_x = 0;
					_y = 0;
					_w = 0;
					_h = 0;
				}
				bullet->at(i)->die();
			}
		}
		_x += (_speed * cos(_theta + 3.1415/4))/((engine->getInstFps() > 100) ? engine->getInstFps() : 400);
		_y -= (_speed * sin(_theta + 3.1415/4))/((engine->getInstFps() > 100) ? engine->getInstFps() : 400);
	}
}