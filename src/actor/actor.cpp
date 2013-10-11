/*************************************************************************
 * Divide and Conquer - actor.cpp                                        *
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

#define _USE_MATH_DEFINES
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include <GLFW/glfw3.h>

#include "actor.h"

void Actor::render(void) {
	if(!_dead) {
		glColor4f(1.f, 0.f, 0.f, _health/_mhealth);
		glBegin(GL_QUADS);
			for(int i = 0; i < 4; ++i) {
				glVertex2f(_coords.x[i], _coords.y[i]);
			}
		glEnd();
	}
}

void Actor::getCenter(float *x, float *y)
{
	*x = (getCornerX(3) + getCornerX(1))/2;
	*y = (getCornerY(3) + getCornerY(1))/2;
}

void Actor::rotate(Actor *dest, float xpos, float ypos, float camx, float camy, Mode::Engine *engine)
{
	if(dest != nullptr)
	{
		float fx = 0, 
		      fy = 0;
		dest->getCenter(&fx, &fy);
		xpos = fx;
		ypos = fy;
		_theta = asin( (xpos - getXMid()) / (sqrt(pow(xpos-getXMid(), 2) + pow(ypos - getYMid(), 2))) );

		_theta *= -1;
		_theta += M_PI/4;

		if(ypos - getYMid() > 0)
		{
			_theta += M_PI/2;
			_theta *= -1;
		}
	}
	else
	{
		int ww = 800,
			wh = 600;
		if(engine != nullptr) {
			ww = engine->getWindow()->getW();
			wh = engine->getWindow()->getH();
		}
		_theta = asin( (xpos - ww/2) / (sqrt(pow(xpos-ww/2, 2) + pow(ypos - wh/2, 2))) );
		_theta *= -1;
		_theta += M_PI/4;

		if(ypos - wh/2 > 0)
		{
			_theta += M_PI/2;
			_theta *= -1;
		}
	}

	_coords.x[0] = (float)(getXMid()-(sqrt(pow(_w,2)+pow(_h,2))/2*sin(_theta+M_PI/2)));
    _coords.y[0] = (float)(getYMid()-(sqrt(pow(_w,2)+pow(_h,2))/2*cos(_theta+M_PI/2)));

    _coords.x[1] = (float)(getXMid()-(sqrt(pow(_w,2)+pow(_h,2))/2*sin(_theta+M_PI)));
    _coords.y[1] = (float)(getYMid()-(sqrt(pow(_w,2)+pow(_h,2))/2*cos(_theta+M_PI)));

    _coords.x[2] = (float)(getXMid()-(sqrt(pow(_w,2)+pow(_h,2))/2*sin(_theta+M_PI*3/2)));
    _coords.y[2] = (float)(getYMid()-(sqrt(pow(_w,2)+pow(_h,2))/2*cos(_theta+M_PI*3/2)));

    _coords.x[3]  = (float)(getXMid()-(sqrt(pow(_w,2)+pow(_h,2))/2*sin(_theta)));
    _coords.y[3]  = (float)(getYMid()-(sqrt(pow(_w,2)+pow(_h,2))/2*cos(_theta)));
}
