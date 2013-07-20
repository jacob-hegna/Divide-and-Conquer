//Standard headers
#include <Windows.h>
#include <ctime>

//Project headers
#include "window\window.h"
#include "modes\modes.h"


int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow)
{
	Window::initGLFW();
	Window window("Divide and Conquer", 50, 50);
	window.setKeyCallback(keyCall);

	srand(time(0));
	gameModes(&window);

	window.free();
	Window::deinitGLFW();
	return 0;
}
