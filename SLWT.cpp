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
#include "SLWT.h"


SLWT::SLWT(){
	_index=0;
	for (int i = 0; i<MAXTHREADS; i++){
		tptr[i]=NULL;
	}
}

boolean SLWT::attachThread(lwthread *t){
	for (int i = 0; i<MAXTHREADS; i++){
		if(tptr[i]==NULL){
			tptr[i]=t;
			return true;
		}
	}
	return false;
}

boolean SLWT::detachThread(lwthread *t){
	for (int i = 0; i<MAXTHREADS; i++){
		if(tptr[i]==t){
			tptr[i]=NULL;
			return true;
		}
	}
	return false;
}

void SLWT::handle_run(){
	
	tptr[_index]->Run();
	
	_index ++;
	if (_index>=MAXTHREADS)
	{
		_index=0;
	}
}