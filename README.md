# Arduino-Thread
This library provides multitasking on microcontrollers such as arduino providing threads and a scheduler.

#Preface
Thread is the smallest sequence of program that can be managed independently by a scheduler. Multiple threads can exist running concurrently using time-slicing methods by a scheduler. 

For more information please read this [page](https://en.wikipedia.org/wiki/Thread_(computing))


# Resume
On our Arduino based projects (or other platforms) we usually do:
- Data acquisition:
  - Analog to digital converters (battery voltage, potentiometer resistance...)
  - Digital reading on ports or registers
  - I2C sensors like temperature and humidity
  - Serial input from user
- Data processing
  - Conversion digital values to human readable ones
  etc
- Data storage
  - Serial print
  - Store on SD card
  - Upload to the cloud
  etc
But in larger programs, the management of them can become really painful.

For example, on debouncing a push-button, the noise of the state change can be filtered by instead of use delay to double check if the button is pressed, we can start a thread that perform a double verification every 20ms and if after this time if the button still pressed, start another thread that processes the result for example.


##Resume: No blocking code
	
#Features
- Allows a Multithreading system
- Easy to implement timers and invoke callbacks (event like programming)
- makes your code readable and easy to understand even for the developer
- structured programming
- high abstraction layer on threads. Only create a thread, start it and forget about


# Instalation
To add libraries on arduino ide check this [guide](https://www.arduino.cc/en/guide/libraries)

# Documentation
- Check the wiki [beta](https://github.com/linoestevao/Arduino-Thread/wiki) 

### Version
0.9.0

#License
See the [LICENSE](/LICENSE.md) file for license rights and limitations (GPLV2)


