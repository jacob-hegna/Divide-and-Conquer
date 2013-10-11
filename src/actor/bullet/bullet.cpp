/*************************************************************************
 * Divide and Conquer - bullet.cpp                                       *
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

#include "bullet.h"

void Bullet::init(float px, float py, float ptheta, int type)
{
    _type = type;
    _speed  = guns[_type].speed;
    _w      = guns[_type].bW;
    _h      = guns[_type].bH;
    _x      = px-_w/2;
    _y      = py-_h/2;
    _theta  = ptheta;
    _damage = guns[_type].damage;
    _dead  = false;

    _theta += randF(-guns[_type].acc, guns[_type].acc);
}

void Bullet::move(Mode::Engine *engine)
{
	_x += (_speed * cos(_theta))/engine->getInstFps();
	_y += (_speed * sin(_theta))/engine->getInstFps();
}

void Bullet::render(void)
{
    if(!_dead)
    {
        glColor3f(0.f, 0.f, 0.f);
        glBegin(GL_QUADS);
            glVertex2d(_x, _y);
            glVertex2d(_x+_w, _y);
            glVertex2d(_x+_w, _y+_h);
            glVertex2d(_x, _y+_h);
        glEnd();
    }
}