#define _USE_MATH_DEFINES
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include <GLFW\glfw3.h>

#include "actor.h"

void Actor::render(void) {
	if(!_dead) {
		glColor3f(1.f, 0.f, 0.f);
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

void Actor::rotate(Actor *dest, float xpos, float ypos)
{
	if(dest != nullptr)
	{
		float fx, fy;
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
		if(xpos != 400 && ypos != 300) {
			_theta = asin( (xpos - 400) / (sqrt(pow(xpos-400, 2) + pow(ypos - 300, 2))) );
			_theta *= -1;
			_theta += M_PI/4;

			if(ypos - 600/2 > 0)
			{
				_theta += M_PI/2;
				_theta *= -1;
			}
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
