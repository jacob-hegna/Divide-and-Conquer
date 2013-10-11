/*************************************************************************
 * Divide and Conquer - window.cpp                                       *
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

#include "window.h"

#include <cstring>

using namespace rapidxml;

Window::~Window(void) {
	free();
}

void Window::free(void) {
	_time = glfwGetTime() - _stime;
	glfwDestroyWindow(_window);
}

int Window::init(void)
{
	// Input
	struct stat buffer;
	if(stat("settings.xml", &buffer) == 0) {
		file<> xmlFile("settings.xml");
		xml_document<> doc;
		doc.parse<0>(xmlFile.data());
		xml_node<> *root = doc.first_node("window");

		xml_attribute<> *rootAddr = root->first_attribute("title");
		_title = rootAddr->value();
		rootAddr = rootAddr->next_attribute("aa");
		_aa = atof(rootAddr->value());


		xml_node<> *node = root->first_node("pos");
		xml_attribute<> *attr = node->first_attribute("x");
		_x = atoi(attr->value());
		attr = attr->next_attribute("y");
		_y = atoi(attr->value());

		node = node->next_sibling("size");
		attr = node->first_attribute("w");
		_w = atoi(attr->value());
		attr = attr->next_attribute("h");
		_h = atoi(attr->value());
		attr = attr->next_attribute("fullscreen");
		_fc = (atoi(attr->value()) == 1) ? true : false;

		node = node->next_sibling("color");
		attr = node->first_attribute("r");
		_clearColor.r = atof(attr->value());
		attr = attr->next_attribute("g");
		_clearColor.g = atof(attr->value());
		attr = attr->next_attribute("b");
		_clearColor.b = atof(attr->value());

		root = root->next_sibling("input");
		rootAddr = root->first_attribute("type");
		if(strcmp(rootAddr->value(), "joystick") == 0) {
			_inputType = JOYSTICK;
		} else {
			_inputType = KEYBOARD;
		}

	} else {
		std::ofstream ofile("settings.xml");
		ofile << "<window title=\"Divide and Conquer\" aa=\"16\">"                                             << std::endl
			  << "  <pos  x=\"15\" y=\"15\"/>"                                                                 << std::endl
			  << "  <size w=\"800\" h=\"600\" fullscreen=\"0\"/>"                                              << std::endl
			  << "  <color r=\"1\" g=\"1\" b=\"1\"/>"                                                          << std::endl
		      << "</window>"                                                                                   << std::endl
		      << "<input type=\"keyboard\"/>"                                                                  << std::endl;
		ofile.close();
		_clearColor.r = 1.f;
		_clearColor.g = 1.f;
		_clearColor.b = 1.f;
		_x = 50;
		_y = 50;
		_w = 800;
		_h = 600;
		_title = "Divide and Conquer";
		_aa = 16;
		_fc = false;
		_inputType = KEYBOARD;
	}

	_time    = 0;
	_frames  = 0;
	_stime   = glfwGetTime(); 
	_joy.set(0);
	_oldW = _w;
	_oldH = _h;

	glfwWindowHint(GLFW_SAMPLES, _aa);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	_window = glfwCreateWindow(_w, _h, _title.c_str(), (_fc) ? glfwGetPrimaryMonitor() : nullptr, nullptr);

	if(!_window) {
		glfwDestroyWindow(_window);
		return -1;
	}

	glfwSetWindowPos(_window, _x, _y);

	glfwMakeContextCurrent(_window);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glEnable(GL_TEXTURE_2D);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, _w, _h, 0);
	glClearColor(_clearColor.r,
				 _clearColor.g,
				 _clearColor.b,
				 1.f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	return 0;
}

void Window::clear(void) {
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);

	if(_oldW != _w || _oldH != _h) {
		_oldW = _w;
		_oldH = _h;
		glfwSetWindowSize(_window, _w, _h);
	}
}
