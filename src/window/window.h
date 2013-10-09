#ifndef _WINDOW_H
#define _WINDOW_H

#include <string>
#include <fstream>
#include <sys/stat.h>
#include <iostream>

#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>

#include <rapidxml/rapidxml.hpp>
#include <rapidxml/rapidxml_utils.hpp>

#include "../utilities/joystick.h"

class Window
{
public:
	Window(void) {
		// Nothing to do here...
	}

	~Window(void);

	void free(void);

	static int initGLFW(void) {
		if(!glfwInit()) {
			return -1;
		}
		return 0;
	}

	static void deinitGLFW(void) {
		glfwTerminate();
	}

	int init(void);

	void render(void) {
		glfwSwapBuffers(_window);
	}

	void clear(void);

	// If you need to do variable printing
	FILE** getFile(void) {
		return &_outputFile;
	}

	void setKeyCallback(void (*keyCallBack)(GLFWwindow *window, int key, int scan, int action, int mods)) {
		glfwSetKeyCallback(_window, keyCallBack);
	}

	bool getKey(int key) {
		return (glfwGetKey(_window, key) == GLFW_PRESS);
	}

	float getJoyPos(int i) {
		return _joy.getPos(i);
	}
	float getJoyButton(int i) {
		return _joy.getButton(i);
	}
	bool isJoy(void) {
		return _inputType==JOYSTICK;
	}

	GLFWwindow* getWindow(void) {
		return _window;
	}

	bool shouldClose(void) {
		return (glfwWindowShouldClose(_window) == GL_TRUE);
	}

	void close(void) {
		glfwSetWindowShouldClose(_window, GL_TRUE);
	}

	int getX(void) {
		return _x;
	}

	int getY(void) {
		return _y;
	}

	int getW(void) {
		return _w;
	}

	int getH(void) {
		return _h;
	}

	void incFrames(void) {
		++_frames;
	}

private:
	GLFWwindow *_window;
	Joystick    _joy;
	enum {
		KEYBOARD,
		JOYSTICK
	} _inputType;

	std::string _title;
	int _x, _y;
	int _w, _h;
	bool _fc;
	int _aa;

	FILE* _outputFile;

	int  _frames;
	float _time,
		 _stime;

	struct
	{
		float r, g, b;
	} _clearColor;
};

#endif
