# IR-Sensor-Arduino

Simple code to setup and read data from the VNCL4200 IR Sensor (http://www.mouser.com/ds/2/427/vcnl4200-1115021.pdf)

The code sets up some basic registers in the sensors then continuously requests the distance reading from the sensor (register 0x08). The sensors returns the reading in the form of two bytes, which are then combined and displayed as one number, over the serial monitor.
