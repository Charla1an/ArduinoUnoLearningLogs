int redPin=6;
int brightness;
int delayTime=20;

void setup() {
  pinMode(redPin,OUTPUT);
}

void loop() {
  for (brightness=0;brightness<=255;brightness=brightness+1) {
    analogWrite(redPin,brightness);
    delay(delayTime);
  }
  for (brightness=255;brightness>=0;brightness=brightness-1) {
    analogWrite(redPin,brightness);
    delay(delayTime);
  }
}
