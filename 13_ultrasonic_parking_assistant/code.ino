int trigPin=12;
int echoPin=11;

int rPin=4;
int yPin=5;
int gPin=6;

int buzzPin=8;

unsigned long event1=0;
unsigned long event2=0;
unsigned long event3=0;

const int danger_dist=100;
const int warning_dist=200;
const int safe_dist=300;

const int buzzer_freq=2700;

void ledMode(int r,int y,int g) {
  digitalWrite(rPin,r);
  digitalWrite(yPin,y);
  digitalWrite(gPin,g);
}

void setup() {
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(rPin,OUTPUT);
  pinMode(yPin,OUTPUT);
  pinMode(gPin,OUTPUT);
  pinMode(buzzPin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  float distance=pulseIn(echoPin,HIGH)*0.017;
  Serial.println(distance);
  unsigned long currentTime=millis();

  if (distance<danger_dist) {
    if (currentTime-event1<=100) {
      ledMode(1,0,0);
      tone(buzzPin,buzzer_freq);
    }
    else if (currentTime-event1<=200) {
      ledMode(0,0,0);
      noTone(buzzPin);
    }
    else {
      event1=currentTime;
    }
  }
  else if (distance<warning_dist) {
    ledMode(0,1,0);
    if (currentTime-event2<=300) {
      tone(buzzPin,buzzer_freq);
    }
    else if (currentTime-event2<=600) {
      noTone(buzzPin);
    }
    else {
      event2=currentTime;
    }
  }
  else if (distance<safe_dist) {
    ledMode(0,0,1);
    if (currentTime-event3<300) {
      tone(buzzPin,buzzer_freq);
    }
    else if (currentTime-event3<1000) {
      noTone(buzzPin);
    }
    else {
      event3=currentTime;
    }
  }
  else {
    ledMode(0,0,1);
    noTone(buzzPin);
  }
}
