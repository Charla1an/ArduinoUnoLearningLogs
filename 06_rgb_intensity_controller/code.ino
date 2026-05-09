int rPin=11;
int gPin=10;
int bPin=9;

int rButPin=7;
bool rButState;
bool rButPrev=true;
int rBright;

int gButPin=6;
bool gButState;
bool gButPrev=true;
int gBright;

int bButPin=5;
bool bButState;
bool bButPrev=true;
int bBright;

String selectedChannel;

int potReadPin=A2;
int potVal;

int dt=50;

void setup() {
  pinMode(rButPin,INPUT_PULLUP);
  pinMode(gButPin,INPUT_PULLUP);
  pinMode(bButPin,INPUT_PULLUP);
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  analogWrite(rPin,255);
  analogWrite(gPin,255);
  analogWrite(bPin,255);
}

void loop() {

  potVal=analogRead(potReadPin);

  rButState=digitalRead(rButPin);
  gButState=digitalRead(gButPin);
  bButState=digitalRead(bButPin);
  if (rButState==LOW && rButPrev==HIGH) {
    selectedChannel="red";
  }
  else if (gButState==LOW && gButPrev==HIGH) {
    selectedChannel="green";
  }
  else if (bButState==LOW && bButPrev==HIGH) {
    selectedChannel="blue";
  }

  if (selectedChannel=="red") {
    rBright=map(potVal,0,1023,255,0);
  }
  if (selectedChannel=="green") {
    gBright=map(potVal,0,1023,255,0);
  }
  if (selectedChannel=="blue") {
    bBright=map(potVal,0,1023,255,0);
  }
  analogWrite(rPin,rBright);
  analogWrite(gPin,gBright);
  analogWrite(bPin,bBright);
  rButPrev=rButState;
  gButPrev=gButState;
  bButPrev=bButState;
  delay(dt);
}
