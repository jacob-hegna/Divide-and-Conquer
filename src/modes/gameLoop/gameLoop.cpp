/*************************************************************************
 * Divide and Conquer - gameLoop.cpp                                     *
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

#include "gameLoop.h"

#include "../../media/font.h"

bool GameLoop::qBuf     = false;
bool GameLoop::pauseBuf = false;

bool GameLoop::rightBuf = false;
bool GameLoop::leftBuf  = false;
bool GameLoop::upBuf    = false;
bool GameLoop::downBuf  = false;

void GameLoop::init(Mode::Engine *engine) {
	Actors *actors = new Actors;
	actors->pushHero(0, 0, 75, 75, 325.f, 100);
	for(int i = 0; i < 5; ++i) {
		actors->pushEnemy(randF(-400, 400), randF(-300, 300), 75, 75, randF(130.f, 292.5f), 100, 4);
	}
	engine->setData<Actors>(actors);
}

void GameLoop::logic(Mode::Engine *engine) {
	Actors *actors = engine->getData<Actors>();
	for(int i = 0; i < actors->getHeroAmt(); ++i) {
		actors->getHero(i)->move(engine);

		if(actors->getHero(i)->getDead()) {
			std::vector<Hero*> tempVec = *actors->getHeros();
			actors->getHeros()->clear();
			for(int j = 0; j < tempVec.size(); ++j) {
				if(j != i) {
					actors->getHeros()->push_back(tempVec.at(j));
				}
			}
			tempVec.clear();
		}
	}
	for(int i = 0; i < actors->getEnemyAmt(); ++i) {
		actors->getEnemy(i)->move(engine);

		if(actors->getEnemy(i)->getDead()) {
			actors->getEnemy(i)->init(randF(-400, 400), randF(-300, 300), 75, 75, randF(130.f, 292.5f), 100, 10);
		}
	}
	if(engine->getWindow()->isJoy()) {
		bufFunc(engine->getWindow()->getJoyButton(12) != 0,
				&GameLoop::qBuf,
				[] (Actors *actors, void *v) {
					if(actors->getHeroAmt() < 4) {
						if(actors->getHeroAmt() != 2) actors->pushHero(actors->getHero(actors->getHeroAmt()-1)->getX(), actors->getHero(actors->getHeroAmt()-1)->getY() + 150, 75, 75, 325.f, 100);
						else                          actors->pushHero(actors->getHero(actors->getHeroAmt()-1)->getX() + 150, actors->getHero(actors->getHeroAmt()-1)->getY() - 150, 75, 75, 325.f, 100);
						--actors->heroPoints;
					}
				},
				actors, nullptr);

		if(engine->getWindow()->getJoyButton(7) != 0) {
			for(int i = 0; i < actors->getHeroAmt(); ++i) {
				actors->getHero(i)->decType();
			}
		}
		if(engine->getWindow()->getJoyButton(5) != 0) {
			for(int i = 0; i < actors->getHeroAmt(); ++i) {
				actors->getHero(i)->incType();
			}
		}

		bufFunc(engine->getWindow()->getJoyButton(3) != 0,
				&GameLoop::pauseBuf,
				[] (Mode::Engine *engine, GameModeType *mode) {*mode=PAUSE_MENU;engine->switch_();},
				engine, &globalGameMode);
	} else {
		bufFunc(engine->getWindow()->getKey(GLFW_KEY_Q),
				&GameLoop::qBuf,
				[] (Actors *actors, void *v) {
					if(actors->getHeroAmt() < 4) {
						if(actors->getHeroAmt() != 2) actors->pushHero(actors->getHero(actors->getHeroAmt()-1)->getX(), actors->getHero(actors->getHeroAmt()-1)->getY() + 150, 75, 75, 325.f, 100);
						else                          actors->pushHero(actors->getHero(actors->getHeroAmt()-1)->getX() + 150, actors->getHero(actors->getHeroAmt()-1)->getY() - 150, 75, 75, 325.f, 100);
						--actors->heroPoints;
					}
				},
				actors, nullptr);

		for(int i = GLFW_KEY_1; i < GLFW_KEY_9; ++i) {
			if(engine->getWindow()->getKey(i)) {
				for(int j = 0; j < actors->getHeroAmt(); ++j) {
					actors->getHero(j)->setType(i-GLFW_KEY_1);
				}
			}
		}

		bufFunc(engine->getWindow()->getKey(GLFW_KEY_ESCAPE),
				&GameLoop::pauseBuf,
				[] (Mode::Engine *engine, GameModeType *mode) {*mode=PAUSE_MENU;engine->switch_();},
				engine, &globalGameMode);
	}

	if(actors->getHeros()->empty()) {
		engine->switch_();
		globalGameMode = GAME_OVER;
	}
}

void GameLoop::render(Mode::Engine *engine) {
	Actors *actors = engine->getData<Actors>();

#ifndef _WIN32
	Font::print(SSTR((int)engine->getInstFps()), 15, 39);
#endif

	// HUD code goes above this line
	GameLoop::camera(engine);
	// Game code goes below this line

	//temp background for a sense of direction and speed
	for(int i = -100; i < 100; ++i) {
		for(int j = -100; j < 100; ++j) {
			glColor3f(1.f, 0.f, 1.f);
			glPointSize(2.f);
			glBegin(GL_POINTS);
				glVertex2d(i*100, j*100);
			glEnd();
		}
	}

	for(int i = 0; i < actors->getHeroAmt(); ++i) {
		actors->getHero(i)->render();
	}
	for(int i = 0; i < actors->getEnemyAmt(); ++i) {
		actors->getEnemy(i)->render();
	}
}

void GameLoop::free(Mode::Engine *engine) {
	Actors *actors = engine->getData<Actors>();
	for(int i = 0; i < actors->getHeroAmt(); ++i) {
		actors->getHero(i)->free();
	}
}

void GameLoop::camera(Mode::Engine *engine) {
	int ww = engine->getWindow()->getW(),
		wh = engine->getWindow()->getH();

	int heroNum = engine->getData<Actors>()->getHeroAmt();
	float x     = 0,
		  y     = 0,
		  tempX = 0,
		  tempY = 0;
	for(int i = 0; i < heroNum; ++i) {
		engine->getData<Actors>()->getHero(i)->getCenter(&tempX, &tempY);
		x += tempX;
		y += tempY;
	}
	x /= heroNum;
	y /= heroNum;
	glTranslatef(ww/2-x, wh/2-y, 0.f);
	engine->getData<Actors>()->camX = x;
	engine->getData<Actors>()->camY = y;
}
