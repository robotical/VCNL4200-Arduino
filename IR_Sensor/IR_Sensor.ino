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

  write_register(SENSOR_ADDR, 0x3, B00011010, B00001000);
//  Wire.beginTransmission(SENSOR_ADDR);
//  Wire.write(0x3);
//  Wire.write(B00011010);  //PS_CONF1
//  Wire.write(B00001000);  //PS_CONF2
//  Wire.endTransmission(false);

  write_register(SENSOR_ADDR, 0x0, B01000001, B00000000);
//  Wire.beginTransmission(SENSOR_ADDR);
//  Wire.write(0x0);
//  Wire.write(B01000001);  //ALS_CONF  
//  Wire.write(B00000000);  //RESERVED
//  Wire.endTransmission(false);

  write_register(SENSOR_ADDR, 0x6, B00010000, B00000000);  
//  Wire.beginTransmission(SENSOR_ADDR);
//  Wire.write(0x6);
//  Wire.write(B00010000);  //PS_CONF1
//  Wire.write(B00000000);  //PS_CONF2
//  Wire.endTransmission(false);

  write_register(SENSOR_ADDR, 0x4, B01110000, B00000111);
//  Wire.beginTransmission(SENSOR_ADDR);
//  Wire.write(0x4);
//  Wire.write(B01110000);  //PS_CONF3
//  Wire.write(B00000111);  //PS_MS
//  Wire.endTransmission(false);
}

void loop() {

  int reg = 0x8;
  
  Wire.beginTransmission(SENSOR_ADDR);
  Wire.write(reg);
  Wire.endTransmission(false);

  //Read data
  byte data[2] = {0, 0};
  Wire.requestFrom(SENSOR_ADDR, 2);
  data[0] = Wire.read();
  data[1] = Wire.read();
  int value = int(data[1])*256 + int(data[0]);
  Serial.print(value);
  Serial.println(",");
  delay(100);

}
