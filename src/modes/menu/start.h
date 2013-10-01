#ifndef _START_H
#define _START_H

#include <GLFW/glfw3.h>

#include "../engine/engine.h"
#include "../../window/window.h"

namespace StartMenu {
	void init(Mode::Engine*);
	void logic(Mode::Engine*);
	void render(Mode::Engine*);
};

#endif