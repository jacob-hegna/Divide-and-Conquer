/*************************************************************************
 * Divide and Conquer - engine.h                                         *
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

#ifndef _ENGINE_H
#define _ENGINE_H

#include <GLFW/glfw3.h>
#include <string>

#include "../../window/window.h"
#include "../../media/font.h"
#include "../../util/util.h"

namespace Mode {
	// This class controls any main section of game function
	// Things like the game loop, the start menu, the pause menu,
	// and the settings menu are controlled here
	class Engine {
	public:
		Engine(void) {
			//Nothing to do here...
		}

		Engine(Window *window, void (*_init)(Engine*), void (*logic)(Engine*), void (*render)(Engine*), void (*free)(Engine*), const char* name) {
			init(window, _init, logic, render, free, name);
		}

		~Engine(void) {
			free();
		}
		void free(void) {
			if(_free != nullptr) _free(this);
		}

		void init(Window *window, void(*_init)(Engine*), void (*logic)(Engine*), void (*render)(Engine*), void (*free)(Engine*), const char* name);

		void use(void);

		// Have to use the underscore so it is a legit name
		void switch_(void) {
			_timer.pause();
			_switch = true;
		}

		template <class T>
		void setData(T* t) {
			if(t != nullptr) {
				_data = t;
			}
		}

		template <class T>
		T* getData() {
			return static_cast<T*>(_data);
		}

		Window* getWindow(void) {
			return _window;
		}

		float getTime(void) {
			return _timer.getTime();
		}
		int getFrames(void) {
			return _frames;
		}

		double getFps(void) {
			_timer.update();
			return (_frames > 10) ? _frames/_timer.getTime() : 10;
		}
		double getInstFps(void) {
			return (_instFps > 5) ? _instFps : 5;
		}

	private:
		Window *_window;

		const char* _name;

		// Function pointers
		void (*_logic)(Engine*);
		void (*_render)(Engine*);
		void (*_free)(Engine*);

		/* Every engine will have these functions
		* void init(Engine*) {
		*     // This will initialize anything you need for that scene
		* }
		* 
		* void logic(Engine*) {
		*     // This does any math/logic needed for the scene
		* }
		* 
		* void render(Engine*) {
		*     // This ONLY renders things to the screen
		* }
		* 
		* void free(Engine*) {
		*     // This frees any data allocated in void init(Engine*)
		* }
		*/	

		// Misc data storage
		// This can store a pointer to a stuct
		// where you can store data to use
		void *_data;

		// Timer is used for fps
		Timer _timer;
		int _frames;
		int _lastFrame;
		float _instFps;

		// Used basically only for the timer
		bool _switch;
	};
};

#endif