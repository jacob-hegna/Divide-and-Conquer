#ifndef _TIMER_H
#define _TIMER_H

#include <vector>
#include <cstdio>

class Timer {
public:
	Timer( void ) {
		// nothing to do here...
	}

	Timer( double (*timerFunc)(void) ) {
		init(timerFunc);
	}

	~Timer( void ) {
		free();
	}

	void init( double (*_timerFunc)(void) );
	void update( void );
	void reset( void );

	void setInstant( void );
	double getInstant( void );

	void pause(void);
	void unpause(void);

	double getTime( void );

	void free( void ) {
		// nothing to free...
	}

private:
	float _start;
	std::vector<float> _total;

	double _instStart;

	double (*_timerFunc)(void);
};

#endif