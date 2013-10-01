#include "timer.h"

void Timer::init( double (*timerFunc)(void) ) {
	_timerFunc = timerFunc;
	_start = _timerFunc();
}

void Timer::update( void ) {
	_total.push_back(_timerFunc() - _start);
	_start = _timerFunc();
}

double Timer::getTime(void) {
	float sum = 0.f;
	for(int i = 0; i < _total.size(); ++i) {
		sum += _total.at(i);
	}
	return sum;
}

void Timer::setInstant( void ) {
	_instStart = _timerFunc();
}

double Timer::getInstant( void ) {
	return _timerFunc() - _instStart;
}

void Timer::reset( void ) {
	_start = _timerFunc();
}

void Timer::pause(void) {

}

void Timer::unpause(void) {
	_start = _timerFunc();
}