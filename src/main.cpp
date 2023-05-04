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

OLED oled; // create a OLED object

float distance = 1.32;
float compass = 234;
float clino = -23;
bool ble_status =  false;

float batt_percentage = 25;

void setup()   {

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
  batt_percentage = random(0,100);
  ble_status = !ble_status;

  oled.Battery(batt_percentage);
  oled.Distance(distance);
  oled.Compass(compass);
  oled.Clino(clino);
  oled.Blutooth(ble_status);

  delay(1000);

}






