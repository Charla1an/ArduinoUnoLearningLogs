int rPin=11;
int yPin=10;
int gPin=9;

// Time compression used for testing:
// 10 seconds represents 1 simulated hour

int cycle=0;
int rEnd=3000;
int yEnd=5000;
int gEnd=10000;
unsigned long currentTime;
unsigned long interval;
unsigned long elapsed;

void setup() {
  pinMode(rPin,OUTPUT);
  pinMode(yPin,OUTPUT);
  pinMode(gPin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  currentTime=millis();
  elapsed=currentTime-interval;
  if (cycle%24>=8 && cycle%24<=21) {
    if (elapsed<rEnd) {
      digitalWrite(rPin,HIGH);
      digitalWrite(yPin,LOW);
      digitalWrite(gPin,LOW);
    }
    else if (elapsed<yEnd) {
      digitalWrite(rPin,LOW);
      digitalWrite(yPin,HIGH);
      digitalWrite(gPin,LOW);
    }
    else if (elapsed<gEnd) {
      digitalWrite(rPin,LOW);
      digitalWrite(yPin,LOW);
      digitalWrite(gPin,HIGH);
    }
    else if (elapsed>10000) {
    interval=interval+10000;
    cycle=cycle+1;
    }
  }
  else if (cycle%24<8 || cycle%24>21) {
    digitalWrite(yPin,HIGH);
    delay(200);
    digitalWrite(yPin,LOW);
    delay(200);
    digitalWrite(rPin,LOW);
    digitalWrite(gPin,LOW);
    if (elapsed>10000) {
      interval=interval+10000;
      cycle=cycle+1;
    }
  }
  Serial.print(currentTime);
  Serial.print(" and ");
  Serial.println(cycle);
}
