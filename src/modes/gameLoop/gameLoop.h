#ifndef _GAMELOOP_H
#define _GAMELOOP_H

#include "../engine/engine.h"
#include "../../window/window.h"
#include "../../util/util.h"
#include "../modes.h"
#include "../../actor/actors.h"

#include <cstdlib>
#include <string>

namespace GameLoop {
	extern bool qBuf, pauseBuf;
	extern bool leftBuf, rightBuf,
	            upBuf,   downBuf;

	void init(Mode::Engine* engine);
	void logic(Mode::Engine* engine);
	void render(Mode::Engine* engine);
	void free(Mode::Engine* engine);
	void camera(Mode::Engine*);
}

#endif
