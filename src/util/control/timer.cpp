/*************************************************************************
 * Divide and Conquer - timer.cpp                                        *
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

#include "timer.h"

void Timer::init( double (*timerFunc)(void) ) {
	_timerFunc = timerFunc;
	_start = _timerFunc();
}

void Timer::update( void ) {
	_total.push_back(_timerFunc() - _start);
	_start = _timerFunc();
}

double Timer::getTime(void) {
	float sum = 0.f;
	for(int i = 0; i < _total.size(); ++i) {
		sum += _total.at(i);
	}
	return sum;
}

void Timer::setInstant( void ) {
	_instStart = _timerFunc();
}

double Timer::getInstant( void ) {
	return _timerFunc() - _instStart;
}

void Timer::reset( void ) {
	_start = _timerFunc();
}

void Timer::pause(void) {

}

void Timer::unpause(void) {
	_start = _timerFunc();
}