/*************************************************************************
 * Divide and Conquer - font.h                                           *
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

#ifndef _FONT_H
#define _FONT_H

#include <string>
#include <GLFW/glfw3.h>

#ifndef _WIN32
#include <oglft/OGLFT.h>
#endif

namespace Font {
#ifndef _WIN32
    extern OGLFT::Monochrome *face;
#endif
    void init(void);
    void print(std::string, float, float);
    void deinit(void);
};

#endif
