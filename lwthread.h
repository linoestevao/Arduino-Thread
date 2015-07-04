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

#ifndef BITOS_LWTHREAD_H_
#define BITOS_LWTHREAD_H_


#include <Arduino.h>
#include "bitos.h"

class SLWT;

class lwthread {

private:

	//provide information if the thread is running or not
	boolean _isRunning;

	//Stores the interval in millisecconds for each run
	int _interval;

	//this is auto-updated on each call Run() and optimizes all the Run method
	// and initializated on Start() call.
	unsigned long _nextRun;

	//Stores the function adress for call in the method Run();
	void (*_callback)(void);

public:

	//Create the instance
	lwthread();

	//init the callback pointer and the interval call.
	void init(void (*callback)(void), int interval);
	
	//init the callback pointer, the interval  and the scheduler for handle this thread
	void init(void (*callback)(void), int interval, SLWT *scheduler);

	//Set the interval call
	void set_interval(int interval);

	//Get the interval call
	int get_interval();

	//Activation of the thread in Run() method and also set the _nextRun variable to the actual time + _interval.
	void Start();

	//Deactivation of the thread in Run() method
	void Stop();
	
	//set the _nextRun variable to the actual time + _interval.
	void Restart();

	//Get if this is runnable or not
	boolean isRunning();

	//RUN the thread :3 ... need to be called every time. This function will verify if the
	//_callback is set (in order to prevent an halt), check if its runnable (_isRunning) and if the actual time (millis()) is greater than the _nextRun variable.
	void Run();

};



#endif /* BITOS_LWTHREAD_H_ */
