int sensorPin=A2;
int redPin=6;
int sensorValue;
int brightness;


void setup() {
pinMode(redPin,OUTPUT);
Serial.begin(9600);
}

void loop() {
  sensorValue=analogRead(sensorPin);
  brightness=(sensorValue/1023.)*255;
  analogWrite(redPin,brightness);
  Serial.print("Brightness: ");
  Serial.println(brightness);
  delay(30);
}
