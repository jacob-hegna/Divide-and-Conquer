#ifndef _PAUSE_H
#define _PAUSE_H

#include "../engine/engine.h"

namespace PauseMenu {
	void init(Mode::Engine*);
	void logic(Mode::Engine*);
	void render(Mode::Engine*);
};

#endif