#include "modes.h"

#include "engine\engine.h"
#include "gameLoop\gameLoop.h"
#include "menu\start.h"
#include "menu\pause.h"

#include "../media/font/glfont.h"

GameModeType globalGameMode = START_MENU;

void gameModes(Window *window) {
	Mode::Engine engine[3];
	engine[GAME_LOOP].init(window, GameLoop::init, GameLoop::logic, GameLoop::render);
	engine[START_MENU].init(window, StartMenu::init, StartMenu::logic, StartMenu::render);
	engine[PAUSE_MENU].init(window, PauseMenu::init, PauseMenu::logic, PauseMenu::render);

	do {
		engine[globalGameMode].use();
	} while( !window->shouldClose() );
}