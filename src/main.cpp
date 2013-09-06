//Standard headers
#include <ctime>
#include <cstdlib>
#include <cstdio>

//Project headers
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
	Window::initGLFW();
	Window window("Divide and Conquer", 50, 50);

	srand(time(0));
	gameModes(&window);

	window.free();
	Window::deinitGLFW();
	return 0;
}
