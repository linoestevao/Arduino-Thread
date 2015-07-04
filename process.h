/*
 * process.h - processes for BitOS
 * Copyright (c) 2015 Lino Estevao All rights reserved.
 *
 *
 * This is a library to provide a lightweight struct to handle processes and their threads
 * for BITOS
 *
 *  Created on: 23/06/2015
 */



#ifndef BITOS_PROCESS_H_
#define BITOS_PROCESS_H_

#include "bitos.h"
#include "lwthread.h"

#include <Arduino.h>

class process {

private:
	//store global id for the process
	int _id;

	//store the state of the process
	processSTATE _st;

	//Store the name of the process
	String _name;


	//Store processor time consumption
	unsigned long _runtime;

	//Store total processor time consumption
	unsigned long _time;

	//Stores the interval in millisecconds for each run
	int _interval;

	//this is auto-updated on each call Run() and optimizes all the Run method
	// and initializated on Start() call.
	unsigned long _nextRun;

	lwthread t[MAXTHREADSPERPROCESS];

public:

	//Create the instance
	process();

	//init the process
	void init(String Name, int _interval /*Maybe its cool to add "data" stuff on this to call in other processes easily ... just saying*/);

	int get_interval();

	unsigned long get_runtime();

	unsigned long get_time();

	String get_name();

	processSTATE get_state();

	/*callback setup
	 */

	/*
	 * need a flag in the waiting state
	 * why? imagine that you want to update time on a screen.
	 * call sys_getTime() and pass the wakeup procedure, and the call thread will go to waitting state.
	 * */

	/* RUN the active threads of the process.
	 * Need to be called every time.
	 * verify if the _callback run is set (in order to prevent an halt), check if its runnable and if the actual time is greater than the nextRun, runs the callback_run
	 */
	void Run();

/*todo list
	instanciar o processo
	chamar funcao setup() que recebe por parametro
	no setup() iniciar o _id, as threads e etc...

	no run() é para correr esta motherfucker!!!

	void Run();
*/
};



#endif /* BITOS_PROCESS_H_ */
