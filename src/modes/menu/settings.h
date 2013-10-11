/*************************************************************************
 * Divide and Conquer - settings.h                                       *
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

#ifndef _SETTINGS_H
#define _SETTINGS_H

#include <string>
#include <functional>

#include "../engine/engine.h"
#include "../modes.h"
#include "../../media/font.h"
#include "../../util/util.h"

namespace SettingsMenu {
	extern std::string options[];

	extern int select;
	extern bool leftBuf, rightBuf,
	            upBuf,   downBuf;
	            
	void logic(Mode::Engine*);
	void render(Mode::Engine*);
}

#endif