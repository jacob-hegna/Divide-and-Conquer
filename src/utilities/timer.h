#ifndef _TIMER_H
#define _TIMER_H

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
	void pause( void );
	void unpause( void );
	void reset( void );

	double getTime( void ) {
		return _total;
	}

	void free( void ) {
		// nothing to free...
	}

private:
	double _start;
	double _total;

	double (*_timerFunc)(void);

	double _begin;
};

#endif