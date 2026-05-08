int buttonPin=10;
int buttonState;
int prevButtonState=1;
int redPin=6;

bool ledState=false;

void setup() {
  pinMode(buttonPin,INPUT_PULLUP);
  pinMode(redPin,OUTPUT);
}

void loop() {
  buttonState=digitalRead(buttonPin);
    if (prevButtonState==HIGH && buttonState==LOW) {
        ledState=!ledState;
        digitalWrite(redPin,ledState);
    }
  prevButtonState=buttonState;
}
