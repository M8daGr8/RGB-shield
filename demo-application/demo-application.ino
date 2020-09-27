#include "config.h"
#include "init.h"
#include "shieldService.h"

void setup() {
  InitPins();
}

void loop(){
  if(!digitalRead(btnOne) && !digitalRead(btnTwo))
    RainbowCycle();
  
  ReadInputPins();
  UpdateBrightness();
  
  ShowLED();
  TurnoffLed();
}
