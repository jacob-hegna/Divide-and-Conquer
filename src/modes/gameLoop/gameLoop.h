#ifndef _GAMELOOP_H
#define _GAMELOOP_H

#include "../engine/engine.h"
#include "../../window/window.h"
#include "../../utilities/util.h"
#include "../modes.h"
#include "../../actor/actors.h"


namespace GameLoop {
	void init(Mode::Engine* engine);
	void logic(Mode::Engine* engine);
	void render(Mode::Engine* engine);
	void free(Mode::Engine* engine);
	void camera(Hero*);
}

#endif