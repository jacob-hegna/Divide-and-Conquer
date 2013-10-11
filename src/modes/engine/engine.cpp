/*************************************************************************
 * Divide and Conquer - engine.cpp                                       *
 * www.github.com/jacob-hegna/Divide-and-Conquer                         *
 * --------------------------------------------------------------------- *
 * Copyright 2013 Jacob Hegna.                                           *
 *                                                                       *
 * This file is a part of Divide and Conquer.                            *
 *                                                                       *
 * Divide and Conquer is free software: you can redistribute it          *
 * and/or modify it under the terms of the GNU General Public            *
 * License as published by the Free Software Foundation, either          *
 * version 3 of the License, or (at your option) any later version.      *
 *                                                                       *
 * This program is distributed in the hope that it will be useful,       *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                  *
 * See the GNU General Public License for more details.                  *
 *                                                                       *
 * You should have received a copy of the GNU General Public License     *
 * along with this program.  If not, see <http://www.gnu.org/licenses/>. *
 ************************************************************************/

#include "engine.h"

void Mode::Engine::init(Window *window, void (*_init)(Engine*), void (*logic)(Engine*), void (*render)(Engine*), void (*free)(Engine*), const char* name) {
	_window = window;
	_logic  = logic;
	_render = render;
	_free   = free;

	if(_init != nullptr) _init(this);

	_timer.init(glfwGetTime);
	_frames = 0;
	_lastFrame = 0;
	_instFps = 60;
	_name = name;
}

void Mode::Engine::use(void) {
	if(_switch) {
		_timer.unpause();
		_switch = false;
	}
	_timer.update();

	if(_frames - _lastFrame >= 30) {
		if(_lastFrame >= 30) _instFps = 30/_timer.getInstant();
		_timer.setInstant();
		_lastFrame = _frames;
	}
	glLoadIdentity();
	//glPushMatrix();
	_window->clear();

	if(_logic != nullptr) _logic(this);
	if(_render != nullptr) _render(this);

	_window->render();

	//glPopMatrix();
	glfwPollEvents();
	++_frames;
	_window->incFrames();
}
