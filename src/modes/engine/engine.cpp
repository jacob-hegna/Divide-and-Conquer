#include "engine.h"

void Mode::Engine::init(Window *window, void (*_init)(void**), void (*logic)(Window*, void*), void (*render)(void*), void *data) {
	_window = window;
	_logic  = logic;
	_render = render;

	if(_init != nullptr) _init(&_data);

	_totalTime = 0;
}

void Mode::Engine::use(void) {
	_lastTime = glfwGetTime();

	glPushMatrix();
	_window->clear();

	_logic(_window, _data);
	_render(_data);

	_window->render();

	glPopMatrix();
	glfwPollEvents();

	_totalTime += glfwGetTime() - _lastTime;
}