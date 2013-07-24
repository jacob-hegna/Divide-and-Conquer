#include "start.h"
#include "../modes.h"

#include "../../media/font/glfont.h"

void StartMenu::init(Mode::Engine *engine) {

}

void StartMenu::logic(Mode::Engine *engine) {
	if(engine->getWindow()->getKey(GLFW_KEY_SPACE)) {
		globalGameMode = GAME_LOOP;
	}
}

void StartMenu::render(Mode::Engine *engine) {
	glPrintf("Start", "media/fonts/largeArial.glf", 10, 10);
}