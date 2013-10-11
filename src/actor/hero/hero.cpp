/*************************************************************************
 * Divide and Conquer - hero.cpp                                         *
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

#include "hero.h"
#include "../actors.h"

void Hero::init(float x, float y,
				float w, float h,
				float speed,
				float health)
{
	_bullet = nullptr;
	_bullet = new std::vector<Bullet*>;

	_x       = x;
	_y       = y;
	_w       = w;
	_h       = h;
	_speed   = speed;
	_mhealth = health;
	_health  = health;
	_gunType = 1;
	_dead    = false;
	_theta   = 0.f;
}

void Hero::render(void) {

	for(int i = (_bullet->size() > 1000) ? _bullet->size() - 1000 : 0; i < _bullet->size(); ++i) {
		_bullet->at(i)->render();
	}

	glColor4f(5.f/_health, 0.f, _health/100.f, _health/_mhealth);
	glBegin(GL_QUADS);
		for(int i = 0; i < 4; ++i) {
			glVertex2f(_coords.x[i], _coords.y[i]);
		}
	glEnd();
}

void Hero::move(Mode::Engine *engine) {
	Window *window = engine->getWindow();

	if(!engine->getWindow()->isJoy()) {
		double mx, my;
		glfwGetCursorPos(window->getWindow(), &mx, &my);
		rotate(nullptr, (float)mx + engine->getData<Actors>()->camX-_x-_w/2, (float)my + engine->getData<Actors>()->camY-_y-_h/2, engine->getData<Actors>()->camX, engine->getData<Actors>()->camY, engine);
		_keys(engine);	
	} else {
		_joy(engine);
	}

	shoot(engine);
	_getDamage(engine);
}

void Hero::_keys(Mode::Engine *engine) {
	if(engine->getWindow()->getKey(GLFW_KEY_W)) _y -= _speed/engine->getInstFps();
	if(engine->getWindow()->getKey(GLFW_KEY_S)) _y += _speed/engine->getInstFps();
	if(engine->getWindow()->getKey(GLFW_KEY_A)) _x -= _speed/engine->getInstFps();
	if(engine->getWindow()->getKey(GLFW_KEY_D)) _x += _speed/engine->getInstFps();

}

void Hero::_joy(Mode::Engine *engine) {
	_x             += engine->getWindow()->getJoyPos(0)*_speed/engine->getInstFps();
	_y             -= engine->getWindow()->getJoyPos(1)*_speed/engine->getInstFps();

	float x         = sqrt(pow(engine->getWindow()->getJoyPos(2), 2) + pow(engine->getWindow()->getJoyPos(3), 2));
	if(x != 0) {
		if(engine->getWindow()->getJoyPos(2) < 0) {
			_theta = acos(engine->getWindow()->getJoyPos(3)/x) + M_PI/4;
		} else {
			_theta = -1 * acos(engine->getWindow()->getJoyPos(3)/x) + M_PI/4;
		}
	}
	
	_coords.x[0]    = (float)(getXMid()-(sqrt(pow(_w,2)+pow(_h,2))/2*sin(_theta+M_PI/2)));
    _coords.y[0]    = (float)(getYMid()-(sqrt(pow(_w,2)+pow(_h,2))/2*cos(_theta+M_PI/2)));

    _coords.x[1]    = (float)(getXMid()-(sqrt(pow(_w,2)+pow(_h,2))/2*sin(_theta+M_PI)));
    _coords.y[1]    = (float)(getYMid()-(sqrt(pow(_w,2)+pow(_h,2))/2*cos(_theta+M_PI)));

    _coords.x[2]    = (float)(getXMid()-(sqrt(pow(_w,2)+pow(_h,2))/2*sin(_theta+M_PI*3/2)));
    _coords.y[2]    = (float)(getYMid()-(sqrt(pow(_w,2)+pow(_h,2))/2*cos(_theta+M_PI*3/2)));

    _coords.x[3]    = (float)(getXMid()-(sqrt(pow(_w,2)+pow(_h,2))/2*sin(_theta)));
    _coords.y[3]    = (float)(getYMid()-(sqrt(pow(_w,2)+pow(_h,2))/2*cos(_theta)));
}

void Hero::_getDamage(Mode::Engine *engine) {
	Actors *actors = engine->getData<Actors>();
	for(int i = 0; i < actors->getEnemyAmt(); ++i) {
		if(!actors->getEnemy(i)->getDead() && // Let's make sure that the enemy is alive
		   (actors->getEnemy(i)->getX() + actors->getEnemy(i)->getW()/2 > _x && // Now we will check to see if the enemy's center is inside of us
		   actors->getEnemy(i)->getX() + actors->getEnemy(i)->getW()/2 < _x + _w &&
		   actors->getEnemy(i)->getY() + actors->getEnemy(i)->getH()/2 > _y &&
		   actors->getEnemy(i)->getY() + actors->getEnemy(i)->getH()/2 < _y + _h)) {
			   _health -= actors->getEnemy(i)->getDamage()/engine->getInstFps();
			   if(_health <= 0) {
			        _dead = true;
			   }
		}
	}
}

void Hero::shoot(Mode::Engine *engine) {
	if((engine->getWindow()->isJoy()) ? 
		engine->getWindow()->getJoyButton(11) != 0 : 
		glfwGetMouseButton(engine->getWindow()->getWindow(), GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
		if(guns[_gunType].delay != -1) {
			_bullet->push_back(new Bullet(cos(_theta*-1 - M_PI/4)*_w/2+_x+_w/2, sin(_theta*-1 - M_PI/4)*_h/2+_y+_h/2, (_theta*-1)-M_PI/4, _gunType));
		} else {
			if(!_mouseBuffer) {
				_bullet->push_back(new Bullet(cos(_theta*-1 - M_PI/4)*_w/2+_x+_w/2, sin(_theta*-1 - M_PI/4)*_h/2+_y+_h/2, (_theta*-1)-M_PI/4, _gunType));
				_mouseBuffer = true;
			}
		}
	} else if(glfwGetMouseButton(engine->getWindow()->getWindow(), GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE) {
		_mouseBuffer = false;
	}

	int ww = engine->getWindow()->getW(),
		wh = engine->getWindow()->getH();

	bool canClear = true;
	for(int i = (_bullet->size() > 1000) ? _bullet->size() - 1000 : 0; i < _bullet->size(); ++i) {
		_bullet->at(i)->move(engine);
		if(canClear && (_bullet->at(i)->getX() < ww/2 + _x && 
			_bullet->at(i)->getX() > -ww/2 + _x && 
			_bullet->at(i)->getY() < wh/2 + _y &&
			_bullet->at(i)->getY() > -wh/2 + _y) &&
			!_bullet->at(i)->getDead()) {
			canClear = false;
		}
	}
	if(canClear) _bullet->clear();
}

void Hero::free(void) {
	_bullet->clear();
}