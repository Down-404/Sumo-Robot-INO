//arranque.cpp
#include "arranque.h"
#include "../config/config.h" // .. Salir de carpeta


void iniciarArranque() {
  pinMode(MODR01_RDY, INPUT);
  pinMode(MODR01_GO, INPUT_PULLDOWN); //evita leerlo mal, ruido, siempre 0
}

bool moduloListo() {
  return digitalRead(MODR01_RDY) == HIGH;
}

bool arranqueActivo() {
  return digitalRead(MODR01_GO) == HIGH;
}