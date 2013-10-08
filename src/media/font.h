#ifndef _FONT_H
#define _FONT_H

#include <string>
#include <GLFW/glfw3.h>

#ifndef _WIN32
#include <oglft/OGLFT.h>
#endif

namespace Font {
#ifndef _WIN32
    extern OGLFT::Monochrome *face;
#endif
    void init(void);
    void print(std::string, float, float);
    void deinit(void);
};

#endif
