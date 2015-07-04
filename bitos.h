/* 
bitos.h - Provide all the instructions for the pre-processor to compile the code
		
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
	Created on: Created on: 23/06/2015
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
