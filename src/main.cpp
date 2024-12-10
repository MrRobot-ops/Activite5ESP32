#include <Arduino.h>

const int Full_trame = 11;
int trame[Full_trame];
int compteur = 0;
int tab[5];
int carte[5] = {0xC, 0x0, 0x42, 0x16, 0x94};

void setup() {
  Serial.begin(9600);
}

void loop() {}

void serialEvent() {
  while (Serial.available()) {
    trame[compteur] = Serial.read();
    compteur++;
    if (compteur == Full_trame) {
      for (int i = 0; i < Full_trame; i++) {
        Serial.print(trame[i], HEX);
        Serial.print(" ");
      }
      Serial.println();
      compteur = 0;
    }
  }
}
