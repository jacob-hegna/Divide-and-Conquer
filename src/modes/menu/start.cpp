#include "start.h"
#include "../modes.h"

#include "../../media/font/glfont.h"

void StartMenu::init(void **data) {

}

void StartMenu::logic(Window *window, void *data) {
	if(window->getKey(GLFW_KEY_SPACE)) {
		globalGameMode = GAME_LOOP;
	}
}

void StartMenu::render(void *data) {
	glPrintf("Start", "media/fonts/largeArial.glf", 10, 10);
}