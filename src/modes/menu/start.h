#ifndef _START_H
#define _START_H

#include <GLFW/glfw3.h>

#include "../../window/window.h"

namespace StartMenu {
	void init(void **data);
	void logic(Window *window, void *data);
	void render(void *data);
};

#endif