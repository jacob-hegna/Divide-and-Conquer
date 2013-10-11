/*************************************************************************
 * Divide and Conquer - joystick.h                                       *
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