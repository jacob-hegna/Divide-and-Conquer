#ifndef _GAMELOOP_H
#define _GAMELOOP_H

#include "../engine/engine.h"
#include "../../window/window.h"
#include "../../actor/hero/hero.h"
#include "../../actor/enemy/enemy.h"
#include "../../utilities/util.h"

namespace GameLoop {

	struct Actors {
		Actors(float hx, float hy) {
			hero = new Hero(hx, hy, 75, 75, .2);
			enemy = new Enemy*;

			enemyAmt = 4;
			for(int i = 0; i < enemyAmt; ++i) {
				enemy[i] = new Enemy(rand() % 800 - 400, rand() % 600 - 300, 75, 75, randF(0.05f, 0.15f));
			}
		};

		Hero *hero;
		int enemyAmt;
		Enemy **enemy;
	};

	void init(Mode::Engine* engine);
	void logic(Mode::Engine* engine);
	void render(Mode::Engine* engine);
	void camera(Hero*);
}

#endif