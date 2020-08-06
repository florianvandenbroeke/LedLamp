#include <ColorConverterLib.h>

const int bluePin = 3;
const int redPin = 5;
const int greenPin = 6;

uint8_t red, green, blue;

double hue = 0;
double sat = 1;
double val = 1;

void setup() {
  
  pinMode(bluePin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  Serial.begin(9600);
  
}


void loop() {

  analogWrite(redPin, 255);

}

void fade() {

  ColorConverter::HsvToRgb(hue, sat, val, red, green, blue);

  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);

  hue += 0.01;

  delay(50);
  
}
