/*************************************************************************
 * Divide and Conquer - modes.cpp                                        *
 * www.github.com/jacob-hegna/Divide-and-Conquer                         *
 * --------------------------------------------------------------------- *
 * Copyright 2013 Jacob Hegna.                                           *
 *                                                                       *
 * This file is a part of Divide and Conquer.                            *
 *                                                                       *
 * Divide and Conquer is free software: you can redistribute it          *
 * and/or modify it under the terms of the GNU General Public            *
 * License as published by the Free Software Foundation, either          *
 * version 3 of the License, or (at your option) any later version.      *
 *                                                                       *
 * This program is distributed in the hope that it will be useful,       *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                  *
 * See the GNU General Public License for more details.                  *
 *                                                                       *
 * You should have received a copy of the GNU General Public License     *
 * along with this program.  If not, see <http://www.gnu.org/licenses/>. *
 ************************************************************************/

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
