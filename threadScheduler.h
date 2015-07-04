#ifndef _thread_scheduler_h_
#define _thread_scheduler_h_

#define MAXPROCESSTHREADS 10


#include "thread.h"


class thread_scheduler {

  private:
            
	int _index;
    int coisa;
          
  public:
    
    
    
	thread tsch[MAXPROCESSTHREADS];
    
	thread_scheduler();
    
    void handleRun();
    
    
};



#endif
