/*
 * process.cpp
 *
 *  Created on: 23/06/2015
 *      Author: LinoMiguelSantos
 */


#include "process.h"


void process::Run(){
	//interate all threads an run the runnable ones.
	//it must be optimized in the future

	for (int i=0; i< MAXTHREADSPERPROCESS; i++){
		t[i].Run(); //threads runner
	}
}
