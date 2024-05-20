
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

  //if bottle sensor runs as false will print "there is a problem" in serial monitor 
  if (bottleSensor.isConnected() == false)
  {
    Serial.println("theres a problem");
    while (1);
  }
// start of file test 
  Serial.println("Run OpenLog JaydensData File Test");
  //JaydensData is the name of the file
  bottleReadings.append("JaydensData.txt");
  //writes headers for the files
  bottleReadings.println("Temerature, Pressure"); //printing headings bottle readings 
  //ensure file data is writen immediatly 
  bottleReadings.syncFile();
  //prints headers to serial monitor 
  Serial.println("Temerature, Pressure"); //printing headings to serial 
  //indicates completion 
  Serial.println("Done!");
}


void loop()
{
  dataReadings(false); //false = rocket launch
  //  dataReadings(true); //true = before takeoff

}
//Method
void dataReadings(boolean debug) {
  if (debug == true) {
    Serial.print("Pressure in hPa: ");
    Serial.print(bottleSensor.getPressure_hPa()); // Get the pressure reading in hPa
    Serial.print(", Temperature (degC): ");
    Serial.println(bottleSensor.getTemperature_degC()); // Get the temperature in degrees
  }
  //printing the data for Temperature and Pressure
  bottleReadings.print(Temperature);
  bottleReadings.print(",");
  bottleReadings.println(Pressure);

}
