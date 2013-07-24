#include "timer.h"

void Timer::init( double (*timerFunc)(void) ) {
	_timerFunc = timerFunc;
	_start = _timerFunc();
	_total = 0;
}

void Timer::update( void ) {
	_total = _timerFunc() - _start;
}

void Timer::pause( void ) {

}

void Timer::unpause( void ) {

}

void Timer::reset( void ) {
	_start = _timerFunc();
	_total = 0;
	_begin = 0;
}