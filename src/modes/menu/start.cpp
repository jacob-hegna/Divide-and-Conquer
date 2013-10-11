/*************************************************************************
 * Divide and Conquer - start.cpp                                        *
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

#include "start.h"
#include "../modes.h"

#include "../../media/font.h"

void StartMenu::init(Mode::Engine *engine) {

}

void StartMenu::logic(Mode::Engine *engine) {
	if(engine->getWindow()->isJoy()) {
		if(engine->getWindow()->getJoyButton(14) != 0) {
			engine->switch_();
			globalGameMode = GAME_LOOP;
		}
	} else {
		if(engine->getWindow()->getKey(GLFW_KEY_SPACE)) {
			engine->switch_();
			globalGameMode = GAME_LOOP;
		}
	}
}

void StartMenu::render(Mode::Engine *engine) {
	Font::print("Divide and Conquer", 15, 39);
}