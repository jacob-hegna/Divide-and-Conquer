#include "pause.h"
#include "../modes.h"

#include "../../media/font/glfont.h"

void PauseMenu::init(Mode::Engine *engine) {

}

void PauseMenu::logic(Mode::Engine *engine) {
	if(engine->getWindow()->getKey(GLFW_KEY_ESCAPE)) {
		globalGameMode = GAME_LOOP;
	}
}

void PauseMenu::render(Mode::Engine *engine) {
	glPrintf("Paused", "media/fonts/largeArial.glf", 10, 10);
}