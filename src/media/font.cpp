#include "font.h"

OGLFT::Monochrome *Font::face = nullptr;

void Font::init(void) {
    face = new OGLFT::Monochrome("media/arial.ttf", 24);
    face->setForegroundColor(0,0,0);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
}  

void Font::print(std::string data, float x, float y) {
    face->draw(x, y, data.c_str());
}

void Font::deinit(void) {
    delete face;
}
