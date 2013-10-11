#include "bullet.h"

void Bullet::init(float px, float py, float ptheta, int type)
{
    _type = type;
    _speed  = guns[_type].speed;
    _w      = guns[_type].bW;
    _h      = guns[_type].bH;
    _x      = px-_w/2;
    _y      = py-_h/2;
    _theta  = ptheta;
    _damage = guns[_type].damage;
    _dead  = false;

    _theta += randF(-guns[_type].acc, guns[_type].acc);
}

void Bullet::move(Mode::Engine *engine)
{
	_x += (_speed * cos(_theta))/engine->getInstFps();
	_y += (_speed * sin(_theta))/engine->getInstFps();
}

void Bullet::render(void)
{
    if(!_dead)
    {
        glColor3f(0.f, 0.f, 0.f);
        glBegin(GL_QUADS);
            glVertex2d(_x, _y);
            glVertex2d(_x+_w, _y);
            glVertex2d(_x+_w, _y+_h);
            glVertex2d(_x, _y+_h);
        glEnd();
    }
}