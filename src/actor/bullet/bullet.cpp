#include "bullet.h"

#include <cmath>

Gun gun[5];

void Bullet::init(float px, float py, float ptheta, GunType type)
{
    _speed  = gun[type].speed;
    _w      = gun[type].bW;
    _h      = gun[type].bH;
    _x      = px-_w/2;
    _y      = py-_h/2;
    _theta  = ptheta;
    _damage = gun[type].damage;
    _dead  = false;

	_theta -= gun[type].acc/2;
	_theta += (float)rand()/((float)RAND_MAX/gun[type].acc);

	_type = type;
}

void Bullet::move(Mode::Engine *engine)
{
	_x += (_speed * cos(_theta))/engine->getFps();
	_y += (_speed * sin(_theta))/engine->getFps();
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

void Bullet::initGuns( void ) {
    gun[PISTOL].bH    = 4;
    gun[PISTOL].bW     = 4;
    gun[PISTOL].speed  = 650;
    gun[PISTOL].damage = 20;
    gun[PISTOL].delay  = -1;
	gun[PISTOL].acc    = .1f;

    gun[SNIPER].bH     = 8;
    gun[SNIPER].bW     = 8;
    gun[SNIPER].speed  = 650;
    gun[SNIPER].damage = 50;
    gun[SNIPER].delay  = -1;
	gun[SNIPER].acc    = 0;

    gun[RPG].bH     = 25;
    gun[RPG].bW     = 25;
    gun[RPG].speed  = 650;
    gun[RPG].damage = 100;
    gun[RPG].delay  = -1;
	gun[RPG].acc    = .25;

    gun[GATLING].bH     = 3;
    gun[GATLING].bW     = 3;
    gun[GATLING].speed  = 650;
    gun[GATLING].damage = 1;
    gun[GATLING].delay  = .001f;
	gun[GATLING].acc    = .5f;

	gun[SHOTGUN].bH     = 4;
	gun[SHOTGUN].bW     = 4;
	gun[SHOTGUN].speed  = 650;
	gun[SHOTGUN].damage = 13;
	gun[SHOTGUN].delay  = -1;
	gun[SHOTGUN].acc    = .1f;
}
