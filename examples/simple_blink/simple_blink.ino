
/*
 * blink_example.ino
 *
 * Created: 04/07/2015 01:10:34
 *  Author: LinoMiguelSantos
 */ 

#include <lwthread.h>

lwthread t1;

//function for change led state
void change(){
	digitalWrite(13,!digitalRead(13));
	
}



void setup(){
	pinMode(13, OUTPUT);
	//init thread with the callback "change" and run every 1s or 1000 ms 
	t1.init(change, 1000);
	//we must start the thread
	t1.Start();
}

void loop(){
	//The run method will auto run the callback when the timer blows up <3
	t1.Run();
	
}