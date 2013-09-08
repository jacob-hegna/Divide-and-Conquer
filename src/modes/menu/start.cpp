#include "start.h"
#include "../modes.h"

#include "../../media/font.h"

void StartMenu::init(Mode::Engine *engine) {

}

void StartMenu::logic(Mode::Engine *engine) {
	if(engine->getWindow()->getKey(GLFW_KEY_SPACE)) {
		globalGameMode = GAME_LOOP;
	}
}

#include <cstdio>

void StartMenu::render(Mode::Engine *engine) {
	//glPrintf("Start", 30, 30, "media/fonts/Liberation.ttf", 12);
}