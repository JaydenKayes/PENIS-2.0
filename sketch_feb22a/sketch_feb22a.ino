
//Add a LCD library of functions 
#include <Adafruit_LiquidCrystal.h>


//set up all the pins and constants 
const byte BINPIN = 1;
const byte NOISEPIN = A0;
const byte POTPIN = A1;


//connect via 12c, default address #0
Adafruit_LiquidCrystal screen(0);

//setting up what pins are input and output
//and randomise where we start our random numbers from 
void setup() {
  pinMode(BINPIN, INPUT);
  pinMode(POTPIN, INPUT);

  randomSeed(analogRead(NOISEPIN));

  Serial.begin(9600);


  if(!screen.begin(16, 2)){
    Serial.println("big dick yummy");
    while(1);
  }

}

void loop() {
  // put your main code here, to run repeatedly:

}
