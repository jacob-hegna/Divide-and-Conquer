#ifndef _FONT_H
#define _FONT_H

#include <string>
#include <GLFW/glfw3.h>

#if !defined(_WIN32) && !defined(__APPLE__)
#include <oglft/OGLFT.h>
#endif

namespace Font {
#if !defined(_WIN32) && !defined(__APPLE__)
    extern OGLFT::Monochrome *face;
#endif
    void init(void);
    void print(std::string, float, float);
    void deinit(void);
};

#endif
