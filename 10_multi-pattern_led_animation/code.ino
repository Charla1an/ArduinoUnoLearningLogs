int leds[]={10,9,8,7,6,5,4,3};

int but1Pin=11;
bool but1State;
bool but1Prev;

int but2Pin=12;
bool but2State;
bool but2Prev;

int but3Pin=13;
bool but3State;
bool but3Prev;

void evenMode() {
  for (int i=0;i<7;i=i+2) {
    digitalWrite(leds[i],HIGH);
    digitalWrite(leds[i+1],LOW);
  }
}

void oddMode() {
  for (int i=1;i<8;i=i+2) {
    digitalWrite(leds[i],HIGH);
    digitalWrite(leds[i-1],LOW);
  }
}

void clearLED() {
  for (int i=0;i<8;i++) {
    digitalWrite(leds[i],LOW);
  }
}
void setup() {
  for (int j=0;j<8;j++) {
    pinMode(leds[j],OUTPUT);
  }
  pinMode(but1Pin,INPUT_PULLUP);
  pinMode(but2Pin,INPUT_PULLUP);
  pinMode(but3Pin,INPUT_PULLUP);
}

void loop() {
  but1State=digitalRead(but1Pin);
  but2State=digitalRead(but2Pin);
  but3State=digitalRead(but3Pin);

  if (but1State==LOW && but1Prev==HIGH) {
    for (int i=0;i<8;i++) {
      int j=i-1;
      constrain(j,0,7);
      digitalWrite(leds[i],HIGH);
      digitalWrite(leds[j],LOW);
      delay(100);
    }
    for (int i=7;i>-1;i--) {
      int k=i+1;
      constrain(k,0,7);
      digitalWrite(leds[i],HIGH);
      digitalWrite(leds[k],LOW);
      delay(100);
    }
    clearLED();
  }
  
  if (but2State==LOW && but2Prev==HIGH) {
    for (int cycle=0;cycle<8;cycle++){
      evenMode();
      delay(100);
      oddMode();
      delay(100);
    }
    clearLED();
  }
  
  if (but3State==LOW && but3Prev==HIGH) {
    for (int num=0;num<256;num++) {
      for (int i=0;i<8;i++) {
        digitalWrite(leds[i],bitRead(num,i));
      }
      delay(200);
    }
    clearLED();
  }

  but1Prev=but1State;
  but2Prev=but2State;
  but3Prev=but3State;
}
