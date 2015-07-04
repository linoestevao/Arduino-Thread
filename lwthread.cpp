/*
 * lwthread.cpp
 *
 *  Created on: 22/06/2015
 *      Author: LinoMiguelSantos
 */

#include "lwthread.h"

lwthread::lwthread(){
	_callback = NULL;

	_interval = 0;

	_isRunning = false;

	_nextRun = 0;

}


void lwthread::init(void (*callback)(void), int interval){

	_callback = callback;

	_interval = interval;

	_isRunning = false;

	_nextRun = 0;

}

void lwthread::init(void (*callback)(void), int interval, SLWT *scheduler){
	_callback = callback;

	_interval = interval;

	_isRunning = false;

	_nextRun = 0;
	
	scheduler->attachThread(this);
}

void lwthread::set_interval(int interval){

	_interval = interval;
}

int lwthread::get_interval(){

	return _interval;
}

void lwthread::Start(){
	if(_callback != NULL){
		_nextRun = millis() + _interval;
		_isRunning = true;
	}
	//add to handle run class
}

void lwthread::Stop(){
	_isRunning = false;
	//add to handle run class
}

void lwthread::Restart(){
	_nextRun = millis() + _interval;
}

boolean lwthread::isRunning(){
	return _isRunning;

}
void lwthread::Run(){


	if (_isRunning && (millis() > _nextRun)){
#ifdef debug
		Serial.print(millis());
		Serial.print(" | Thread n #");
		Serial.print((int)_callback);
		Serial.print(" | nextRun: ");

#endif
		_callback();
		_nextRun = millis() + _interval;
#ifdef debug
		Serial.print(_nextRun);
		Serial.print("size of this ");
		Serial.println(sizeof(_nextRun));
#endif



	}
}


