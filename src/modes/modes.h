#ifndef _MODES_H
#define _MODES_H

#include "../window/window.h"

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