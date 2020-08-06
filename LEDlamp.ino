const int bluePin = 3;
const int redPin = 5;
const int greenPin = 6;
const int soundPin = 12;
const int fadespeed = 5;
const int buttonPin = 4;


bool toggle = false;
int randg = 255;
int randb = 255;
int randr = 255;
int program = 1;
int r, g, b;

void setup() {
  pinMode(bluePin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void color (int red,int green,int blue) {
  analogWrite(redPin, red);
  analogWrite(bluePin, blue);
  analogWrite(greenPin, green);
  }

void loop() {

  //Button updater
  if (digitalRead(buttonPin)==1) {
    program ++;
    program = program % 10;
    delay(200);
    }

  //Mode  0: fading through each color
  if (program == 0) {

    for (r = 0; r < 256; r++) {
      analogWrite(redPin, r);
      delay(fadespeed);
      }

    for (b = 255; b > 0; b--) {
      analogWrite(bluePin, b);
      delay(fadespeed);
      }

    for (g = 0; g < 256; g++) {
      analogWrite(greenPin, g);
      delay(fadespeed);
      }

    for (r = 255; r > 0; r--) {
      analogWrite(redPin, r);
      delay(fadespeed);
      }

    for (b = 0; b < 256; b++) {
      analogWrite(bluePin, b);
      delay(fadespeed);
      }

    for (g = 255; g > 0; g--) {
      analogWrite(greenPin, g);
      delay(fadespeed);
      }

  }

  // Mode 1: fixed red
  if (program == 1) {
    color(255, 0, 0);
    } 

  // Mode 2: fixed yellow
  if (program == 2) {
    color(255, 255, 0);
    }

  // Mode 3: fixed green
  if (program == 3) {
    color(0, 255, 0);
    }

  // Mode 4: fixed teal
  if (program == 4) {
    color(0, 255, 255);
    }

  // Mode 5: fixed blue
  if (program == 5) {
    color(0, 0, 255);
    }

  // Mode 6: fixed violet
  if (program == 6) {
    color(255, 0, 255);
    }

  // Mode 7: fixed white
  if (program == 7) {
    color(255, 255, 255);
    }

  // Mode 8: random sound color change
  if (program == 8) {

    if (digitalRead(soundPin) == 1) {
    randg = rand() % 256;
    randb = rand() % 256;
    randr = rand() % 256;
    color(randr, randb, randg);
    delay(100); 
      }
    
    }

  if (program == 9) {
    int  c = 11016574;
  
  r = c % 256;
  g = (c /256) % 256;
  b = c / 256;

  color(0, 0, b);
    }

}
