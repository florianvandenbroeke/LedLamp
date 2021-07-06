#include <ColorConverterLib.h>

const int redPin = 5;
const int greenPin = 6;
const int bluePin = 3;
const int soundPin = 12;

const int fadespeed = 5;

const int buttonPin = 4;

int randg = 255;
int randb = 255;
int randr = 255;

int program = 0;

uint8_t r, g, b;
double hue = 0, sat = 1, val = 1;

void setup() {
  
  pinMode(bluePin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  pinMode(buttonPin, INPUT);

  Serial.begin(9600);
  
}

void loop() {

  if (digitalRead(buttonPin)==1) {
    
    program ++;
    program %= 9;
    delay(220); // button debounce
    
  }

  switch (program) {

    // Mode 0: fade
    case 0:
    fade(40);
    break;

    // Mode 1: fixed red
    case 1: 
    color(255, 0, 0);
    break;

    // Mode 2: fixed yellow
    case 2:
    color(255, 255, 0);
    break;
    
    // Mode 3: fixed green
    case 3:
    color(0, 255, 0);
    break;
    
    // Mode 4: fixed teal
    case 4:
    color(0, 255, 255);
    break;
  
    // Mode 5: fixed blue
    case 5:
    color(0, 0, 255);
    break;
  
    // Mode 6: fixed violet
    case 6:
    color(255, 0, 255);
    break;
  
    // Mode 7: fixed white
    case 7:
    color(255, 255, 255);
    break;

    // Mode 8: random sound color change
    case 8:
    if (digitalRead(soundPin) == 1) {
      
    // generate random color
    randg = rand() % 256;
    randb = rand() % 256;
    randr = rand() % 256;
    
    color(randr, randb, randg);
    
    delay(100); 

    }

    break;

  }
    
  Serial.println(program); // print program number for debugging

}

// displays color by rgb value
void color (int red,int green,int blue) {
  
  analogWrite(redPin, red);
  analogWrite(bluePin, blue);
  analogWrite(greenPin, green);
  
}

// fade animation
// each call advances the animation one frame
void fade(int wait) {

  ColorConverter::HsvToRgb(hue, sat, val, r, g, b);

  analogWrite(redPin, r);
  analogWrite(greenPin, g);
  analogWrite(bluePin, b);

  hue += 0.001;
  

  delay(wait);
  
}
