// This #include statement was automatically added by the Particle IDE.
#include "dotstar.h"

#define NUMPIXELS 108 // Number of LEDs in strip
#define DATAPIN   A4
#define CLOCKPIN  A5

Adafruit_DotStar strip = Adafruit_DotStar(NUMPIXELS, DATAPIN, CLOCKPIN);


void setup() {
  strip.begin(); // Initialize pins for output
  strip.show();  // Turn all LEDs off ASAP


  Particle.function("lightsOn", turnOnLights);
}


int      head  = 0, tail = -10; // Index of first 'on' and 'off' pixels
uint32_t color = 0xff0000;      // 'On' color (starts red)

void loop() {


}

int turnOnLights(String command) {
     strip.setPixelColor(head, color); // 'On' pixel at head
    //   strip.setPixelColor(tail, 0);     // 'Off' pixel at tail
      strip.show();                     // Refresh strip
      delay(100);                        // Pause 20 milliseconds (~50 FPS)

      if(++head >= NUMPIXELS) {         // Increment head index.  Off end of strip?
        head = 0;                       //  Yes, reset head index to start
        if((color >>= 8) == 0)          //  Next color (R->G->B) ... past blue now?
          color = 0xff0000;             //   Yes, reset to red
      }
      if(++tail >= NUMPIXELS) tail = 0; // Increment, reset tail index
}

int turnOffLights() {
    strip.clear();
}
