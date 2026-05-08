int led0=5;
int led1=7;
int led2=9;
int led3=11;
int waitTime=700;

void on(int LED) {
  digitalWrite(LED,HIGH);
  delay(100);
}
void off(int LED) {
  digitalWrite(LED,LOW);
  delay(100);
}

void setup() {
  // put your setup code here, to run once:
pinMode(led0,OUTPUT);
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
off(led3);
off(led2);
off(led1);
off(led0);
delay(waitTime);
off(led3);
off(led2);
off(led1);
on(led0);
delay(waitTime);
off(led3);
off(led2);
on(led1);
off(led0);
delay(waitTime);
off(led3);
off(led2);
on(led1);
on(led0);
delay(waitTime);
off(led3);
on(led2);
off(led1);
off(led0);
delay(waitTime);
off(led3);
on(led2);
off(led1);
on(led0);
delay(waitTime);
off(led3);
on(led2);
on(led1);
off(led0);
delay(waitTime);
off(led3);
on(led2);
on(led1);
on(led0);
delay(waitTime);
on(led3);
off(led2);
off(led1);
off(led0);
delay(waitTime);
on(led3);
off(led2);
off(led1);
on(led0);
delay(waitTime);
on(led3);
off(led2);
on(led1);
off(led0);
delay(waitTime);
on(led3);
off(led2);
on(led1);
on(led0);
delay(waitTime);
on(led3);
on(led2);
off(led1);
off(led0);
delay(waitTime);
on(led3);
on(led2);
off(led1);
on(led0);
delay(waitTime);
on(led3);
on(led2);
on(led1);
off(led0);
delay(waitTime);
on(led3);
on(led2);
on(led1);
on(led0);
}
