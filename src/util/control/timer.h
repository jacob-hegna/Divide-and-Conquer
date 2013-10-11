/*************************************************************************
 * Divide and Conquer - timer.h                                          *
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

#ifndef _TIMER_H
#define _TIMER_H

#include <vector>
#include <cstdio>

class Timer {
public:
	Timer( void ) {
		// nothing to do here...
	}

	Timer( double (*timerFunc)(void) ) {
		init(timerFunc);
	}

	~Timer( void ) {
		free();
	}

	void init( double (*_timerFunc)(void) );
	void update( void );
	void reset( void );

	void setInstant( void );
	double getInstant( void );

	void pause(void);
	void unpause(void);

	double getTime( void );

	void free( void ) {
		// nothing to free...
	}

private:
	float _start;
	std::vector<float> _total;

	double _instStart;

	double (*_timerFunc)(void);
};

#endif