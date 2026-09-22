#include <Arduino.h>

constexpr byte SRCLK=13; // clock
constexpr byte RCLK=7;  // latch
constexpr byte SER=6;    // output

constexpr byte CLK=2;
constexpr byte DT=3;
constexpr byte SW=5;

volatile byte currentEncoderState;
byte previousEncoderState;

int counter=0;

bool buttonState;
bool buttonPrevState=1;

const byte digits[10]={
  0b01111110,
  0b00011000,
  0b10110110,
  0b10111100,
  0b11011000,
  0b11101100,
  0b11101110,
  0b00111000,
  0b11111110,
  0b11111100
};

void encoderISR() {
  currentEncoderState=(digitalRead(CLK)<<1) | digitalRead(DT);
}

void setup() {

  pinMode(SRCLK,OUTPUT);
  pinMode(RCLK,OUTPUT);
  pinMode(SER,OUTPUT);

  pinMode(CLK, INPUT);
  pinMode(DT, INPUT);
  pinMode(SW,INPUT_PULLUP);

  previousEncoderState = (digitalRead(CLK) << 1) | digitalRead(DT);
 
  attachInterrupt(digitalPinToInterrupt(CLK), encoderISR, CHANGE);

}

void loop() {

  buttonState=digitalRead(SW);

  if (currentEncoderState != previousEncoderState) {
    
    if ((previousEncoderState==0b11 && currentEncoderState==0b0) || (previousEncoderState==0b0 && currentEncoderState==0b11) || (previousEncoderState==0b1 && currentEncoderState==0b11) || (previousEncoderState==0b10 && currentEncoderState==0b0)) {
      counter--;
    }
    
    else if ((previousEncoderState==0b1 && currentEncoderState==0b10) || (previousEncoderState==0b10 && currentEncoderState==0b1) || (previousEncoderState==0b11 && currentEncoderState==0b1) || (previousEncoderState==0b0 && currentEncoderState==0b10)) {
      counter++;
    }
    
    previousEncoderState = currentEncoderState;
  }

  if (buttonPrevState==1 && buttonState==0) {
    counter=0;
  }

  if (counter>9) {
    counter=9;
  }
  if (counter<0) {
    counter=0;
  }



  digitalWrite(RCLK,LOW);
  shiftOut(SER,SRCLK,LSBFIRST,digits[counter]);
  digitalWrite(RCLK,HIGH);

  buttonPrevState=buttonState;
}