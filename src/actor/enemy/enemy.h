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
		  float health = 100,
		  float damage = 0.1f) {init(x, y, w, h, speed, health, damage);}

	~Enemy(void) {

	}

	void init(float x = 0, float y = 0,
			  float w = 75, float h = 75,
			  float speed = 260,
			  float health = 100,
			  float damage = 0.1f);

	void move(Mode::Engine *engine);
	float getDamage(void) {
		return _damage;
	}
private:
	float _damage;
};

#endif