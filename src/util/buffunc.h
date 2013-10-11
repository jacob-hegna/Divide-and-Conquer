/*************************************************************************
 * Divide and Conquer - buffunc.cpp                                      *
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

#ifndef _BUFFUNC_H_
#define _BUFFUNC_H_

/* a typical call to this function will follow this structure:
 * bufFunc( a test statement,
 *          a pointer to the boolean that stores the buffer for the function,
 *          a lambda function, 
 *          and then the parameters to the lambda);
 */
template<class Func, class P1, class P2>
void bufFunc(bool condition, bool *buf, Func func, P1 p1, P2 p2) {
	if(condition) {
		if(!*buf) {
			func(p1, p2);
			*buf = true;
		}
	} else {
		*buf = false;
	}
}

#endif
