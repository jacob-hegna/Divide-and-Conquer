/*************************************************************************
 * Divide and Conquer - enemy.cpp                                        *
 * www.github.com/jacob-hegna/Divide-and-Conquer                         *
 * --------------------------------------------------------------------- *
 * Copyright 2013 Jacob Hegna.                                           *
 *                                                                       *
 * This file is a part of Divide and Conquer.                            *
 *                                                                       *
 * Divide and Conquer is free software: you can redistribute it          *
 * and/or modify it under the terms of the GNU General Public            *
 * License as published by the Free Software Foundation, either          *
 * version 3 of the License, or (at your option) any later version.      *
 *                                                                       *
 * This program is distributed in the hope that it will be useful,       *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                  *
 * See the GNU General Public License for more details.                  *
 *                                                                       *
 * You should have received a copy of the GNU General Public License     *
 * along with this program.  If not, see <http://www.gnu.org/licenses/>. *
 ************************************************************************/

#include "enemy.h"
#include "../actors.h"

#include <cmath>

void Enemy::init(float x, float y,
				 float w, float h,
				 float speed,
				 float health,
				 float damage)
{
	_x       = x;
	_y       = y;
	_w       = w;
	_h       = h;
	_speed   = speed;
	_mhealth = health;
	_health  = health;
	_damage  = damage;
	_dead    = false;
	_theta   = 0.f;
}

void Enemy::move(Mode::Engine *engine) {
	Hero *hero = engine->getData<Actors>()->getHero(0);
	rotate(hero);
	_x += (_speed * cos(_theta + 3.1415/4))/engine->getInstFps();
	_y -= (_speed * sin(_theta + 3.1415/4))/engine->getInstFps();

	for(int i = 0; i < engine->getData<Actors>()->getHeroAmt(); ++i) {
		if(!_dead && !engine->getData<Actors>()->getHeros()->empty()) {
			hero = engine->getData<Actors>()->getHero(i);

			std::vector<Bullet*> *bullet = hero->getBullet();

			for(int i = (bullet->size() > 400) ? bullet->size() - 400 : 0; i < bullet->size(); ++i) {
				if(bullet->at(i)->getX() > _x &&
				bullet->at(i)->getX() < _x + _h &&
				bullet->at(i)->getY() > _y &&
				bullet->at(i)->getY() < _y + _h) {
					if(_health > 0) {
						_health-=guns[bullet->at(i)->getType()].damage;
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
		}
	}
}