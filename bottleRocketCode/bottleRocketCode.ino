
#include <Wire.h>
#include "SparkFun_Qwiic_OpenLog_Arduino_Library.h"
#include <SparkFun_LPS25HB_Arduino_Library.h> // Click here to get the library: http://librarymanager/All#SparkFun_LPS25HB

//TEACHER COMMENTS so what do these lines of code do?
LPS25HB bottleSensor; // Create an object of the LPS25HB class
OpenLog bottleReadings; //Create instance

void setup()
{
  Serial.begin(9600);
  Wire.begin();
  bottleSensor.begin(); // Begin links an I2C port and I2C address to the sensor, sets an I2C speed, begins I2C on the main board, and then sets default settings
  bottleReadings.begin(); //Open connection to OpenLog (no pun intended)

//TEACHER COMMENTS what is this checking again?  
  if (bottleSensor.isConnected() == false) 
  {
    Serial.println("theres a problem");
    while (1);
  }

  Serial.println("Run OpenLog Append File Test"); //TEACHER COMMENTS is this from the example code? do you need it?
//TEACHER COMMENTS what is the name of your file going to be? 
  bottleReadings.append("appendMe.txt");
  bottleReadings.println("This is recorded to appendMe.txt");

  bottleReadings.syncFile();

  Serial.println("Done!");
}


void loop()
{
  //TEACHER COMMENTS what is this chunk of code doing?
  Serial.print("Pressure in hPa: ");
  Serial.print(bottleSensor.getPressure_hPa()); // Get the pressure reading in hPa
  Serial.print(", Temperature (degC): ");
  Serial.println(bottleSensor.getTemperature_degC()); // Get the temperature in degrees C

  //TEACHER COMMENTS wouldn't it be great if your bottleReadings and bottleSensor did something here? 
  
  delay(40); // Wait - 40 ms corresponds to the maximum update rate of the sensor (25 Hz)
}
