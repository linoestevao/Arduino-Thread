/*
 * SLWT.h - Scheduler for light weight thread
 *
 * Copyright (c) 2015 Lino Estevao All rights reserved.
 *
 *
 * This is a library to provide a scheduler for lightweight thread struct to handle threads
 * for BITOS
 *  Created on: 03/07/2015
 *  Written by lino Estevao
*/

#ifndef SLWT_H_
#define SLWT_H_

#include <Arduino.h>
#include "bitos.h"


class lwthread;

class SLWT {

private:
	
	//vector pointer threads
	lwthread *tptr[MAXTHREADS];
	byte _index;
	
public:

	SLWT();
	
	boolean attachThread(lwthread *t);
	
	boolean detachThread(lwthread *t);
	
	void handle_run();
	



};



#endif /* SLWT_H_ */