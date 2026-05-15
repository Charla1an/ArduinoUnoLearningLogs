int led1=11;
int led2=10;
int led3=9;

int butPin=4;
int butState;
int butPrev;

long currentTime;
long randomTime;
long endTime;

void blink(int led) {
  digitalWrite(led,HIGH);
  delay(300);
  digitalWrite(led,LOW);
  delay(200);
}

void allLED(int state) {
  digitalWrite(led1,state);
  digitalWrite(led2,state);
  digitalWrite(led3,state);
}

void setup() {
  Serial.begin(9600);
  pinMode(butPin,INPUT_PULLUP);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  randomSeed(A5);
  randomTime=random(3000,10000);
  blink(led1);
  blink(led2);
  blink(led3);
  allLED(HIGH);
  delay(300);
  allLED(LOW);
}

void loop() {
  butState=digitalRead(butPin);
  currentTime=millis();
  if (currentTime>=randomTime) {
    allLED(HIGH);
  }
  if (butState==LOW && butPrev==HIGH) {
    endTime=currentTime-randomTime;
  }
  butPrev=butState;
  if (endTime>0) {
    Serial.print("Your reaction time is: ");
    Serial.print(endTime);
    Serial.println("ms");
  }
  else if (endTime<0) {
    Serial.println("false start, skill issue");
  }
}
