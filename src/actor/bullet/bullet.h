#ifndef _BULLET_H
#define _BULLET_H

#include "../actor.h"

void initGuns();
enum GunType 
{
	PISTOL,
	SNIPER,
	RPG,
	GATLING,
	SHOTGUN
};

struct Gun
{
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

    void init(float x, float y, float theta, int type);
    void move();
	void render();

    float getDamage(void) {return _damage;}

	float getX(void) {
		return _x;
	}
	float getY(void) {
		return _y;
	}
};

#endif