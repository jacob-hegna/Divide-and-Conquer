#ifndef _ENGINE_H
#define _ENGINE_H

#include <GLFW/glfw3.h>

#include "../../window/window.h"

namespace Mode {
	class Engine {
	public:
		Engine(void) {
			//Nothing to do here...
		}

		Engine(Window *window, void (*_init)(void**), void (*logic)(Window*, void*), void (*render)(void*), void *data = nullptr) {
			init(window, _init, logic, render);
		}

		~Engine(void) {
			
		}

		void init(Window *window, void(*_init)(void**), void (*logic)(Window*, void*), void (*render)(void*), void *data = nullptr);

		void use(void);

		template <class T>
		static void setData(void **data, T* t) {
			if(t != nullptr) *data = t;
		}

		template <class T>
		static T* getData(void *data) {
			return static_cast<T*>(data);
		}

		double getTime(void) {
			return _totalTime;
		}

	private:
		Window *_window;

		// Function pointers
		void (*_logic)(Window*, void*);
		void (*_render)(void*);

		// Some of the scenes might
		// require an fps counter
		float _avFps;
		double _totalTime;
		double _lastTime;

		// Misc data storage
		// This can store a pointer to a stuct
		// where you can store data to use
		void *_data;
	};
};

#endif