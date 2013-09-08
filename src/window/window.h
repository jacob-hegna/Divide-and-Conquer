#ifndef _WINDOW_H
#define _WINDOW_H

#include <string>
#include <fstream>
#include <sys/stat.h>
#include <iostream>

#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>

#include "../media/rapidxml/rapidxml.hpp"
#include "../media/rapidxml/rapidxml_utils.hpp"

class Window
{
public:
	Window(void) {
		// Nothing to do here...
	}

	Window(std::string path);

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

	int init(std::string path);

	void render(void) {
		glfwSwapBuffers(_window);
	}

	void clear(void);

	void print(std::string text) {
		fprintf(_outputFile, text.c_str());
	}

	void setKeyCallback(void (*keyCallBack)(GLFWwindow *window, int key, int scan, int action, int mods)) {
		glfwSetKeyCallback(_window, keyCallBack);
	}

	bool getKey(int key) {
		return (glfwGetKey(_window, key) == GLFW_PRESS);
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

private:
	GLFWwindow *_window;

	std::string _title;
	int _x, _y;
	int _w, _h;
	int _aa;

	FILE* _outputFile;

	struct
	{
		float r, g, b;
	} _clearColor;
};

#endif
