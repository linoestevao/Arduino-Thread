
#include "thread.h"
#include "threadScheduler.h"

thread_scheduler::thread_scheduler() {
  _index = 0;
}



void thread_scheduler::handleRun() {

  tsch[_index].Run();

  _index++;
  if (_index == MAXPROCESSTHREADS)
    _index = 0;
}
