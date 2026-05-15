int rPin=11;
int gPin=10;
int bPin=9;

String inputC;
int inputB;

int brightness;
int red;
int green;
int blue;

void colour(int r,int g,int b) {
  red=255-((inputB/100.)*r);
  green=255-((inputB/100.)*g);
  blue=255-((inputB/100.)*b);
  analogWrite(rPin,red);
  analogWrite(gPin,green);
  analogWrite(bPin,blue);
}

void setup() {
  pinMode(rPin,OUTPUT);
  pinMode(gPin,OUTPUT);
  pinMode(bPin,OUTPUT);
  Serial.begin(9600);
}
void loop() {
  Serial.println("Which colour do you want?");
  while (Serial.available()==0) {

  }
  inputC=Serial.readString();
  
  Serial.println("Enter your brightness");
  while (Serial.available()==0) {

  }
  inputB=Serial.parseInt();
  inputB=constrain(inputB,0,100);

  if (inputC=="red") {
    colour(255,0,0);
  }
  else if (inputC=="green") {
    colour(0,255,0);
  }
  else if (inputC=="blue") {
    colour(0,0,255);
  }
  else if (inputC=="cyan") {
    colour(0,255,255);
  }
  else if (inputC=="yellow") {
    colour(255,255,0);
  }
  else if (inputC=="magenta") {
    colour(255,0,255);
  }
}
