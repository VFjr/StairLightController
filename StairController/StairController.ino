//parameters:

int brightness = 10; // 0 to 255
int interval = 30; //in ms
unsigned long stayOnTime = 10*1000; //in ms
int intervalsPerStair = 10; 

//pin declarations:
int LED1 = 2;
int LED2 = 3;
int LED3 = 4;
int LED4 = 5;
int LED5 = 6;
int LED6 = 7;
int LED7 = 8;
int LED8 = 9;
int LED9 = 10;
int LED10 = 11;
int LED11 = 12;
int LED12 = 13;
int LED13 = 44;
int LED14 = 45;
int PIR_UP = 36;
int PIR_DOWN = 34;

// other declarations
int stairLeds[14];
unsigned long previousMillis = 0;

void fallSequence();
void riseSequence();
void stayONsequence();
void riseOffSequence();
void fallOffSequence();

void setup() {
  pinMode(PIR_UP, INPUT);
  pinMode(PIR_DOWN, INPUT);
  
}

void loop() {

    if(digitalRead(PIR_UP)){
      
      fallSequence();
      stayONsequence();
      riseOffSequence();

      
    }

 
    if(digitalRead(PIR_DOWN)){
      riseSequence();
      stayONsequence();
      fallOffSequence();

      
    }

}

void riseSequence(){
  for (int i = 13; i >= 0; i--){//corresponds to led index

    for (int j = 1; j <= intervalsPerStair; j++){
      stairLeds[i] = (j*brightness)/intervalsPerStair;
      updateLEDs();
      delay(interval);
    }
  }
}

void fallSequence(){
  for (int i = 0; i <14; i++){//corresponds to led index
    
    for (int j = 1; j <= intervalsPerStair; j++){
      stairLeds[i] = (j*brightness)/intervalsPerStair;
      updateLEDs();
      delay(interval);
    }
  }
}

void riseOffSequence(){
  for (int i = 13; i >= 0; i--){//corresponds to led index

    for (int j = 1; j <= intervalsPerStair; j++){
      stairLeds[i] = ((intervalsPerStair-j)*brightness)/intervalsPerStair;
      updateLEDs();
      delay(interval);
    }
  }
}

void fallOffSequence(){
  for (int i = 0; i <14; i++){//corresponds to led index
    
    for (int j = 1; j <= intervalsPerStair; j++){
      stairLeds[i] = ((intervalsPerStair-j)*brightness)/intervalsPerStair;
      updateLEDs();
      delay(interval);
    }
  }
}

void updateLEDs(){
  analogWrite(LED1, stairLeds[0]);
  analogWrite(LED2, stairLeds[1]);
  analogWrite(LED3, stairLeds[2]);
  analogWrite(LED4, stairLeds[3]);
  analogWrite(LED5, stairLeds[4]);
  analogWrite(LED6, stairLeds[5]);
  analogWrite(LED7, stairLeds[6]);
  analogWrite(LED8, stairLeds[7]);
  analogWrite(LED9, stairLeds[8]);
  analogWrite(LED10, stairLeds[9]);
  analogWrite(LED11, stairLeds[10]);
  analogWrite(LED12, stairLeds[11]);
  analogWrite(LED13, stairLeds[12]);
  analogWrite(LED14, stairLeds[13]);
}

void stayONsequence(){
  
  updateLEDs();

  int currentMillis2 = millis();
  int lastInteractionMillis = currentMillis2;

  while (currentMillis2 - lastInteractionMillis <= stayOnTime){

    if(digitalRead(PIR_UP) || digitalRead(PIR_DOWN)){
      lastInteractionMillis = currentMillis2;
    }

    currentMillis2 = millis();
  }  
}
