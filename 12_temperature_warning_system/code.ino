int tempPin=A2;
int tempVal;

int rPin=11;
int gPin=10;
int bPin=9;

int buzzPin=5;

bool flashing=false;
long eventTime=0;

void setup() {
  Serial.begin(9600);
  pinMode(rPin,OUTPUT);
  pinMode(gPin,OUTPUT);
  pinMode(bPin,OUTPUT);
  pinMode(buzzPin,OUTPUT);
  // RGB LED is common anode, so PWM values are inverted
  analogWrite(rPin,255);
  analogWrite(gPin,255);
  analogWrite(bPin,255);
}

void loop() {
  tempVal=analogRead(tempPin);
  Serial.println(tempVal);
  long currentTime=millis();

  if (tempVal<600) {
    analogWrite(rPin,255);
    analogWrite(gPin,180);
    analogWrite(bPin,255);
  }
  else if (tempVal<680) {
    analogWrite(rPin,0);
    analogWrite(gPin,90);
    analogWrite(bPin,255);
    flashing=false;
  }
  else if (tempVal>680 && flashing==false) {
    eventTime=currentTime;
    flashing=true;
  }
  if (flashing) {
    if (currentTime-eventTime<1050) {
      analogWrite(rPin,0);
      analogWrite(gPin,255);
      analogWrite(bPin,255);
      tone(buzzPin,2800,1000);
    }
    else if (currentTime-eventTime<2050) {
      analogWrite(rPin,255);
      analogWrite(gPin,255);
      analogWrite(bPin,255);
      noTone(buzzPin);
    }
    else {
      eventTime=currentTime;
    }
  }
  if (tempVal<680) {
    flashing=false;
  }
}
