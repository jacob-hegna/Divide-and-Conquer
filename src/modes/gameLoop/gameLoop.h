#ifndef _GAMELOOP_H
#define _GAMELOOP_H

#include "../../window/window.h"
#include "../../actor/hero/hero.h"
#include "../../actor/enemy/enemy.h"

float RandomFloat(float a, float b);

namespace GameLoop {

	struct Actors {
		Actors(float hx, float hy) {
			hero = new Hero(hx, hy, 75, 75, .2);
			enemy = new Enemy*;

			enemyAmt = 4;
			for(int i = 0; i < enemyAmt; ++i) {
				enemy[i] = new Enemy(rand() % 800 - 400, rand() % 600 - 300, 75, 75, RandomFloat(0.05f, 0.15f));
			}
		};

		Hero *hero;
		int enemyAmt;
		Enemy **enemy;
	};

	void init(void **data);
	void logic(Window *window, void *data);
	void render(void *data);
	void camera(Hero *hero);
}

#endif