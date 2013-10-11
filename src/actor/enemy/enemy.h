/*************************************************************************
 * Divide and Conquer - enemy.h                                          *
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

#ifndef _ENEMY_H
#define _ENEMY_H

#include "../actor.h"
#include "../hero/hero.h"
#include "../../modes/engine/engine.h"

class Enemy : public Actor {
public:
	Enemy(void) {
		// Nothing to do here...
	}

	Enemy(float x, float y,
		  float w = 75, float h = 75,
		  float speed = 260,
		  float health = 100,
		  float damage = 0.1f) {init(x, y, w, h, speed, health, damage);}

	~Enemy(void) {

	}

	void init(float x = 0, float y = 0,
			  float w = 75, float h = 75,
			  float speed = 260,
			  float health = 100,
			  float damage = 0.1f);

	void move(Mode::Engine *engine);
	float getDamage(void) {
		return _damage;
	}
private:
	float _damage;
};

#endif