#include <MD_TCS230.h>
#include <FreqCount.h>

// Pin definitions
#define  S2_OUT  12
#define  S3_OUT  13
#define  OE_OUT   8    // LOW = ENABLED

MD_TCS230  CS(S2_OUT, S3_OUT, OE_OUT);

void setup() {
  Serial.begin(57600);
  CS.begin();
  blackCalibration();
}

char getChar()
// blocking wait for an input character from the input stream
{
  while (Serial.available() == 0);
  return(toupper(Serial.read()));
}

void clearInput()
// clear all characters from the serial input
{
  while (Serial.read() != -1);
}

void blackCalibration() 
{
  Serial.print(F("BLACK calibration\n"));
  getChar();
  clearInput();
  Serial.print(F("Reading\n"));
  CS.read(); 
  delay(1000);
  while(!CS.available()) 
    {}
      sensorData sd;

      CS.getRaw(&sd);  
      CS.setDarkCal(&sd); 
      Serial.print(F("black calibrated"));

  
}



void loop() {

}
