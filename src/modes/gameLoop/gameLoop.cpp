#include "gameLoop.h"

void GameLoop::init(Mode::Engine *engine) {
	Actors *actors = new Actors;
	actors->pushHero(0, 0, 75, 75, 325.f, 100);
	for(int i = 0; i < 5; ++i) {
		actors->pushEnemy(randF(-400, 400), randF(-300, 300), 75, 75, randF(130.f, 292.5f), 100);
	}
	engine->setData<Actors>(actors);
}

void GameLoop::logic(Mode::Engine *engine) {
	Actors *actors = engine->getData<Actors>();
	for(int i = 0; i < actors->getHeroAmt(); ++i) {
		actors->getHero(i)->move(engine);
	}
	for(int i = 0; i < actors->getEnemyAmt(); ++i) {
		actors->getEnemy(i)->move(engine);
	}
	if(engine->getWindow()->getKey(GLFW_KEY_ESCAPE)) {
		//globalGameMode = PAUSE_MENU;
	}
}

void GameLoop::render(Mode::Engine *engine) {
	Actors *actors = engine->getData<Actors>();
	
	glPrintf((int)engine->getFps(), "media/fonts/arial.glf", 10, 10);

	// HUD code goes above this line
	GameLoop::camera(actors->getHero(0));
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

void GameLoop::camera(Hero *hero) {
	float x, y;
	hero->getCenter(&x, &y);
	glTranslatef(400-x, 300-y, 0.f);
}