/*************************************************************************
 * Divide and Conquer - guns.h                                           *
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

#ifndef _GUNS_H
#define _GUNS_H

#include <string>

const int GUN_AMT = 4;
struct Gun {
	std::string name;
    float speed;
    int bW, bH;
    float damage;
    float delay;
	float acc;
};

static const Gun guns[] = {
	// This goes in the same order as the struct declaration, obviously
	{"Pistol",   650,  4,  4,  20,    -1,  .1f},
	{"Gatling",  650,  3,  3,   1, .001f,  .5f},
	{"Sniper",  1000,  8,  8,  65,    -1, .05f},
	{"RPG",      550, 25, 25, 150,    -1, .15f}
};

#endif