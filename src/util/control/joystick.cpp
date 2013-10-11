/*************************************************************************
 * Divide and Conquer - joystick.cpp                                     *
 * www.github.com/jacob-hegna/Divide-and-Conquer                         *
 * --------------------------------------------------------------------- *
 * Copyright 2013 Jacob Hegna.                                           *
 *                                                                       *
 * This file is a part of Divide and Conquer.                            *
 *                                                                       *
 * Divide and Conquer is free software: you can redistribute it          *
 * and/or modify it under the terms of the GNU General Public            *
 * License as published by the Free Software Foundation, either          *
 * version 3 of the License, or (at your option) any later version.      *
 *                                                                       *
 * This program is distributed in the hope that it will be useful,       *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                  *
 * See the GNU General Public License for more details.                  *
 *                                                                       *
 * You should have received a copy of the GNU General Public License     *
 * along with this program.  If not, see <http://www.gnu.org/licenses/>. *
 ************************************************************************/

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