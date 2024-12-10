#include <Arduino.h>

const int Full_trame = 11;
int trame[Full_trame];
int compteur = 0;
int tab[5];
int carte[5] = { 0xC, 0x0, 0x42, 0x16, 0x94 };

void setup() {
  Serial.begin(9600);
  Serial2.begin(9600, SERIAL_8N1, 2, -1); // RX sur port 2, TX désactivé (-1)
  Serial.println("Systeme verouiller, presenter badge");
}

void loop() {}

void serialEventRun() {
  while (Serial2.available()) {
    trame[compteur] = Serial2.read();
    compteur++;
    if (compteur == Full_trame) {
      for (int i = 0; i < 5; i++) {
        tab[i] = trame[i + 3];
      }

      bool whitelist = true;
      for (int i = 0; i < 5; i++) {
        if (tab[i] != carte[i]) {
          whitelist = false;
          break;
        }
      }

      if (whitelist) {
        for (int i = 0; i < 5; i++) {
          Serial.println("Carte correcte, Systeme deverouiller ");
        } 
      }
      else {
          Serial.println("Carte incorrecte, Systeme verouiller ");
        }
      compteur = 0;
    }
  }
}
