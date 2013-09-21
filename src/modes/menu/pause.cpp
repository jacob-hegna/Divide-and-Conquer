#include "pause.h"
#include "../modes.h"

#include "../../media/font.h"

bool PauseMenu::pauseBuf = true;

void PauseMenu::init(Mode::Engine *engine) {

}

void PauseMenu::logic(Mode::Engine *engine) {
	if(engine->getWindow()->getKey(GLFW_KEY_Q)) {
		engine->getWindow()->close();
	}

	if(engine->getWindow()->getKey(GLFW_KEY_ESCAPE)) {
		if(!PauseMenu::pauseBuf) {
			globalGameMode = GAME_LOOP;
			PauseMenu::pauseBuf = true;
		}
	} else {
		PauseMenu::pauseBuf = false;
	}
}

void PauseMenu::render(Mode::Engine *engine) {
	Font::print("Paused", 15, 39);
}