#ifndef _WINDOW_H
#define _WINDOW_H

#include <string>

#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>

//Functions for project
void keyCall(GLFWwindow* window, int key, int scancode, int action, int mods);

// Standard class
class Window
{
public:
	Window(void) {
		// Nothing to do here...
	}

	Window(std::string title,
		   int x, int y, 
		   int w = 800, int h = 600,
		   int aa = 16,
		   float r = 1.f,
		   float g = 1.f,
		   float b = 1.f);

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

	int init(std::string title,
		      int x, int y, 
		      int w = 800, int h = 600,
		      int aa = 16,
		      float r = 1.f,
		      float g = 1.f,
		      float b = 1.f);

	void render(void) {
		glfwSwapBuffers(_window);
	}

	void clear(void);

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

	struct
	{
		float r, g, b;
	} _clearColor;
};

#endif