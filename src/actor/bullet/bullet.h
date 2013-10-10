#ifndef _BULLET_H
#define _BULLET_H

#include <vector>
#include <string>
#include <cmath>
#include <rapidxml/rapidxml.hpp>
#include <rapidxml/rapidxml_utils.hpp>

#include "../actor.h"
#include "../../modes/engine/engine.h"
#include "../../util/util.h"

struct Gun {
	std::string name;
    float speed;
    int bW, bH;
    float damage;
    float delay;
	float acc;
};
extern std::vector<Gun> guns;

class Bullet : public Actor
{
private:
	int   _type;
    float _damage;
public:
    Bullet(void) {
		// Nothing to do here...
	}
    
	Bullet(float x, float y, float theta, int type) {
		init(x, y, theta, type);
	}

	~Bullet(void) {

	}

	static void initGuns( void );
    void init(float x, float y, float theta, int type);
    void move(Mode::Engine *engine);
	void render();

    float getDamage(void) {return _damage;}

	float getX(void) {
		return _x;
	}
	float getY(void) {
		return _y;
	}
	int getType(void) {
		return _type;
	}
};

#endif