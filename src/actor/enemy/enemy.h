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
		  float health = 100) {init(x, y, w, h, speed, health);}

	~Enemy(void) {

	}

	void init(float x = 0, float y = 0,
			  float w = 75, float h = 75,
			  float speed = 260,
			  float health = 100);

	void move(Mode::Engine *engine);
};

#endif