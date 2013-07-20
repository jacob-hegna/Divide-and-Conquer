#include "enemy.h"

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
}

void Enemy::move(Hero *hero) {
	rotate(hero, 0, 0);

	_x += _speed * cos(_theta + 3.1415/4);
	_y -= _speed * sin(_theta + 3.1415/4);
}