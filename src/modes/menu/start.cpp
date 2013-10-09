#include "start.h"
#include "../modes.h"

#include "../../media/font.h"

void StartMenu::init(Mode::Engine *engine) {

}

void StartMenu::logic(Mode::Engine *engine) {
	if(engine->getWindow()->isJoy()) {
		if(engine->getWindow()->getJoyButton(14) != 0) {
			globalGameMode = GAME_LOOP;
		}
	} else {
		if(engine->getWindow()->getKey(GLFW_KEY_SPACE)) {
			globalGameMode = GAME_LOOP;
		}
	}
}

void StartMenu::render(Mode::Engine *engine) {
	Font::print("Divide and Conquer", 15, 39);
}