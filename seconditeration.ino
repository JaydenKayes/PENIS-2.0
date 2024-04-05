#include <Wire.h>
#include <SPI.h>
#include <SD.h>

const int chipSelect = 4;

bool initializeLPS25HB() {
  // Placeholder for initializing the LPS25HB sensor
  // For now it always returns true
  return true;
}

float readLPS25HBPressure() {
  // Placeholder for pressure readings from LPS25HB module
  return 1013.25;  //examples for testing
}

float readLPS25HBTemperature() {
  // Placeholder for temperature readings from LPS25HB module
  return 22.5;  // Example for testing
}

void setup() {
  Serial.begin(9600);
  Wire.begin();

  // Initialize SD card
  if (!SD.begin(chipSelect)) {
    Serial.println("SD card unconnected");
    return;
  }
    // Open the file on the SD card
    File dataFile = SD.open("sensorData.txt", FILE_WRITE);
    
    dataFile.print("Temperature C, Pressure hPa  ");
  // Initialize LPS25HB sensor
  if (!initializeLPS25HB()) {
    Serial.println("LPS25HB card unconnected");
    while (1)
      ;  // Infinite loop to halt further execution
  }
}

void loop() {
  // Read temperature and pressure
  float temperature = readLPS25HBTemperature();
  float pressure = readLPS25HBPressure();

    // Open the file on the SD card
    File dataFile = SD.open("sensorData.txt", FILE_WRITE);

  // If the file is available, write to it
  if (dataFile) {
    // Write temperature and pressure data to the file
    dataFile.print(temperature);
    dataFile.println(" , ");
    dataFile.print(pressure);

    // Print temperature and pressure data to the Serial Monitor
    Serial.print("Temperature, Pressure, C, hPa: ");
    Serial.print(temperature);
    Serial.println(" C");
    Serial.print("Pressure: ");
    Serial.print(pressure);
    Serial.println(" hPa");

    dataFile.close();  // Close the file
  } else {
    // If the file didn't open print an error message
    Serial.println("Error opening sensorData.txt");
  }

  delay(2000);  // Delay for 2 seconds before next read
}
