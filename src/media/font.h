#ifndef _FONT_H
#define _FONT_H

#include <string>
#include <sstream>
#include <cstdio>

#include <FTGL/ftgl.h>
#include <GL/gl.h>

int glPrintf(std::string, float x, float y, std::string path, int size);

#endif