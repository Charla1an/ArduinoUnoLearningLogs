int rPin=11;
int gPin=10;
int bPin=9;
int redVal;
int greenVal;
int blueVal;

String colour;

void setColour(int r,int g,int b) {
  if (r<0) {
    r=0;
  }
  if (g<0) {
    g=0;
  }
  if (b<0) {
    b=0;
  }
  if (r>255) {
    r=255;
  }
  if (g>255) {
    g=255;
  }
  if (b>255) {
    b=255;
  }
  analogWrite(rPin,255-r);
  analogWrite(gPin,255-g);
  analogWrite(bPin,255-b);
}

void setup() {
  Serial.begin(9600);
  pinMode(rPin,OUTPUT);
  pinMode(gPin,OUTPUT);
  pinMode(bPin,OUTPUT);
  analogWrite(rPin,255);
  analogWrite(gPin,255);
  analogWrite(bPin,255);
}

void loop() {
  Serial.println("What colour?  (input should be made in lower case)");
  Serial.println("The preloaded colours are: red, green, blue, aqua, violet, and custom");
  while (Serial.available()==0) {

  }
  colour=Serial.readString();
  if (colour=="red") {
    setColour(255,0,0);
  }
  else if (colour=="green") {
    setColour(0,255,0);
  }
  else if (colour=="blue") {
    setColour(0,0,255);
  }
  else if (colour=="aqua") {
    setColour(0,255,255);
  }
  else if (colour=="violet") {
    setColour(128,0,255);
  }
  else if (colour=="custom") {
    Serial.println("Put in the value for Red");
    while (Serial.available()==0) {

    }
    redVal=Serial.parseInt();
    Serial.println("Put in the value for Green");
    while (Serial.available()==0) {

    }
    greenVal=Serial.parseInt();
    Serial.println("Put in the value for Blue");
    while (Serial.available()==0) {

    }
    blueVal=Serial.parseInt();
    setColour(redVal,greenVal,blueVal);
  }
  else if (colour=="off") {
  setColour(0,0,0);
  }
}
