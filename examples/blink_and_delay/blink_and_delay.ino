
/*
 * blink_example.ino
 *
 * Created: 04/07/2015 01:10:34
 *  Author: LinoMiguelSantos
 */ 

#include <lwthread.h>

lwthread t1, t2;

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
	//init thread with the callback "change" and run every 1s or 1000 ms 
	t1.init(change, 1000);
	//we must start the thread
	t1.Start();
	
	//init thread with the callback for delay the thread t1
	//every time this thread runs, de t1 thread will stop is work for 5 seconds or 5000 miliseconds
	t2.init(delayThread, 5000);
	
	t2.Start();
}

void loop(){
	//The run method will auto run the callback when the timer blows up <3
	t1.Run();
	//same as the other :3
	t2.Run();
	
}