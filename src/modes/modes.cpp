#include "modes.h"

#include "engine/engine.h"
#include "gameLoop/gameLoop.h"
#include "menu/start.h"
#include "menu/pause.h"
#include "menu/gameOver.h"

#include "../media/font.h"

GameModeType globalGameMode = START_MENU;

void gameModes(Window *window) {
	Mode::Engine **engine = new Mode::Engine*[4];
	for(int i = 0; i < 4; ++i) {
		engine[i] = static_cast<Mode::Engine*>(calloc(1, sizeof(Mode::Engine)));
	}

	engine[GAME_LOOP]->init(window, GameLoop::init, GameLoop::logic, GameLoop::render, GameLoop::free);
	engine[START_MENU]->init(window, StartMenu::init, StartMenu::logic, StartMenu::render, nullptr);
	engine[PAUSE_MENU]->init(window, PauseMenu::init, PauseMenu::logic, PauseMenu::render, nullptr);
	engine[GAME_OVER]->init(window, nullptr, nullptr, GameOver::render, nullptr);

	do {
		engine[globalGameMode]->use();
	} while( !window->shouldClose() );

	for(int i = 0; i < 4; ++i) {
		engine[i]->free();
		free(engine[i]);
	}

	delete [] engine;
}