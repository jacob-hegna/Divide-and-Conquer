#include "pause.h"
#include "../modes.h"

#include "../../media/font.h"
#include "../../utilities/array_size.h"

bool PauseMenu::pauseBuf = true;
std::string PauseMenu::options[3] = {
	"Resume",
	"Settings",
	"Quit"
};
int PauseMenu::select = 0;
bool PauseMenu::wBuf = true;
bool PauseMenu::sBuf = true;

void PauseMenu::init(Mode::Engine *engine) {

}

void PauseMenu::logic(Mode::Engine *engine) {
	if(engine->getWindow()->isJoy()) {
		// Need to replace keyboard code with joystick code
		if(engine->getWindow()->getJoyButton(14) &&
			PauseMenu::select == 2) {
			engine->getWindow()->close();
		}
		if(engine->getWindow()->getJoyButton(14)  &&
			PauseMenu::select == 0) {
			globalGameMode = GAME_LOOP;
		}

		if(engine->getWindow()->getJoyButton(4)) {
			if(!PauseMenu::wBuf) {
				if(PauseMenu::select < 2) ++PauseMenu::select;
				PauseMenu::wBuf = true;
			}
		} else {
			PauseMenu::wBuf = false;
		}
		if(engine->getWindow()->getJoyButton(6)) {
			if(!PauseMenu::sBuf) {
				if(PauseMenu::select > 0) --PauseMenu::select;
				PauseMenu::sBuf = true;
			}
		} else {
			PauseMenu::sBuf = false;
		}

		if(engine->getWindow()->getJoyButton(3)) {
			if(!PauseMenu::pauseBuf) {
				globalGameMode = GAME_LOOP;
				PauseMenu::pauseBuf = true;
			}
		} else {
			PauseMenu::pauseBuf = false;
		}
	} else {
		if(engine->getWindow()->getKey(GLFW_KEY_SPACE) ||
			engine->getWindow()->getKey(GLFW_KEY_ENTER) &&
			PauseMenu::select == 2) {
			engine->getWindow()->close();
		}
		if(engine->getWindow()->getKey(GLFW_KEY_SPACE) ||
			engine->getWindow()->getKey(GLFW_KEY_ENTER) &&
			PauseMenu::select == 0) {
			globalGameMode = GAME_LOOP;
		}

		if(engine->getWindow()->getKey(GLFW_KEY_W)) {
			if(!PauseMenu::wBuf) {
				if(PauseMenu::select < 2) ++PauseMenu::select;
				PauseMenu::wBuf = true;
			}
		} else {
			PauseMenu::wBuf = false;
		}
		if(engine->getWindow()->getKey(GLFW_KEY_S)) {
			if(!PauseMenu::sBuf) {
				if(PauseMenu::select > 0) --PauseMenu::select;
				PauseMenu::sBuf = true;
			}
		} else {
			PauseMenu::sBuf = false;
		}

		if(engine->getWindow()->getKey(GLFW_KEY_ESCAPE)) {
			if(!PauseMenu::pauseBuf) {
				globalGameMode = GAME_LOOP;
				PauseMenu::pauseBuf = true;
			}
		} else {
			PauseMenu::pauseBuf = false;
		}
	}
}

void PauseMenu::render(Mode::Engine *engine) {
	Font::print("Paused", engine->getWindow()->getW()-135, engine->getWindow()->getH()-35);
	for(int i = 0; i < ARRAY_SIZE(PauseMenu::options); ++i) {
		Font::print((select==i) ? PauseMenu::options[i] + "*" : PauseMenu::options[i],
					15, 
					engine->getWindow()->getH() - (15+50*i));
	}
}