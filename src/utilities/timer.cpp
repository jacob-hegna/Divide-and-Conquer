#include "timer.h"

void Timer::init( double (*timerFunc)(void) ) {
	_timerFunc = timerFunc;
	_start = _timerFunc();
	_total = 0;
}

void Timer::update( void ) {
	_total = _timerFunc() - _start;
}

void Timer::setInstant( void ) {
	_instStart = _timerFunc();
}

double Timer::getInstant( void ) {
	return _timerFunc() - _instStart;
}

void Timer::reset( void ) {
	_start = _timerFunc();
	_total = 0;
	_begin = 0;
}