#include <Arduino.h>

void setup() {
  Serial.begin(9600);
}

void loop() {}

void serialEvent() {
  int donnee = Serial.read();
  Serial.print(donnee, HEX);
  Serial.print(" ");
}
