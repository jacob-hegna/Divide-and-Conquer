#include "pause.h"
#include "../modes.h"

#include "../../media/font/glfont.h"

void PauseMenu::init(void **data) {

}

void PauseMenu::logic(Window *window, void *data) {
	if(window->getKey(GLFW_KEY_ESCAPE)) {
		globalGameMode = GAME_LOOP;
	}
}

void PauseMenu::render(void *data) {
	glPrintf("Paused", "media/fonts/largeArial.glf", 10, 10);
}