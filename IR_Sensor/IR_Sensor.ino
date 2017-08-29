#define SENSOR_ADDR 0x51  
#include <Wire.h>

void write_register(int device_addr, int register_num, int low_byte, int high_byte)
{
  Wire.beginTransmission(device_addr);
  
  Wire.write(register_num); //PS_CONF1 Address
  Wire.write(low_byte);
  Wire.write(high_byte);
  
  Wire.endTransmission(false);
}


void setup() {
  
  Serial.begin(115200);
  Wire.begin();

  //Write to PS_CONF1 and PS_CONF2 to set Proximity Sensor (PS) settings.
  write_register(SENSOR_ADDR, 0x3, B00011010, B00001000);
 
  //Write to ALS_CONF to turn Ambient Light Sensor (ALS) off.
  write_register(SENSOR_ADDR, 0x0, B01000001, B00000000);
 
  //Write to PS_THDL_L and PS_THDL_H to set Proxmitt Sensor (PS) Threshhold.
  write_register(SENSOR_ADDR, 0x6, B00010000, B00000000);  
 
  //Write to PS_CONF3 and PS_MS to set Proximity Sensor (PS) settings.
  write_register(SENSOR_ADDR, 0x4, B01110000, B00000111);

}

void loop() {

  int reg = 0x8; //Proximity Sensor (PS) output

  //Write to regsiter
  Wire.beginTransmission(SENSOR_ADDR);
  Wire.write(reg);
  Wire.endTransmission(false);

  //Read data
  byte data[2] = {0, 0};  //The sensor provides the output over 2 bytes.
  Wire.requestFrom(SENSOR_ADDR, 2);
  data[0] = Wire.read();
  data[1] = Wire.read();
  int value = int(data[1])*256 + int(data[0]); //Combines bytes
  Serial.println(value);

  delay(100);

}
