/*************************************************************************
 * Divide and Conquer - settings.cpp                                     *
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

#include "settings.h"

std::string SettingsMenu::options[3] = {
	"Window width",
	"Window height",
	"Input type"
};

int SettingsMenu::select    = 0;

bool SettingsMenu::rightBuf = false;
bool SettingsMenu::leftBuf  = false;
bool SettingsMenu::upBuf    = false;
bool SettingsMenu::downBuf  = false;

void SettingsMenu::logic(Mode::Engine *engine) {
	bufFunc((engine->getWindow()->isJoy()) ? engine->getWindow()->getJoyButton(7) : 
											engine->getWindow()->getKey(GLFW_KEY_A),
		    &SettingsMenu::rightBuf, 
		    [] (Mode::Engine *engine, int select) {
		    	switch(select) {
		    		case 0:
		    			if(engine->getWindow()->getW() > 400) engine->getWindow()->setW(engine->getWindow()->getW()-50);
		    			break;
		    		case 1:
		    			if(engine->getWindow()->getH() > 300) engine->getWindow()->setH(engine->getWindow()->getH()-50);
		    			break;
		    		case 2:
		    			if(!engine->getWindow()->isJoy()) engine->getWindow()->setJoy(true);
		    			break;
		    	}
		    },
		    engine, SettingsMenu::select);

	bufFunc((engine->getWindow()->isJoy()) ? engine->getWindow()->getJoyButton(5) : 
											engine->getWindow()->getKey(GLFW_KEY_D),
		    &SettingsMenu::leftBuf,
		    [] (Mode::Engine *engine, int select) {
		    	switch(select) {
		    		case 0:
		    			if(engine->getWindow()->getW() < 1050) engine->getWindow()->setW(engine->getWindow()->getW()+50);
		    			break;
		    		case 1:
		    			if(engine->getWindow()->getH() < 800)  engine->getWindow()->setH(engine->getWindow()->getH()+50);
		    			break;
		    		case 2:
		    			if(engine->getWindow()->isJoy()) engine->getWindow()->setJoy(false);
		    			break;
		    	}
		    },
		    engine, SettingsMenu::select);

	bufFunc((engine->getWindow()->isJoy()) ? engine->getWindow()->getJoyButton(4) :
											engine->getWindow()->getKey(GLFW_KEY_W),
			&SettingsMenu::upBuf,
			[] (int *select, int size) {if(*select < size) ++*select;},
			&SettingsMenu::select, ARRAY_SIZE(SettingsMenu::options));

	bufFunc((engine->getWindow()->isJoy()) ? engine->getWindow()->getJoyButton(6) :
											engine->getWindow()->getKey(GLFW_KEY_S),
			&SettingsMenu::downBuf,
			[] (int *select, void* v) {if(*select > 0) --*select;},
			&SettingsMenu::select, nullptr);

	if((engine->getWindow()->isJoy()) ? engine->getWindow()->getJoyButton(13) != 0 :
		engine->getWindow()->getKey(GLFW_KEY_Q)) {
		engine->switch_();
		globalGameMode = PAUSE_MENU;
	}
}

void SettingsMenu::render(Mode::Engine *engine) {
	Font::print("Settings", engine->getWindow()->getW()-135, engine->getWindow()->getH()-35);
	for(int i = 0; i < ARRAY_SIZE(SettingsMenu::options); ++i) {
		Font::print((select==i) ? SettingsMenu::options[i] + "*" : SettingsMenu::options[i],
					15, 
					engine->getWindow()->getH() - (15+50*i));
					
		if(SettingsMenu::options[i] == "Window width") {
			Font::print(SSTR(engine->getWindow()->getW()),
				        300,
				        engine->getWindow()->getH() - (15+50*i));
		} else if(SettingsMenu::options[i] == "Window height") {
			Font::print(SSTR(engine->getWindow()->getH()),
				        300,
				        engine->getWindow()->getH() - (15+50*i));
		} else if(SettingsMenu::options[i] == "Input type") {
			Font::print((engine->getWindow()->isJoy()) ? "Joystick" : "Keyboard",
				        300,
				        engine->getWindow()->getH() - (15+50*i));
		}
	}
}