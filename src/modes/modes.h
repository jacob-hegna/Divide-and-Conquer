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