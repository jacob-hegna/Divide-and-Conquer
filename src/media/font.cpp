#include "font.h"

void glPrintfInit(void) {
	glcEnable(GL_TRUE);
	glcContext(glcGenContext());
}

void glPrintf(std::string text, 
	             float w, float h, 
	             float x, float y, 
	             float r, float g, float b) {
	glcScale(w, h);
	glColor4f(r, g, b, 1.f);
	glRasterPos2f(x, y);
	glcRenderString(text.c_str());
}