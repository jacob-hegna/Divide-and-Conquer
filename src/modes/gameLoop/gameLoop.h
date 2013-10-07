#ifndef _GAMELOOP_H
#define _GAMELOOP_H

#include "../engine/engine.h"
#include "../../window/window.h"
#include "../../utilities/util.h"
#include "../modes.h"
#include "../../actor/actors.h"

#include <cstdlib>
#include <string>

#ifndef _WIN32
#include <boost/lexical_cast.hpp>
#endif

namespace GameLoop {
	extern bool qBuf, pauseBuf;

	void init(Mode::Engine* engine);
	void logic(Mode::Engine* engine);
	void render(Mode::Engine* engine);
	void free(Mode::Engine* engine);
	void camera(Mode::Engine*);
}

#endif
