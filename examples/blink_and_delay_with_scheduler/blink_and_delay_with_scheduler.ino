/*
blink_and_delay_with_scheduler.ino - example how to use thread library with automated scheduler to handle runs.

	you can look at the documentation on http://github.com/linoestevao/Arduino-thread
	
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
	Created on: Created: 04/07/2015 01:10:34
 */ 

#include <lwthread.h>
#include <SLWT.h>


lwthread t1, t2;


SLWT Scheduler;

//function for change led state
void change(){
	digitalWrite(13,!digitalRead(13));
	
}

void delayThread(){
	if (t1.isRunning()){
		t1.Stop();
	} else {
		t1.Start();
	}
}



void setup(){
	pinMode(13, OUTPUT);
	//init thread with the callback "change" and run every 1s or 1000 ms and attach itself to the scheduler
	t1.init(change, 1000, &Scheduler);
	//we must start the thread
	t1.Start();
	
	//init thread with the callback for delay the thread t1
	//every time this thread runs, de t1 thread will stop is work for 5 seconds or 5000 miliseconds and attach itself to the scheduler
	t2.init(delayThread, 5000, &Scheduler);
	
	t2.Start();
}

void loop(){
	//interate all threads attached
	Scheduler.handle_run();
	
}