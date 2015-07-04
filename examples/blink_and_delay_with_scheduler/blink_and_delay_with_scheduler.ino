
/*
 * blink_example.ino
 *
 * Created: 04/07/2015 01:10:34
 *  Author: LinoMiguelSantos
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