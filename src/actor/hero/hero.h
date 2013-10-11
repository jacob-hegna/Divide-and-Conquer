/*************************************************************************
 * Divide and Conquer - hero.h                                           *
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

#ifndef _HERO_H
#define _HERO_H

#include <vector>
#include <cmath>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include "../actor.h"
#include "../../modes/engine/engine.h"
#include "../bullet/guns.h"
#include "../bullet/bullet.h"
#include "../../util/util.h"

class Hero : public Actor {
public:
	Hero(void) {
		// Nothing to do here...
	}

	Hero(float x, float y,
		 float w = 75, float h = 75,
		 float speed = 260,
		 float health = 100) {init(x, y, w, h, speed, health);}

	~Hero(void) {
		free();
	}

	void init(float x = 0, float y = 0,
			  float w = 75, float h = 75,
			  float speed = 260,
			  float health = 100);

	void move(Mode::Engine *engine);
	void shoot(Mode::Engine *engine);
	void render(void);

	std::vector<Bullet*>* getBullet(void) {
		return _bullet;
	}

	bool setType(int type) {
		if(type < GUN_AMT) {
			_gunType = type;
			return true;
		} else {
			return false;
		}
	}
	void decType(void) {
		if(_gunType > 0) {
			--_gunType;
		}
	}
	void incType(void) {
		if(_gunType < GUN_AMT) {
			++_gunType;
		}
	}

	void free(void);

private:
	void _keys(Mode::Engine *engine);
	void _joy(Mode::Engine *engine);
	void _getDamage(Mode::Engine *engine);

	// Variables for combat
	std::vector<Bullet*> *_bullet;
	int _gunType;
	int _ammo;

	// some stuff to make the fire rates work
	bool   _mouseBuffer;
	double _timeBuffer;
};

#endif