#include "gameLoop.h"

void GameLoop::init(Mode::Engine *engine) {
	Actors *actors = new Actors;
	actors->pushHero(0, 0, 75, 75, 325.f, 100);
	for(int i = 0; i < 5; ++i) {
		actors->pushEnemy(randF(-400, 400), randF(-300, 300), 75, 75, randF(130.f, 292.5f), 100, 10);
	}
	engine->setData<Actors>(actors);
}

void GameLoop::logic(Mode::Engine *engine) {
	Actors *actors = engine->getData<Actors>();
	for(int i = 0; i < actors->getHeroAmt(); ++i) {
		actors->getHero(i)->move(engine);
		
		if(actors->getHero(i)->getDead()) {
			std::vector<Hero*> tempVec = *actors->getHeros();
			actors->getHeros()->clear();
			for(int j = 0; j < tempVec.size(); ++j) {
				if(j != i) {
					actors->getHeros()->push_back(tempVec.at(j));
				}
			}
			tempVec.clear();
		}
	}
	for(int i = 0; i < actors->getEnemyAmt(); ++i) {
		actors->getEnemy(i)->move(engine);

		if(actors->getEnemy(i)->getDead()) {
			std::vector<Enemy*> tempVec = *actors->getEnemies();
			actors->getEnemies()->clear();
			for(int j = 0; j < tempVec.size(); ++j) {
				if(j != i) {
					actors->getEnemies()->push_back(tempVec.at(j));
				}
			}
			tempVec.clear();
		}
	}

	if(engine->getWindow()->getKey(GLFW_KEY_Q) && actors->heroPoints > 0 && actors->getHeroAmt() < 4) {
		if(actors->getHeroAmt() != 2) actors->pushHero(actors->getHero(actors->getHeroAmt()-1)->getX(), actors->getHero(actors->getHeroAmt()-1)->getY() + 150, 75, 75, 325.f, 100);
		else                          actors->pushHero(actors->getHero(actors->getHeroAmt()-1)->getX() + 150, actors->getHero(actors->getHeroAmt()-1)->getY() - 150, 75, 75, 325.f, 100);
		--actors->heroPoints;
	}

	if(engine->getWindow()->getKey(GLFW_KEY_ESCAPE)) {
		globalGameMode = PAUSE_MENU;
	}
	if(actors->getHeros()->empty()) {
		engine->getWindow()->close();
	}
}

void GameLoop::render(Mode::Engine *engine) {
	Actors *actors = engine->getData<Actors>();
	
	// fps
	glPrintf("l", 10, 10, "media/fonts/Liberation.ttf", 12);

	// kill count
	//glPrintf(actors->heroKills, "media/fonts/largeArial.glf", 10, 520);

	// points
	//glPrintf(actors->heroPoints, "media/fonts/largeArial.glf", 10, 560);

	// HUD code goes above this line
	GameLoop::camera(engine);
	// Game code goes below this line

	for(int i = 0; i < actors->getHeroAmt(); ++i) {
		actors->getHero(i)->render();
	}
	for(int i = 0; i < actors->getEnemyAmt(); ++i) {
		actors->getEnemy(i)->render();
	}
}

void GameLoop::free(Mode::Engine *engine) {
	Actors *actors = engine->getData<Actors>();
	for(int i = 0; i < actors->getHeroAmt(); ++i) {
		actors->getHero(i)->free();
	}
}

void GameLoop::camera(Mode::Engine *engine) {
	int heroNum = engine->getData<Actors>()->getHeroAmt();
	float x     = 0, 
		  y     = 0,
		  tempX = 0,
		  tempY = 0;
	for(int i = 0; i < heroNum; ++i) {
		engine->getData<Actors>()->getHero(i)->getCenter(&tempX, &tempY);
		x += tempX;
		y += tempY;
	}
	x /= heroNum;
	y /= heroNum;
	glTranslatef(400-x, 300-y, 0.f);
	engine->getData<Actors>()->camX = x;
	engine->getData<Actors>()->camY = y;
}