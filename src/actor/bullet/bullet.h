#ifndef _BULLET_H
#define _BULLET_H

#include "../actor.h"
#include "../../modes/engine/engine.h"

enum GunType 
{
	PISTOL,
	SNIPER,
	RPG,
	GATLING,
	SHOTGUN
};

struct Gun {
    float speed;
    int bW, bH;
    float damage;
    float delay;
	float acc;
};
extern Gun gun[5];

class Bullet : public Actor
{
private:
	GunType _type;
    float _damage;
public:
    Bullet(void) {
		// Nothing to do here...
	}
    
	Bullet(float x, float y, float theta, GunType type) {
		init(x, y, theta, type);
	}

	~Bullet(void) {

	}

	static void initGuns( void );
    void init(float x, float y, float theta, GunType type);
    void move(Mode::Engine *engine);
	void render();

    float getDamage(void) {return _damage;}

	float getX(void) {
		return _x;
	}
	float getY(void) {
		return _y;
	}
	GunType getType(void) {
		return _type;
	}
};

#endif