#ifndef _thread_h_
#define _thread_h_



#include <Arduino.h>
class thread {
  private:
      
    int _id;
    #ifdef USE_THREAD_NAME
    String _name;
    #endif
    long int _runtime;
    
    long int _time;
    
    boolean _isRunning;
    
    int _interval;
    
    unsigned long _nextRun;
    
    void (*_callback)(void);
    
  
  public:
    thread();
    
    void init(void (*callback)(void), int interval);
    
    #ifdef USE_THREAD_NAME
    
    void init(String Name, void (*callback)(void), int interval);
    
    void setname(String Name);
    
    #endif
    
    void setcallback(void (*callback)(void));
    
    boolean isInitializated();
    
    void setinterval(int interval);
    
    boolean isRunning();
    
    void Start();
    
    void Stop();
    
    unsigned int Tid();
    
    #ifdef USE_THREAD_NAME
    String Name();
    #endif
    
    long int runtime();
    
    long int time();
    
    long int nextRun();
    
    void Run();
    

};

#endif
