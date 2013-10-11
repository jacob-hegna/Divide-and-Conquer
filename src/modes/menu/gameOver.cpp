/*************************************************************************
 * Divide and Conquer - gameOver.cpp                                     *
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

#include "gameOver.h"

void GameOver::render(Mode::Engine *engine) {
	glColor4f(0.f, 0.f, 0.f, 1.f);
	glBegin(GL_QUADS);
		glVertex2d(0, 0);
		glVertex2d(engine->getWindow()->getW(), 0);
		glVertex2d(engine->getWindow()->getW(), engine->getWindow()->getH());
		glVertex2d(0, engine->getWindow()->getH());
	glEnd();
	if((engine->getWindow()->isJoy()) ? engine->getWindow()->getJoyButton(13) != 0 :
		engine->getWindow()->getKey(GLFW_KEY_SPACE) || engine->getWindow()->getKey(GLFW_KEY_ESCAPE)) {
		engine->getWindow()->close();
	}
}