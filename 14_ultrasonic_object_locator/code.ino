#include <Servo.h>

Servo radarServo;

int trigPin=10;
int echoPin=9;

const int scanStep=3;

float curDist;
float bestDist;
int bestAngle;

void ping() {
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  curDist=pulseIn(echoPin,HIGH)*0.017;
}

void setup() {
  radarServo.attach(6);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  Serial.begin(9600);
}

void loop() {
  bestDist=1000;

  for (int curAngle = 0; curAngle <= 180; curAngle=curAngle+scanStep) {
    radarServo.write(curAngle);
    delay(15);
    ping();
    if (curDist<bestDist) {
      bestDist=curDist;
      bestAngle=curAngle;
    }
  }

  for (int curAngle = 180; curAngle >= 0; curAngle=curAngle-scanStep) {
    radarServo.write(curAngle);
    delay(15);
    ping();
    if (curDist<bestDist) {
      bestDist=curDist;
      bestAngle=curAngle;
    }
  }

  Serial.print("Closest Object:");
  Serial.print(bestDist);
  Serial.print(" cm at ");
  Serial.print(bestAngle);
  Serial.println(" degrees.");
  Serial.println("----------------------------------------------------------------------------------------------------------------------------------------------------------------------");
  radarServo.write(bestAngle);
  delay(2000);
}
