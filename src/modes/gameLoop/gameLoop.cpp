#include "gameLoop.h"
#include "../modes.h"
#include "../engine/engine.h"
using namespace Mode;


float RandomFloat(float a, float b) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}

void GameLoop::init(void **data) {
	Engine::setData(data, new Actors(0, 0));
}

void GameLoop::logic(Window *window, void *data) {
	Actors *actors = Engine::getData<Actors>(data);
	actors->hero->move(window);
	for(int i = 0; i < actors->enemyAmt; ++i) {
		actors->enemy[i]->move(actors->hero);
	}

	GameLoop::camera(actors->hero);

	if(window->getKey(GLFW_KEY_ESCAPE)) {
		globalGameMode = PAUSE_MENU;
	}
}

void GameLoop::render(void *data) {
	Actors *actors = Engine::getData<Actors>(data);
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