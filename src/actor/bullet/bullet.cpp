#include "bullet.h"

#include <cmath>
#include "../../utilities/util.h"

std::vector<Gun> guns;

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

void Bullet::initGuns( void ) {
    using namespace rapidxml;
    file<> xmlFile("settings.xml");
    xml_document<> doc;
    doc.parse<0>(xmlFile.data());
    xml_node<> *root = doc.first_node("guns");

    for(xml_node<> *curNode=root->first_node("gun"); curNode; curNode=curNode->next_sibling())
    {
        Gun gun;

        xml_attribute<> *attr = curNode->first_attribute("name");
        gun.name = attr->value();
        attr = attr->next_attribute("w");
        gun.bW = atoi(attr->value());
        attr = attr->next_attribute("h");
        gun.bH = atof(attr->value());
        attr = attr->next_attribute("s");
        gun.speed = atof(attr->value());
        attr = attr->next_attribute("da");
        gun.damage = atof(attr->value());
        attr = attr->next_attribute("de");
        gun.delay = atof(attr->value());
        attr = attr->next_attribute("a");
        gun.acc = atof(attr->value());

        guns.push_back(gun);
    }
}
