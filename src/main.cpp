// Standard headers
#include <ctime>
#include <cstdlib>
#include <cstdio>

// Project headers
#include "window/window.h"
#include "modes/modes.h"

#ifdef _WIN32
#include <Windows.h>
int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow)
#else
int main(int argc, char *argv[])
#endif
{
	if(Window::initGLFW() != 0) {
		return -1;
	}
	
	Window* window(new Window);
	window->init();

	srand(time(0));
	gameModes(window);

	delete window;

	Window::deinitGLFW();
	return 0;
}
