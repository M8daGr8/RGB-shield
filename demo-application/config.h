#define potPin A0
#define btnOne 8
#define btnTwo 12

const byte leds[] = { 11, 10, 9 };

byte brightness = 255;
byte dir = 1;

unsigned int fadeRate = 0;
byte currentLed = 0;
byte prevLed = 0;

unsigned long prevMillis = 0;


//Enbart för RainbowCycle

const byte colours[][3] = { 
  { 255, 0, 0 },    // <-- RED
  { 0, 0, 255 },    // <-- GREEN
  { 0, 255, 0 },    // <-- BLUE
  { 255, 255, 0 },  // <-- YELLOW
  { 255, 0, 255 },  // <-- PURPLE
  { 0, 255, 255 }   // <-- CYAN
};

byte values[] = { 0, 0, 0 };

byte colour = 0;
