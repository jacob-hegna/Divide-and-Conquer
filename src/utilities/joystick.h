#ifndef _JOYSTICK_H
#define _JOYSTICK_H

#include <GLFW/glfw3.h>

class Joystick {
public:
	Joystick(void);
	~Joystick(void);

	bool init(void);
	bool set(int);
	const float getPos(int);
	const unsigned char getButton(int);

	bool exists(void) {
		return _exists;
	}

private:
	int _joyNum;
	bool _exists;
};

#endif