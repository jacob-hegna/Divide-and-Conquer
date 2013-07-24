#include "gameLoop.h"
#include "../modes.h"
#include "../engine/engine.h"

void GameLoop::init(Mode::Engine *engine) {
	engine->setData(new Actors(0, 0));
}

void GameLoop::logic(Mode::Engine *engine) {
	Actors *actors = engine->getData<Actors>();
	actors->hero->move(engine->getWindow());
	for(int i = 0; i < actors->enemyAmt; ++i) {
		actors->enemy[i]->move(actors->hero);
	}

	if(engine->getWindow()->getKey(GLFW_KEY_ESCAPE)) {
		//globalGameMode = PAUSE_MENU;
	}
}

void GameLoop::render(Mode::Engine *engine) {
	Actors *actors = engine->getData<Actors>();
	
	glPrintf((int)engine->getFps(), "media/fonts/arial.glf", 10, 10);

	// HUD code goes above this line
	GameLoop::camera(actors->hero);
	// Game code goes below this line

	actors->hero->render();
	for(int i = 0; i < actors->enemyAmt; ++i) {
		actors->enemy[i]->render();
	}
}

void GameLoop::camera(Hero *hero) {
	float x, y;
	hero->getCenter(&x, &y);
	glTranslatef(400-x, 300-y, 0.f);
}