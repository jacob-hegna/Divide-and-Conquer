#ifndef _FONT_H
#define _FONT_H

#include <string>
#include <GLFW/glfw3.h>
#include <GL/glc.h>

void glPrintfInit(void);

void glPrintf(std::string text, 
	             float w, float h, 
	             float x, float y, 
	             float r, float g, float b);

#endif