#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

constexpr byte TRIG_PIN=5;
constexpr byte ECHO_PIN=6;

long pulseDuration=0;

int sum=0;
int count=0;
int distanceCm;
int previousDistanceCm;
int avgDistanceCm;
bool avg;

String status;

unsigned long currentT;       //current time
unsigned long e1S=0;          //event 1 Start
unsigned long e1=500;         //event 1 interval

byte upArrow[8] = {
  B00100,
  B01110,
  B10101,
  B00100,
  B00100,
  B00100,
  B00100,
  B00000
};

byte downArrow[8] = {
  B00100,
  B00100,
  B00100,
  B00100,
  B10101,
  B01110,
  B00100,
  B00000
};

void setup() {
  pinMode(TRIG_PIN,OUTPUT);
  pinMode(ECHO_PIN,INPUT);
  lcd.init();
  lcd.backlight();
  lcd.createChar(0, upArrow);
  lcd.createChar(1, downArrow);
  Serial.begin(9600);
}

void loop() {
 currentT=millis();

// Calculate Distance

  if (currentT-e1S<e1) {
    if (currentT-e1S<450) {
      digitalWrite(TRIG_PIN,LOW);
      delayMicroseconds(2);
      digitalWrite(TRIG_PIN,HIGH);
      delayMicroseconds(10);
      digitalWrite(TRIG_PIN,LOW);
      
      pulseDuration=pulseIn(ECHO_PIN,HIGH);
      delay(2);
      distanceCm=pulseDuration/58;
      sum += distanceCm;
      count++;
      avg=1;
    }
    else if (currentT-e1S>450 && currentT-e1S<500 && avg==1) {
      avgDistanceCm=sum/count;
      sum=0;
      count=0;
      avg=0;
    }
  }

  else {
    e1S=currentT;
  } 

// Determine Status
  
  if (avgDistanceCm<10) {
    status="DANGER";
  }
  else {
    status="SAFE  ";
  }

// Display Update

  lcd.setCursor(0,0);
  lcd.print("Distance:");
  lcd.setCursor(9,0);
  lcd.print(avgDistanceCm);

  if (avgDistanceCm<10) {
    lcd.setCursor(10,0);
    lcd.print("cm");
    lcd.setCursor(12,0);
    lcd.print("   ");
  }
  else if (avgDistanceCm>=10 && avgDistanceCm<100) {
    lcd.setCursor(11,0);
    lcd.print("cm");
    lcd.setCursor(13,0);
    lcd.print("  ");

  }
  else if (avgDistanceCm>=100) {
    lcd.setCursor(12,0);
    lcd.print("cm");
    lcd.setCursor(14,0);
    lcd.print(" ");
  }
  
  lcd.setCursor(15,0);
  if (avgDistanceCm < previousDistanceCm) {
    lcd.write(byte(1));   
  } 
  else if (avgDistanceCm > previousDistanceCm) {
    lcd.write(byte(0));   
  }
  else {
    lcd.print("=");       
  } 

  lcd.setCursor(0,1);
  lcd.print("STATUS:");
  
  lcd.setCursor(7,1);
  lcd.print(status);

  previousDistanceCm=avgDistanceCm;
}