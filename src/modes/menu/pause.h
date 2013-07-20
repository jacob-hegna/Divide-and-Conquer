#ifndef _PAUSE_H
#define _PAUSE_H

#include "../../window/window.h"

namespace PauseMenu {
	void init(void **data);
	void logic(Window *window, void *data);
	void render(void *data);
};

#endif