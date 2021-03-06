#ifndef _ACTOR_H
#define _ACTOR_H

#include <vector>

#include "../window/window.h"
#include "../modes/engine/engine.h"

class Actor {
public:
	Actor(void) {
		// Nothing to do...
	}

	~Actor(void) {

	}

	void rotate(Actor *dest, float xpos = 0, float ypos = 0, float camx = 0, float camy = 0, Mode::Engine* engine = nullptr);

	virtual void render(void);

	void die(void) {
		_x=0;_y=0;_w=0;_h=0;_dead=true;
	}

	void getCenter(float *x, float *y);
	
	float getXMid(void) {
		return _x+_w/2;
	}

	float getYMid(void) {
		return _y+_h/2;
	}

	float getW(void) {
		return _w;
	}

	float getH(void) {
		return _h;
	}

	float getCornerX(int i) {
		return _coords.x[i];
	}

	float getCornerY(int i) {
		return _coords.y[i];
	}
	
	float getTheta(void) {
		return _theta;
	}

	float getSpeed(void) {
		return _speed;
	}

	float getHealth(void) {
		return _health;
	}

	bool getDead(void) {
		return _dead;
	}

	float getX(void) {return _x;}
	float getY(void) {return _y;}
protected:
	float _x, _y;
	float _w, _h;
	float _theta;
	float _speed;
	float _health;
	float _mhealth;
	bool  _dead;


	/*******
	* 1---2
	* |   |
	* 4---3
	*******/
	struct {
		float x[4];
		float y[4];
	} _coords;
};

#endif