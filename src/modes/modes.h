#ifndef _MODES_H
#define _MODES_H

#include "../window/window.h"

enum GameModeType {
	GAME_LOOP,
	START_MENU,
	PAUSE_MENU,
	GAME_OVER
};

extern GameModeType globalGameMode;

void gameModes(Window *window);

#endif