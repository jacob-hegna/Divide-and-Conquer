#include "gameOver.h"

void GameOver::render(Mode::Engine *engine) {
	glColor4f(0.f, 0.f, 0.f, 1.f);
	glBegin(GL_QUADS);
		glVertex2d(0, 0);
		glVertex2d(engine->getWindow()->getW(), 0);
		glVertex2d(engine->getWindow()->getW(), engine->getWindow()->getH());
		glVertex2d(0, engine->getWindow()->getH());
	glEnd();
	if(engine->getWindow()->getKey(GLFW_KEY_SPACE) || engine->getWindow()->getKey(GLFW_KEY_ESCAPE)) {
		engine->getWindow()->close();
	}
}