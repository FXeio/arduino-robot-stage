int pinOcchioDx = 5;
int pinOcchioSx = 3;

int pinSorriso = 4;
int pinTriste = 2;

int pinSensore = A0;

#include <Servo.h>
Servo braccio;
int pinBraccio = 7;

int pinBuzzer = 9;


void setup() {
  pinMode(pinOcchioDx, OUTPUT);
  pinMode(pinOcchioSx, OUTPUT);
  digitalWrite(pinOcchioDx, HIGH);
  digitalWrite(pinOcchioSx, HIGH);

  pinMode(pinSorriso, OUTPUT);
  pinMode(pinTriste, OUTPUT);
  digitalWrite(pinSorriso, HIGH);

  braccio.attach(pinBraccio);

  pinMode(pinBuzzer, OUTPUT);

  randomSeed(analogRead(A1)); // Un pin 
analogico scollegato da un valore casuale
}


void loop() {
  if (analogRead(A0) < 600) { // Soglia per 
rilevare l'ombra
    digitalWrite(pinSorriso, LOW);
    digitalWrite(pinTriste, HIGH);
    tone(pinBuzzer, 415);
    braccio.write(180);
    while (analogRead(A0) < 600);
    noTone(pinBuzzer);
    digitalWrite(pinTriste, LOW);
    digitalWrite(pinSorriso, HIGH);
    braccio.write(0);
    occhiolino();
  } else if (random(0, 10) == 0) {
    blink();
    delay(600);
  }
}


void occhiolino() {
  digitalWrite(pinOcchioDx, LOW);
  delay(300);
  digitalWrite(pinOcchioDx, HIGH);
}

void blink() {
  digitalWrite(pinOcchioDx, LOW);
  digitalWrite(pinOcchioSx, LOW);
  digitalWrite(pinOcchioDx, HIGH);
  digitalWrite(pinOcchioSx, HIGH);
}
