
#include <Wire.h>
#include "SparkFun_Qwiic_OpenLog_Arduino_Library.h"
#include <SparkFun_LPS25HB_Arduino_Library.h> // Click here to get the library: http://librarymanager/All#SparkFun_LPS25HB

LPS25HB bottleSensor; // Create an object of the LPS25HB class
OpenLog bottleReadings; //Create instance

void setup()
{
  Serial.begin(9600);
  Wire.begin();
  bottleSensor.begin(); // Begin links an I2C port and I2C address to the sensor, sets an I2C speed, begins I2C on the main board, and then sets default settings
  bottleReadings.begin(); //Open connection to OpenLog (no pun intended)

  if (bottleSensor.isConnected() == false) // The library supports some different error codes such as "DISCONNECTED"
  {
    Serial.println("theres a problem");
    while (1);
  }




  Serial.println("Run OpenLog Append File Test");

  bottleReadings.append("appendMe.txt");
  bottleReadings.println("This is recorded to appendMe.txt");

  bottleReadings.syncFile();

  Serial.println("Done!");
}


void loop()
{
  Serial.print("Pressure in hPa: ");
  Serial.print(bottleSensor.getPressure_hPa()); // Get the pressure reading in hPa
  Serial.print(", Temperature (degC): ");
  Serial.println(bottleSensor.getTemperature_degC()); // Get the temperature in degrees C

  delay(40); // Wait - 40 ms corresponds to the maximum update rate of the sensor (25 Hz)
}
