#include <Arduino.h>

int greenLED=7;
int redLED=6;

int latchPin=10;
int clockPin=11;
int dataPin=9;

int butPinL=2;
bool butStateL;
bool butPrevL=1;

int butPinR=3;
bool butStateR;
bool butPrevR=1;

int numL;
int numR;

bool complete=0;

const byte digits[10]={
    0b11111100,
    0b01100000,
    0b11011010,
    0b11110010,
    0b01100110,
    0b10110110,
    0b10111110,
    0b11100000,
    0b11111110,
    0b11110110
};

void setup() {
    pinMode(latchPin,OUTPUT);
    pinMode(clockPin,OUTPUT);
    pinMode(dataPin,OUTPUT);
    pinMode(butPinL,INPUT_PULLUP);
    pinMode(butPinR,INPUT_PULLUP);
    randomSeed(analogRead(A5));
    numL=random(0,10);
    numR=random(0,10);    
    Serial.begin(9600);
    pinMode(greenLED,OUTPUT);
    pinMode(redLED,OUTPUT);
}

void loop() {
    digitalWrite(redLED,LOW);
    digitalWrite(greenLED,LOW);

    butStateL=digitalRead(butPinL);
    butStateR=digitalRead(butPinR);
    
    digitalWrite(latchPin,LOW);
    shiftOut(dataPin,clockPin,LSBFIRST,digits[numL]);
    shiftOut(dataPin,clockPin,LSBFIRST,digits[numR]);
    digitalWrite(latchPin,HIGH);

    if (numL>numR) {
        if (butStateL==LOW  && butPrevL==HIGH) {
            digitalWrite(greenLED,HIGH);
            complete=true;
            delay(3000);
        }
        else if (butStateR==LOW && butPrevR==HIGH) {
            digitalWrite(redLED,HIGH);
            complete=true;
            delay(3000);
        }
    } 
    else if (numL<numR) {
        if (butStateL==LOW  && butPrevL==HIGH) {
            digitalWrite(redLED,HIGH);
            complete=true;
            delay(3000);
        }
        else if (butStateR==LOW && butPrevR==HIGH) {
            digitalWrite(greenLED,HIGH);
            complete=true;
            delay(3000);
        }
    }
    else if (numL==numR) {
        complete=true;
    }
    butPrevL=butStateL;
    butPrevR=butStateR;

    if (complete) {
        numL=random(0,10);
        numR=random(0,10);
        complete=false;
    }
}
