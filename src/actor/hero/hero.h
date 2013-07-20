#ifndef _HERO_H
#define _HERO_H

#include <vector>

#include "../actor.h"
#include "../../window/window.h"
#include "../bullet/bullet.h"

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

	}

	void init(float x = 0, float y = 0,
			  float w = 75, float h = 75,
			  float speed = 260,
			  float health = 100);

	void move(Window *window);
	void shoot(Window *window);

private:
	void keys(Window *window);

	std::vector<Bullet> bullet;
	GunType gunType;
	int ammo;
};

#endif