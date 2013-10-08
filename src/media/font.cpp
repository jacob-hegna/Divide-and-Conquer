#include "font.h"

#ifndef _WIN32
OGLFT::Monochrome *Font::face = nullptr;
#endif

void Font::init(void) {
#ifndef _WIN32
    face = new OGLFT::Monochrome("media/arial.ttf", 24);
    face->setForegroundColor(0,0,0);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
#endif
}  

void Font::print(std::string data, float x, float y) {
#ifndef _WIN32
    face->draw(x, y, data.c_str());
#endif
}

void Font::deinit(void) {
#ifndef _WIN32
    delete face;
#endif
}
