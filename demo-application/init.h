
void InitPins(){  
  Serial.begin(115200);
  
  pinMode(potPin, INPUT);
  pinMode(btnOne, INPUT);
  pinMode(btnTwo, INPUT);
  
  for(int i = 0; i < sizeof(leds) / sizeof(leds[0]); i++){
    pinMode(leds[i], OUTPUT);
  }
}
