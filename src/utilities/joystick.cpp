#include "joystick.h"

Joystick::Joystick(void) {

}

Joystick::~Joystick(void) {

}

bool Joystick::init(void) {
	for(int i = 0; i < 16; ++i) {
		if(glfwJoystickPresent(i) == GL_TRUE) {
			_joyNum = i;
			return true;
		}
	}
	return false;
}

const float Joystick::getPos(int num) {
	const float *pos;
	int *amt;
	pos = glfwGetJoystickAxes(_joyNum, amt);
	return (num <= *amt) ? pos[num] : -1.f;
}

const unsigned char Joystick::getButton(int num) {
	const unsigned char* state;
	int *amt;
	state = glfwGetJoystickButtons(_joyNum, amt);
	return (num <= *amt) ? state[num] : 0;
} 