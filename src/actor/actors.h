/*************************************************************************
 * Divide and Conquer - actors.h                                         *
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

#ifndef _ACTORS_H
#define _ACTORS_H

#include <vector>

#include "hero/hero.h"
#include "enemy/enemy.h"

class Actors {
public:
	Actors(void) {
		_hero = new std::vector<Hero*>;
		_enemy = new std::vector<Enemy*>;
		heroKills = 0;
		heroPoints = 0;
		camX = 0;
		camY = 0;
	}

	~Actors(void) {
		free();
	}

	void free(void) {
		_hero->clear();
		delete _hero;
		_enemy->clear();
		delete _enemy;
	}
	
	void pushHero(float x, float y, float w, float h, float speed, float health) {
		Hero *hero = nullptr;
		hero = new Hero(x, y, w, h, speed, health);
		_hero->push_back(hero);
	}
	void pushEnemy(float x, float y, float w, float h, float speed, float health, float damage) {
		Enemy *enemy = nullptr;
		enemy = new Enemy(x, y, w, h, speed, health, damage);
		_enemy->push_back(enemy);
	}

	Hero* getHero(int i) {
		return _hero->at(i);
	}
	std::vector<Hero*>* getHeros(void) {
		return _hero;
	}

	Enemy* getEnemy(int i) {
		return _enemy->at(i);
	}
	std::vector<Enemy*>* getEnemies(void) {
		return _enemy;
	}

	int getHeroAmt(void) {
		return _hero->size();
	}
	int getEnemyAmt(void) {
		return _enemy->size();
	}
	
	// public variables :(
	int heroKills;
	int heroPoints;
	float camX, camY;

private:
	std::vector<Hero*>  *_hero;
	std::vector<Enemy*> *_enemy;
};

#endif