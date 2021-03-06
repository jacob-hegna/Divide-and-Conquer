#include "modes.h"

GameModeType globalGameMode = START_MENU;

void gameModes(Window *window) {
	Mode::Engine **engine = new Mode::Engine*[gameModeAmt];
	for(int i = 0; i < gameModeAmt; ++i) {
		engine[i] = static_cast<Mode::Engine*>(calloc(1, sizeof(Mode::Engine)));
	}

	// Start initialization of all the engine objects
	engine[GAME_LOOP]->init(window,     GameLoop::init,  GameLoop::logic,     GameLoop::render,     GameLoop::free, "Game Loop");
	engine[START_MENU]->init(window,    StartMenu::init, StartMenu::logic,    StartMenu::render,    nullptr, "Start Menu");
	engine[PAUSE_MENU]->init(window,    PauseMenu::init, PauseMenu::logic,    PauseMenu::render,    nullptr, "Pause Menu");
	engine[SETTINGS_MENU]->init(window, nullptr,         SettingsMenu::logic, SettingsMenu::render, nullptr, "Settings Menu");
	engine[GAME_OVER]->init(window,     nullptr,         nullptr,             GameOver::render,     nullptr, "Game Over");

    Font::init();
    
    do {
		engine[globalGameMode]->use();
	} while( !window->shouldClose() );

	for(int i = 0; i < gameModeAmt; ++i) {
		engine[i]->free();
		free(engine[i]);
	}

    Font::deinit();
	delete [] engine;
}
