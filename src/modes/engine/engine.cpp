#include "engine.h"

void Mode::Engine::init(Window *window, void (*_init)(Engine*), void (*logic)(Engine*), void (*render)(Engine*), void (*free)(Engine*)) {
	_window = window;
	_logic  = logic;
	_render = render;
	_free   = free;

	if(_init != nullptr) _init(this);

	_timer.init(glfwGetTime);
	_frames = 0;
	_lastFrame = 0;
	_instFps = 60;
	_window->print("Creating engine object...\n");
}

void Mode::Engine::use(void) {
	if(_frames - _lastFrame >= 30) {
		if(_lastFrame >= 30) _instFps = 30/_timer.getInstant();
		_timer.setInstant();
		_lastFrame = _frames;
	}
	glLoadIdentity();
	//glPushMatrix();
	_window->clear();

    // glPrintf(boost::lexical_cast<std::string>((int)_instFps), 
    //			 24, 24, 10, 34, 0, 0, 0);

	if(_logic != nullptr) _logic(this);
	if(_render != nullptr) _render(this);

	_window->render();

	//glPopMatrix();
	glfwPollEvents();
	++_frames;
}
