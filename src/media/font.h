#ifndef _FONT_H
#define _FONT_H

#include <string>
#include <GLFW/glfw3.h>
#include <oglft/OGLFT.h>

namespace Font {
    extern OGLFT::Monochrome *face;
    void init(void);
    void print(std::string, float, float);
    void deinit(void);
};

#endif
