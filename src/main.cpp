#include <Arduino.h>

/*********************************************************************
  This is an example for our Monochrome OLEDs based on SH1107 drivers

  This example is for a 128x128 size display using I2C to communicate

  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada  for Adafruit Industries.
  BSD license, check license.txt for more information
  All text above, and the splash screen must be included in any redistribution
*********************************************************************/



#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#include "OLED.h"
#include "LSM6DS3.h"

OLED oled; // create a OLED object

//Create a instance of class LSM6DS3
LSM6DS3 myIMU(I2C_MODE, 0x6A);    //I2C device address 0x6A

float distance = 1.32;
float compass = 234;
float clino = -23;
bool ble_status =  false;

float batt_percentage = 25;

void setup()   {
  
    // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial);
  //Call .begin() to configure the IMUs
  if (myIMU.begin() != 0) {
      Serial.println("Device error");
  } else {
      Serial.println("Device OK!");
  }

  oled.Initialise();

  delay(250); // wait for the OLED to power up
  oled.clearDisplay();

  oled.Battery(batt_percentage);
  oled.Distance(distance);
  oled.Compass(compass);
  oled.Clino(clino);
  oled.Blutooth(ble_status);

  delay(1000);
}

void loop() {

  distance = random(1,30);
  compass = random(0,359);
  clino = random(-90,90);

  delay(100);

  //Accelerometer
  float x = myIMU.readFloatAccelX();
  float y = myIMU.readFloatAccelY();
  float z = myIMU.readFloatAccelZ();
  batt_percentage = random(0,100);
  ble_status = !ble_status;

  Serial.println(x);
  Serial.println(y);
  Serial.println(z);

  oled.Battery(batt_percentage);
  oled.Distance(distance);
  oled.Compass(compass);
  oled.Clino(clino);
  oled.Blutooth(ble_status);


}






