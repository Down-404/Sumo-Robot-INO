//qtr.cpp
#include "qtr.h"
#include "../config/config.h"

static uint16_t valor[NUM_QTR]; //static no sale solo se hace 

void iniciarQTR() { //ciclo for, cantidad de QTR pinMode como input
  for (uint8_t i = 0; i < NUM_QTR; i++) {
    pinMode(QTR_PIN[i], INPUT);
    valor[i] = 0;
  }
}

void actualizarQTR() { //analog Read cada pin
  for (uint8_t i = 0; i < NUM_QTR; i++) {
    valor[i] = analogRead(QTR_PIN[i]);
  }
}

uint16_t valorQTR(uint8_t indice) { 
    return valor[indice]; 
}

bool lineaQTR(uint8_t indice) {
  return QTR_BLANCO_ES_BAJO ? (valor[indice] < QTR_UMBRAL)  //Sirve para ver si es true o false comparando si lees blanco o negro, si 
                            : (valor[indice] > QTR_UMBRAL);
}