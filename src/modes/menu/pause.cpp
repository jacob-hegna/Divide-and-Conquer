#include "pause.h"

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
	if((engine->getWindow()->isJoy()) ? engine->getWindow()->getJoyButton(14) : 
		(engine->getWindow()->getKey(GLFW_KEY_SPACE) || engine->getWindow()->getKey(GLFW_KEY_ENTER))) {
		switch(PauseMenu::select) {
			case 0:
				engine->switch_();
				globalGameMode = GAME_LOOP;
				break;
			case 1:
				engine->switch_();
				globalGameMode = SETTINGS_MENU;
				break;
			case 2:
				engine->getWindow()->close();
				break;
		}
	}

	bufFunc((engine->getWindow()->isJoy()) ? engine->getWindow()->getJoyButton(4) : 
			engine->getWindow()->getKey(GLFW_KEY_W),
			&PauseMenu::wBuf,
			[] (int *select, void* v) {if(*select < 2) ++*select;},
			&PauseMenu::select, nullptr);
	
	bufFunc((engine->getWindow()->isJoy()) ? engine->getWindow()->getJoyButton(6) :
			engine->getWindow()->getKey(GLFW_KEY_S),
			&PauseMenu::sBuf,
			[] (int *select, void *v) {if(*select > 0) --*select;},
			&PauseMenu::select, nullptr);

	bufFunc((engine->getWindow()->isJoy()) ? engine->getWindow()->getJoyButton(3) :
			engine->getWindow()->getKey(GLFW_KEY_ESCAPE),
			&PauseMenu::pauseBuf,
			[] (GameModeType *mode, Mode::Engine *engine) {*mode = GAME_LOOP;engine->switch_();},
			&globalGameMode, engine);
}

void PauseMenu::render(Mode::Engine *engine) {
	Font::print("Paused", engine->getWindow()->getW()-135, engine->getWindow()->getH()-35);
	for(int i = 0; i < ARRAY_SIZE(PauseMenu::options); ++i) {
		Font::print((select==i) ? PauseMenu::options[i] + "*" : PauseMenu::options[i],
					15, 
					engine->getWindow()->getH() - (15+50*i));
	}
}