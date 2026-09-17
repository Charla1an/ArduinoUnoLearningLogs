#include <Arduino.h>

const int a=2;
const int b=3;
const int c=4;
const int d=5;
const int e=6;
const int f=7;
const int g=8;

int digit=0;

const byte segment[7]={a,b,c,d,e,f,g};

const byte digits[10][7]= {
  {1,1,1,1,1,1,0},
  {0,1,1,0,0,0,0},
  {1,1,0,1,1,0,1},
  {1,1,1,1,0,0,1},
  {0,1,1,0,0,1,1},
  {1,0,1,1,0,1,1},
  {1,0,1,1,1,1,1},
  {1,1,1,0,0,0,0},
  {1,1,1,1,1,1,1},
  {1,1,1,1,0,1,1}
};

const int butPin1=10;
bool but1State;
bool but1Prev=1;

const int butPin2=11;
bool but2State;
bool but2Prev=1;

void displayDigit(int digit) {
  for (int i=0;i<7;i++) {
    digitalWrite(segment[i],digits[digit][i]);
  }
}

void setup() {
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(butPin1,INPUT_PULLUP);
  pinMode(butPin2,INPUT_PULLUP);
}

void loop() {
  but1State=digitalRead(butPin1);
  but2State=digitalRead(butPin2);

  if (but1State==LOW && but1Prev==HIGH) {
    digit++;
    if (digit>9) {
      digit=0;
    }
  }

  else if (but2State==LOW && but2Prev==HIGH) {
    digit--;
    if (digit<0) {
      digit=9;
    }
  }

  but1Prev=but1State;
  but2Prev=but2State;
  displayDigit(digit);
}
