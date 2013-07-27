#include "engine.h"

void Mode::Engine::init(Window *window, void (*_init)(Engine*), void (*logic)(Engine*), void (*render)(Engine*), void (*free)(Engine*)) {
	_window = window;
	_logic  = logic;
	_render = render;
	_free   = free;

	if(_init != nullptr) _init(this);

	_timer.init(glfwGetTime);
	_frames = 0;
}

void Mode::Engine::use(void) {
	glPushMatrix();
	_window->clear();

	_logic(this);
	_render(this);

	_window->render();

	glPopMatrix();
	glfwPollEvents();
	++_frames;
}