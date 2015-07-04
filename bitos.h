/*
 * bitos.h - Provide all the instructions for the pre-processor to compile the code
 * Copyright (c) 2015 Lino Estevao All rights reserved.
 * Created on: 23/06/2015
 */

#ifndef BITOS_BITOS_H_
#define BITOS_BITOS_H_

//Activate debug on BitOS. Be carefull, this may cause instability
//#define debug

//Self explanatory :3
#define MAXTHREADSPERPROCESS 30
#define MAXTHREADS 30

#include "lwthread.h"
#include "SLWT.h"


enum processSTATE {
	STOP,
	IDLE,
	PAUSED,
	RUNNING,
	WAITING,
};

#endif /* BITOS_BITOS_H_ */
