#ifndef _HERO_H
#define _HERO_H

#include <vector>
#include <cmath>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include "../actor.h"
#include "../../modes/engine/engine.h"
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

	void free(void);

private:
	void _keys(Mode::Engine *engine);
	void _getDamage(Mode::Engine *engine);

	// Variables for combat
	std::vector<Bullet*> *_bullet;
	GunType _gunType;
	int _ammo;

	// some stuff to make the fire rates work
	bool   _mouseBuffer;
	double _timeBuffer;
};

#endif