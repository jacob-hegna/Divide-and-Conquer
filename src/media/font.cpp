/*************************************************************************
 * Divide and Conquer - font.cpp                                         *
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

#include "font.h"

#ifndef _WIN32
OGLFT::Monochrome *Font::face = nullptr;
#endif

void Font::init(void) {
#ifndef _WIN32
    face = new OGLFT::Monochrome("media/arial.ttf", 24);
    face->setForegroundColor(0,0,0);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
#endif
}  

void Font::print(std::string data, float x, float y) {
#ifndef _WIN32
    face->draw(x, y, data.c_str());
#endif
}

void Font::deinit(void) {
#ifndef _WIN32
    delete face;
#endif
}
