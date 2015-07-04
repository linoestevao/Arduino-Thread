/*
lwthread.h - LightWeight thread for BitOS
	This is a library to provide a lightweight struct to handle simple threads
	for BITOS
	
	Copyright (c) 2015 Lino Estevao All rights reserved.

	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License along
	with this program; if not, write to the Free Software Foundation, Inc.,
	51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
	
	Author: Lino Estevao <l.estevao@campus.fct.unl.pt>
	Created on: 22/06/2015
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


