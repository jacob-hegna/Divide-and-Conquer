#ifndef _SMARTPTR_H
#define _SMARTPTR_H

#define smartptr SmartPtr

#include <cstdlib>

template <class T> class SmartPtr {
public:
	SmartPtr(void) {
		_data = nullptr;
	}

	SmartPtr(T t) {
		_data = nullptr;
		_data = t;
	}

	~SmartPtr(void) {
		free();
	}

	bool alloc(T data) {
		_data = data;
	}

	bool free(void) {
		if(_data != nullptr) {
			delete _data;
			return true;
		} else {
			return false;
		}
	}

	// Operations
	T operator=(T data) {
		return _data;
	}
	T operator&() {
		return _data; 
	}
	T operator*() {
		return **_data;
	}
	T operator->() {
		return _data;
	}
	void operator delete(void* mem) {
		free();
	}
private:
	T _data;
};

#endif