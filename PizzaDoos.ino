#include <FastLED.h>
#define LED_PIN     9
#define NUM_LEDS    300
CRGB leds[NUM_LEDS];

int bedrag = 0;
int inkomst = 0;
const int LEDPin = 10;
const int pin1muntenteller = 4;
const int pin2muntenteller = 2;
const int pin3muntenteller = 3;
const int pin5muntenteller = 5;
const int pin6muntenteller = 6;
const int pin7muntenteller = 7;

void setup() {
  pinMode(pin1muntenteller, INPUT);
  pinMode(pin2muntenteller, INPUT);
  pinMode(pin3muntenteller, INPUT);
  pinMode(pin5muntenteller, OUTPUT);
  pinMode(pin6muntenteller, OUTPUT);
  pinMode(pin7muntenteller, OUTPUT);
  Serial.begin(9600);
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
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

  if (inkomst == 200){
    bedrag += 200;
  leds[0] = CRGB(255, 0, 0);
  FastLED.show();
  delay(50);  
  leds[1] = CRGB(0, 255, 0);
  FastLED.show();
  delay(50);
  leds[2] = CRGB(0, 0, 255);
  FastLED.show();
  delay(50);
  leds[5] = CRGB(150, 0, 255);
  FastLED.show();
  delay(50);
  leds[9] = CRGB(255, 200, 20);
  FastLED.show();
  delay(50);
  leds[14] = CRGB(85, 60, 180);
  FastLED.show();
  delay(50);
  leds[19] = CRGB(50, 255, 20);
  FastLED.show();
  delay(50); 
  }

  else if (inkomst == 50){
    bedrag += 50;
    leds[0] = CRGB(255, 0, 0);
  FastLED.show();
  delay(50);  
  leds[1] = CRGB(0, 255, 0);
  FastLED.show();
  delay(50);
  leds[2] = CRGB(0, 0, 255);
  FastLED.show();
  delay(50);
  leds[5] = CRGB(150, 0, 255);
  FastLED.show();
  delay(50);
  leds[9] = CRGB(255, 200, 20);
  FastLED.show();
  delay(50);
  leds[14] = CRGB(85, 60, 180);
  FastLED.show();
  delay(50);
  leds[19] = CRGB(50, 255, 20);
  FastLED.show();
  delay(50);
  }
  
  else if (inkomst == 100){
    bedrag += 100;
    leds[0] = CRGB(255, 0, 0);
  FastLED.show();
  delay(50);  
  leds[1] = CRGB(0, 255, 0);
  FastLED.show();
  delay(50);
  leds[2] = CRGB(0, 0, 255);
  FastLED.show();
  delay(50);
  leds[5] = CRGB(150, 0, 255);
  FastLED.show();
  delay(50);
  leds[9] = CRGB(255, 200, 20);
  FastLED.show();
  delay(50);
  leds[14] = CRGB(85, 60, 180);
  FastLED.show();
  delay(50);
  leds[19] = CRGB(50, 255, 20);
  FastLED.show();
  delay(50);
  }
  
  else if (inkomst == 20){
    bedrag += 20;
    leds[0] = CRGB(255, 0, 0);
  FastLED.show();
  delay(50);  
  leds[1] = CRGB(0, 255, 0);
  FastLED.show();
  delay(50);
  leds[2] = CRGB(0, 0, 255);
  FastLED.show();
  delay(50);
  leds[5] = CRGB(150, 0, 255);
  FastLED.show();
  delay(50);
  leds[9] = CRGB(255, 200, 20);
  FastLED.show();
  delay(50);
  leds[14] = CRGB(85, 60, 180);
  FastLED.show();
  delay(50);
  leds[19] = CRGB(50, 255, 20);
  FastLED.show();
  delay(50);
  }
  else if (inkomst == 5){
    bedrag += 5;
    leds[0] = CRGB(255, 0, 0);
  FastLED.show();
  delay(50);  
  leds[1] = CRGB(0, 255, 0);
  FastLED.show();
  delay(50);
  leds[2] = CRGB(0, 0, 255);
  FastLED.show();
  delay(50);
  leds[5] = CRGB(150, 0, 255);
  FastLED.show();
  delay(50);
  leds[9] = CRGB(255, 200, 20);
  FastLED.show();
  delay(50);
  leds[14] = CRGB(85, 60, 180);
  FastLED.show();
  delay(50);
  leds[19] = CRGB(50, 255, 20);
  FastLED.show();
  delay(50);
  }
  
  else if (inkomst == 10){
    bedrag += 10;
    leds[0] = CRGB(255, 0, 0);
  FastLED.show();
  delay(50);  
  leds[1] = CRGB(0, 255, 0);
  FastLED.show();
  delay(50);
  leds[2] = CRGB(0, 0, 255);
  FastLED.show();
  delay(50);
  leds[5] = CRGB(150, 0, 255);
  FastLED.show();
  delay(50);
  leds[9] = CRGB(255, 200, 20);
  FastLED.show();
  delay(50);
  leds[14] = CRGB(85, 60, 180);
  FastLED.show();
  delay(50);
  leds[19] = CRGB(50, 255, 20);
  FastLED.show();
  delay(50);
  }
  
  else if (inkomst == 2){
    bedrag += 2;
    leds[0] = CRGB(255, 0, 0);
  FastLED.show();
  delay(50);  
  leds[1] = CRGB(0, 255, 0);
  FastLED.show();
  delay(50);
  leds[2] = CRGB(0, 0, 255);
  FastLED.show();
  delay(50);
  leds[5] = CRGB(150, 0, 255);
  FastLED.show();
  delay(50);
  leds[9] = CRGB(255, 200, 20);
  FastLED.show();
  delay(50);
  leds[14] = CRGB(85, 60, 180);
  FastLED.show();
  delay(50);
  leds[19] = CRGB(50, 255, 20);
  FastLED.show();
  delay(50);
  }
  else if (inkomst == 1){
    bedrag += 1;
    leds[0] = CRGB(255, 0, 0);
  FastLED.show();
  delay(50);  
  leds[1] = CRGB(0, 255, 0);
  FastLED.show();
  delay(50);
  leds[2] = CRGB(0, 0, 255);
  FastLED.show();
  delay(50);
  leds[5] = CRGB(150, 0, 255);
  FastLED.show();
  delay(50);
  leds[9] = CRGB(255, 200, 20);
  FastLED.show();
  delay(50);
  leds[14] = CRGB(85, 60, 180);
  FastLED.show();
  delay(50);
  leds[19] = CRGB(50, 255, 20);
  FastLED.show();
  delay(50);
  
  }
  //Serial.println (bedrag);

  }
  /*else if(bedrag() == "500"){
  leds[0] = CRGB(255, 0, 0);
  FastLED.show();
  delay(500);  
  leds[1] = CRGB(0, 255, 0);
  FastLED.show();
  delay(500);
  leds[2] = CRGB(0, 0, 255);
  FastLED.show();
  delay(500);
  leds[5] = CRGB(150, 0, 255);
  FastLED.show();
  delay(500);
  leds[9] = CRGB(255, 200, 20);
  FastLED.show();
  delay(500);
  leds[14] = CRGB(85, 60, 180);
  FastLED.show();
  delay(500);
  leds[19] = CRGB(50, 255, 20);
  FastLED.show();
  delay(500);
  }*/
  
