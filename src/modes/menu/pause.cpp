#include "pause.h"
#include "../modes.h"

#include "../../media/font.h"

bool PauseMenu::pauseBuf = true;

void PauseMenu::init(Mode::Engine *engine) {

}

void PauseMenu::logic(Mode::Engine *engine) {
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
	//glPrintf("Paused", "media/fonts/largeArial.glf", 10, 10);
}