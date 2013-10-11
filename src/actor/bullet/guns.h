#ifndef _GUNS_H
#define _GUNS_H

#include <string>

const int GUN_AMT = 4;
struct Gun {
	std::string name;
    float speed;
    int bW, bH;
    float damage;
    float delay;
	float acc;
};

static Gun guns[] = {
	// This goes in the same order as the struct declaration, obviously
	{"Pistol",   650,  4,  4,  20,    -1,  .1f},
	{"Gatling",  650,  3,  3,   1, .001f,  .5f},
	{"Sniper",  1000,  8,  8,  65,    -1, .05f},
	{"RPG",      550, 25, 25, 150,    -1, .15f}
};

#endif