/*************************************************************************
 * Divide and Conquer - modes.h                                          *
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

#ifndef _MODES_H
#define _MODES_H

#include "../window/window.h"
#include "engine/engine.h"
#include "gameLoop/gameLoop.h"
#include "menu/start.h"
#include "menu/pause.h"
#include "menu/settings.h"
#include "menu/gameOver.h"

#include "../media/font.h"

enum GameModeType {
	GAME_LOOP,
	START_MENU,
	PAUSE_MENU,
	SETTINGS_MENU,
	GAME_OVER
};
static const int gameModeAmt = 5;

extern GameModeType globalGameMode;

void gameModes(Window *window);

#endif