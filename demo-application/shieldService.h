void ReadInputPins(){
  fadeRate = map(analogRead(potPin), 0, 1023, 2, 20);
  
  prevLed = currentLed;
  
  if(digitalRead(btnOne))
    currentLed = 1;
  else if(digitalRead(btnTwo))
    currentLed = 2;
  if(digitalRead(btnOne) && digitalRead(btnTwo))
    currentLed = 0;
}

void UpdateBrightness(){
  if(millis() - prevMillis >= fadeRate){
    if(brightness >= 255 || brightness <= 10)
      dir *= -1;
    brightness += dir;
    prevMillis = millis();
  }
}

void TurnoffLed(){
  if(prevLed != currentLed)
    analogWrite(leds[prevLed], 0);
}

void RainbowCycle(){
  while(true){
    if(colour >= sizeof(colours) / sizeof(colours[0]))
      colour = 0;
        
    while(values[0] != colours[colour][0] || values[1] != colours[colour][1] || values[2] != colours[colour][2]){
      if(millis() - prevMillis >= fadeRate){
        for(int i = 0; i < sizeof(values) / sizeof(values[0]); i++){
          if(values[i] < colours[colour][i])
            values[i] += 1;
          else if(values[i] > colours[colour][i])
            values[i] -=1;
        }
        for(int i = 0; i < sizeof(leds) / sizeof(leds[0]); i++){
          analogWrite(leds[i], 0);
          analogWrite(leds[i], values[i]);
        }
        ReadInputPins();
        prevMillis = millis();
      }
      
      if(digitalRead(btnOne) || digitalRead(btnTwo)){
        for(int i = 0; i < sizeof(leds) / sizeof(leds[0]); i++)
          analogWrite(leds[i], 0); 
        return;
      }
    }
    colour++;
  }
}

void ShowLED(){    
  analogWrite(leds[currentLed], brightness);
}
