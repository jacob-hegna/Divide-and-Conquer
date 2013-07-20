#include "window.h"

// Functions added for project
void keyCall(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	//if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        //glfwSetWindowShouldClose(window, GL_TRUE);
}


// Standard functions
Window::Window(std::string title,
			   int x, int y, 
		       int w, int h,
		       int aa,
		       float r, float g, float b)
{
	init(title, x, y, w, h, aa, r, g, b);
}

Window::~Window(void) {
	free();
}

void Window::free(void) {
	glfwDestroyWindow(_window);
}

int Window::init(std::string title,
				  int x, int y, 
		          int w, int h,
		          int aa,
		          float r, float g, float b)
{
	_title        = title;
	_x            = x;
	_y            = y;
	_w            = w;
	_h            = h;
	_aa           = aa;
	_clearColor.r = r;
	_clearColor.g = g;
	_clearColor.b = b;

	glfwWindowHint(GLFW_SAMPLES, _aa);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	
	_window = glfwCreateWindow(_w, _h, _title.c_str(), nullptr, nullptr);

	if(!_window) {
		glfwDestroyWindow(_window);
		return -1;
	}

	glfwSetWindowPos(_window, _x, _y);

	glfwMakeContextCurrent(_window);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glEnable(GL_TEXTURE_2D);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, _w, _h, 0);
	glClearColor(_clearColor.r,
				 _clearColor.g,
				 _clearColor.b,
				 1.f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	return 0;
}

void Window::clear(void) {
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);
}