#include <Arduino.h>

constexpr byte RELAY_PIN= 9;
constexpr byte BUTTON_PIN= 5;

bool butS; //button current state
bool butP=HIGH; //button previos state

bool relayS=false; //relay state
void setup() {
  pinMode(RELAY_PIN,OUTPUT);
  pinMode(BUTTON_PIN,INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() { 
  butS=digitalRead(BUTTON_PIN);
  if (butS== LOW && butP== HIGH) {
    relayS=!relayS;
    Serial.println(relayS ? "Relay: ON" : "Relay: OFF");
  }
  digitalWrite(RELAY_PIN,relayS);
  butP=butS;
}