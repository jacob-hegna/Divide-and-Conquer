#include "font.h"

#if !defined(_WIN32) && !defined(__APPLE__)
OGLFT::Monochrome *Font::face = nullptr;
#endif

void Font::init(void) {
#if !defined(_WIN32) && !defined(__APPLE__)
    face = new OGLFT::Monochrome("media/arial.ttf", 24);
    face->setForegroundColor(0,0,0);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
#endif
}

void Font::print(std::string data, float x, float y) {
#if !defined(_WIN32) && !defined(__APPLE__)
    face->draw(x, y, data.c_str());
#endif
}

void Font::deinit(void) {
#if !defined(_WIN32) && !defined(__APPLE__)
    delete face;
#endif
}
