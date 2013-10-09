#include "joystick.h"

Joystick::Joystick(void) {
	_joyNum = 0;
	_exists = false;
}

Joystick::~Joystick(void) {

}

bool Joystick::init(void) {
	for(int i = 0; i < 16; ++i) {
		if(set(i)) return true;
	}
	return false;
}

bool Joystick::set(int i) {
	if(glfwJoystickPresent(i) == GL_TRUE) {
		_joyNum = i;
		_exists = true;
		return true;
	} else {
		return false;
	}
}

const float Joystick::getPos(int num) {
	const float *pos = nullptr;
	      int   amt  = 0;
	pos = glfwGetJoystickAxes(_joyNum, &amt);
	return (num <= amt && amt != 0) ? pos[num] : -1.f;
}

const unsigned char Joystick::getButton(int num) {
	const unsigned char* state;
		  int 	   amt;
	state = glfwGetJoystickButtons(_joyNum, &amt);
	return (num <= amt) ? state[num] : 0;
} 