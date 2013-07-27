#ifndef _ENGINE_H
#define _ENGINE_H

#include <GLFW/glfw3.h>
#include <cstdlib>

#include "../../window/window.h"
#include "../../media/font/glfont.h"
#include "../../utilities/timer.h"

namespace Mode {
	class Engine {
	public:
		Engine(void) {
			//Nothing to do here...
		}

		Engine(Window *window, void (*_init)(Engine*), void (*logic)(Engine*), void (*render)(Engine*), void (*free)(Engine*)) {
			init(window, _init, logic, render, free);
		}

		~Engine(void) {
			if(_free != nullptr) _free(this);
		}
		void free(void) {
			if(_free != nullptr) _free(this);
		}

		void init(Window *window, void(*_init)(Engine*), void (*logic)(Engine*), void (*render)(Engine*), void (*free)(Engine*));

		void use(void);

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

		double getFps(void) {
			_timer.update();
			return (_frames > 10) ? _frames/_timer.getTime() : 450;
		}

	private:
		Window *_window;

		// Function pointers
		void (*_logic)(Engine*);
		void (*_render)(Engine*);
		void (*_free)(Engine*);

		// Misc data storage
		// This can store a pointer to a stuct
		// where you can store data to use
		// TODO: figure out how to free it
		void *_data;

		// Timer is used for fps
		Timer _timer;
		int _frames;
	};
};

#endif