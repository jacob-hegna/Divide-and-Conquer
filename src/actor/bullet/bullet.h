/*************************************************************************
 * Divide and Conquer - bullet.h                                         *
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

#ifndef _BULLET_H
#define _BULLET_H

#include <vector>
#include <string>
#include <cmath>
#include <rapidxml/rapidxml.hpp>
#include <rapidxml/rapidxml_utils.hpp>

#include "guns.h"
#include "../actor.h"
#include "../../modes/engine/engine.h"
#include "../../util/util.h"

class Bullet : public Actor
{
private:
	int   _type;
    float _damage;
public:
    Bullet(void) {
		// Nothing to do here...
	}
    
	Bullet(float x, float y, float theta, int type) {
		init(x, y, theta, type);
	}

	~Bullet(void) {

	}
	
    void init(float x, float y, float theta, int type);
    void move(Mode::Engine *engine);
	void render();

    float getDamage(void) {return _damage;}

	float getX(void) {
		return _x;
	}
	float getY(void) {
		return _y;
	}
	int getType(void) {
		return _type;
	}
};

#endif