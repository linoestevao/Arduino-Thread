//#include <Arduino.h>
#include "thread.h"


thread::thread() {
	_id = (int)this;

#ifdef USE_THREAD_NAME
	_name = "---";
#endif

	_runtime = 0;

	_time = 0;

	_isRunning = false;

	_interval = 0;

	_nextRun = 0;

	_callback = NULL;

}


void thread::init(void (*callback)(void), int interval){
	_id = (int)this;

	_runtime = 0;

	_time = 0;

	_isRunning = false;

	_interval = interval;

	_nextRun = 0;

	_callback = callback;
}

#ifdef USE_THREAD_NAME

void thread::init(String Name, void (*callback)(void), int interval){
	_id = (int)this;

#ifdef USE_THREAD_NAME
	_name = Name;
#endif

	_runtime = 0;

	_time = 0;

	_isRunning = false;

	_interval = interval;

	_nextRun = 0;

	_callback = callback;
}

void thread::setname(String Name) {
	_name = Name;
}

#endif



void thread::setcallback(void (*callback)(void)) {
	_callback = callback;
}

boolean thread::isInitializated() {
	if (_callback != NULL)
		return true;
	return false;
}


void thread::setinterval(int interval) {
	_interval = interval;
}

boolean thread::isRunning() {
	return _isRunning;
}

void thread::Start() {
	if (isInitializated()) {
		_isRunning = true;
		_nextRun = millis() + _interval;
	}
}

void thread::Stop() {
	_isRunning = false;
}

unsigned int thread::Tid() {
	return _id;
}

#ifdef USE_THREAD_NAME
String thread::Name() {
	return _name;
}
#endif

long int thread::runtime() {
	return _runtime;
}

long int thread::time() {
	return _time;
}

long int thread::nextRun() {
	return _nextRun;
}

void thread::Run() {
	//store the time before the execution callback
	if (isRunning() && millis() > _nextRun) {
		_runtime = micros();

		_callback();

		//caculate the runtime and store it
		_runtime = (micros() - _runtime) / 1000;

		//update total execution time since start of system
		_time += _runtime;
		//update nextRun
		_nextRun = millis() + _interval;
	}
}






