#include <FastLED.h>

#include <MD_TCS230.h>
#include <FreqCount.h>

#define LED_PIN     9
#define NUM_LEDS    300

#define  S2_OUT  12
#define  S3_OUT  13
#define  OE_OUT   8    // LOW = ENABLED

CRGB leds[NUM_LEDS];

MD_TCS230  CS(S2_OUT, S3_OUT, OE_OUT);

int inkomst = 0;
const int LEDPin = 10;
const int pin1muntenteller = 4;
const int pin2muntenteller = 2;
const int pin3muntenteller = 3;
const int pin5muntenteller = 5;
const int pin6muntenteller = 6;
const int pin7muntenteller = 7;

const int buttonPin = 11;
int buttonState = 0;  


void setup() {
  
  pinMode(pin1muntenteller, INPUT);
  pinMode(pin2muntenteller, INPUT);
  pinMode(pin3muntenteller, INPUT);
  pinMode(pin5muntenteller, OUTPUT);
  pinMode(pin6muntenteller, OUTPUT);
  pinMode(pin7muntenteller, OUTPUT);
  pinMode(buttonPin, INPUT);
  
  Serial.begin(57600);
  
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  
  buttonState = digitalRead(buttonPin);
  
  CS.begin();
 
}

void readSensor(){
  static  bool  waiting;
  
  if (!waiting){
    CS.read();
    waiting = true;
  }
  else{
    if (CS.available()){
      colorData  rgb;
      
      CS.getRGB(&rgb);
      Serial.print("RGB [");
      Serial.print(rgb.value[TCS230_RGB_R]);
      Serial.print(",");
      Serial.print(rgb.value[TCS230_RGB_G]);
      Serial.print(",");
      Serial.print(rgb.value[TCS230_RGB_B]);
      Serial.println("]");
      
      waiting = false;
    }
  }
  
}

void loop() {
  
  //inkomst = Serial.read();
  digitalWrite(pin5muntenteller, HIGH);
  digitalWrite(pin6muntenteller, LOW);
  digitalWrite(pin7muntenteller, LOW);

  bool contactTussenP1enP5 = digitalRead(pin3muntenteller);

  if (contactTussenP1enP5) {
    // geeft aan dat we een muntstuk van 5 cent hebben
    //bedrag + 5;
    

    digitalWrite(LEDPin, HIGH);
    Serial.println("5");
    inkomst += 5;
    delay(500);
  }
  else {
    digitalWrite(LEDPin, LOW);
  }
  bool contactTussenP3enP5 = digitalRead(pin1muntenteller);

  if (contactTussenP3enP5) {
    // geeft aan dat we een muntstuk van 1 cent hebben
    //bedrag + 1;
    digitalWrite(LEDPin, HIGH);
    Serial.println("1");
    inkomst += 1;
    delay(500);
  }
  else {
    digitalWrite(LEDPin, LOW);
  }

  bool contactTussenP2enP5 = digitalRead(pin2muntenteller);

  if (contactTussenP2enP5) {
    // geeft aan dat we een muntstuk van 2 euro hebben
    //bedrag + 200;
    inkomst += 200;
    digitalWrite(LEDPin, HIGH);
    Serial.println("200");
    delay(500);
  }
  else {
    digitalWrite(LEDPin, LOW);
  }
  digitalWrite(pin5muntenteller, LOW);
  digitalWrite(pin6muntenteller, HIGH);
  digitalWrite(pin7muntenteller, LOW);

  bool contactTussenP2enP6 = digitalRead(pin2muntenteller);

  if (contactTussenP2enP6) {
    // geeft aan dat we een muntstuk van 50 cent hebben
    digitalWrite(LEDPin, HIGH);
    Serial.println("50");
    inkomst += 50;
    delay(500);;
  }
  else {
    digitalWrite(LEDPin, LOW);
  }
  bool contactTussenP1enP6 = digitalRead(pin1muntenteller);

  if (contactTussenP1enP6) {
    // geeft aan dat we een muntstuk van 10 cent hebben
    //bedrag + 10;
    digitalWrite(LEDPin, HIGH);
    Serial.println("10");
    inkomst += 10;
    delay(500);
  }
  else {
    digitalWrite(LEDPin, LOW);
  }
  bool contactTussenP3enP6 = digitalRead(pin3muntenteller);

  if (contactTussenP3enP6) {
    // geeft aan dat we een muntstuk van 20 cent hebben
    //bedrag + 20;
    digitalWrite(LEDPin, HIGH);
    Serial.println("20");
    inkomst += 20;
    delay(500);
  }
  else {
    digitalWrite(LEDPin, LOW);
  }
  digitalWrite(pin5muntenteller, LOW);
  digitalWrite(pin6muntenteller, LOW);
  digitalWrite(pin7muntenteller, HIGH);

  bool contactTussenP2enP7 = digitalRead(pin2muntenteller);

  if (contactTussenP2enP7) {
    // geeft aan dat we een muntstuk van 1 euro hebben
    //bedrag + 100;
    digitalWrite(LEDPin, HIGH);
    Serial.println("100");
    inkomst += 100;
    delay(500);
  }
  else {
    digitalWrite(LEDPin, LOW);
  }
  bool contactTussenP1enP7 = digitalRead(pin3muntenteller);

  if (contactTussenP1enP7) {
    // geeft aan dat we een muntstuk van 1 euro hebben
    //bedrag + 100;
    digitalWrite(LEDPin, HIGH);
    Serial.println("100");
    inkomst += 100;
    delay(500);
  }
  else {
    digitalWrite(LEDPin, LOW);
  }

  bool contactTussenP3enP7 = digitalRead(pin1muntenteller);

  if (contactTussenP3enP7) {
    // geeft aan dat we een muntstuk van 2 cent hebben
    //bedrag + 2;
    digitalWrite(LEDPin, HIGH);
    Serial.println("2");
    inkomst += 2;
    delay(500);
  }
  else {
    digitalWrite(LEDPin, LOW);
  }
  

  
if (buttonState == HIGH){
  readSensor();
  colorData  rgb;
    
    if (rgb.value[TCS230_RGB_R]>rgb.value[TCS230_RGB_G]&&rgb.value[TCS230_RGB_R]>rgb.value[TCS230_RGB_B]){

      Serial.print("briefje van 10€");
      //inkomst += 10000t
    
    }
      else if   (rgb.value[TCS230_RGB_B]>rgb.value[TCS230_RGB_G]&&rgb.value[TCS230_RGB_B]>rgb.value[TCS230_RGB_R]){

      Serial.print("briefje van 20€");
    //inkomst += 20000
    
    }
      else 
      Serial.print("briefje van 5€");
    //inkomst+= 5000
    delay(5000);
}
}
