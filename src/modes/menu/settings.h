#ifndef _SETTINGS_H
#define _SETTINGS_H

#include <string>
#include <functional>

#include "../engine/engine.h"
#include "../modes.h"
#include "../../media/font.h"
#include "../../util/util.h"

namespace SettingsMenu {
	extern std::string options[];

	extern int select;
	extern bool leftBuf, rightBuf,
	            upBuf,   downBuf;
	            
	void logic(Mode::Engine*);
	void render(Mode::Engine*);
}

#endif