// This #include statement was automatically added by the Particle IDE.
#include "dotstar.h"

#define NUMPIXELS 109 // Number of LEDs in strip
#define DATAPIN   A4
#define CLOCKPIN  A5

Adafruit_DotStar strip = Adafruit_DotStar(NUMPIXELS, DATAPIN, CLOCKPIN);


void setup() {
  strip.begin(); // Initialize pins for output
  strip.show();  // Turn all LEDs off ASAP


  Particle.function("lightsOn", turnOnLights);
  Particle.function("lightsOff", turnOffLights);
}


int      head  = 0, tail = -10; // Index of first 'on' and 'off' pixels
uint32_t color = 0xff0000;      // 'On' color (starts red)

void loop() {


}

int turnOnLights(String command) {
  int i = 0;

  for (i; i < NUMPIXELS; i++) {
    strip.setPixelColor(i, color);
  }
  strip.show();
  return 1;
}

int turnOffLights(String command) {
  strip.clear();
  strip.show();

  return 1;
}
