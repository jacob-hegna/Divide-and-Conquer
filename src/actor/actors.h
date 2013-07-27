#ifndef _ACTORS_H
#define _ACTORS_H

#include <vector>

#include "hero\hero.h"
#include "enemy\enemy.h"

class Actors {
public:
	Actors(void) {
		_hero = new std::vector<Hero*>;
		_enemy = new std::vector<Enemy*>;
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
		_hero->push_back(new Hero(x, y, w, h, speed, health));
	}
	void pushEnemy(float x, float y, float w, float h, float speed, float health) {
		_enemy->push_back(new Enemy(x, y, w, h, speed, health));
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

private:
	std::vector<Hero*>  *_hero;
	std::vector<Enemy*> *_enemy;
};

#endif