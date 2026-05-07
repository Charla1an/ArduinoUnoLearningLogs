int buttonPin=10;
int buttonState;
int redPin=6;


void setup() {
  pinMode(buttonPin,INPUT_PULLUP);
  pinMode(redPin,OUTPUT);
}

void loop() {
  buttonState=digitalRead(buttonPin);
  if (buttonState==0) {
    digitalWrite(redPin,HIGH);
  }
  else {
    digitalWrite(redPin,LOW);
  }
}
