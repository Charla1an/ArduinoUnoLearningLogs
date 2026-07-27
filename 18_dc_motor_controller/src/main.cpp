#include <Arduino.h>

constexpr byte DIR1= 7;  //Direction Pin 1
constexpr byte DIR2= 6;  //Direction Pin 2
constexpr byte SPEED_PIN= 11;
constexpr byte POTENTIOMETER_PIN= A1;
constexpr byte BUTTON_FOR= 3;
constexpr byte BUTTON_REV= 4;
constexpr byte BUTTON_STOP= 2;

bool butF;         // forward button
bool butFP=HIGH;   // forward button previous state

bool butR;         // reverse button
bool butRP=HIGH;   // reverse button previous state

bool butS;         // stop button
bool butSP=HIGH;   // stop button previous state

enum direction {
  FORWARD,
  REVERSE,
  STOP
};

direction motorDir=STOP;

void setup() {
  pinMode(DIR1,OUTPUT);
  pinMode(DIR2,OUTPUT);
  pinMode(SPEED_PIN,OUTPUT);
  pinMode(POTENTIOMETER_PIN,INPUT);
  
  pinMode(BUTTON_FOR,INPUT_PULLUP);
  pinMode(BUTTON_REV,INPUT_PULLUP);
  pinMode(BUTTON_STOP,INPUT_PULLUP);

  Serial.begin(9600);
}

void setDirection(direction dir) {
  switch(dir) {
    case FORWARD:
      digitalWrite(DIR1,0);
      digitalWrite(DIR2,1);
      break;
    case REVERSE:
      digitalWrite(DIR1,1);
      digitalWrite(DIR2,0);
      break;

    case STOP:
      digitalWrite(DIR1,0);
      digitalWrite(DIR2,0);
      break;
  }
}

void loop() {
  butF=digitalRead(BUTTON_FOR);
  butR=digitalRead(BUTTON_REV);
  butS=digitalRead(BUTTON_STOP);


  int pVal=analogRead(POTENTIOMETER_PIN);
  int speed=map(pVal,0,1023,175,255);
  analogWrite(SPEED_PIN,speed);

  if (butF==LOW && butFP==HIGH) {
    motorDir=FORWARD;
  }
  else if (butR==LOW && butRP==HIGH) {
    motorDir=REVERSE;
  }
  else if (butS==LOW && butSP==HIGH) {
    motorDir=STOP;
  }
  
  setDirection(motorDir);
  
  butSP=butS;
  butFP=butF;
  butRP=butR;
}