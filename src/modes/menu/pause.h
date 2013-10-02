#ifndef _PAUSE_H
#define _PAUSE_H

#include <string>

#include "../engine/engine.h"

namespace PauseMenu {
	extern bool pauseBuf;

	extern std::string options[];
	extern int         select;
	extern bool        wBuf;
	extern bool        sBuf;

	void init(Mode::Engine*);
	void logic(Mode::Engine*);
	void render(Mode::Engine*);
};

#endif