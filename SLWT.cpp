/*
SLWT.h - Scheduler for light weight thread
	This is a library to provide a scheduler for lightweight thread struct to handle threads
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
	Created on: 03/07/2015
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