//debug.cpp
#include "debug.h"
#include "../config/config.h"

void imprimirSensores(const LecturaSensores& s){
  if (!DEBUG_SERIAL) return;

  static uint32_t ultimo = 0;
  uint32_t ahora = millis();
  if(ahora - ultimo < DEBUG_INTERVALO_MS) return;
  ultimo = ahora; 
  
  Serial.print("VLX:  ");
  for(uint8_t i = 0; i < NUM_VLX; i++){
    Serial.print(s.dist[i]);
    Serial.print("  ");
  }
  Serial.println();
  
  Serial.print(" -QTR: ");
  for (uint8_t i = 0; i < NUM_QTR; i++) {
    Serial.print(s.qtr[i]);
    Serial.print(s.linea[i] ? "(L) " : "(-) "); //Linea o No
  }
  Serial.println();
};   

void imprimirArranque(bool listo, bool go) {
  if (!DEBUG_SERIAL) return;

  static uint32_t ultimo = 0;
  uint32_t ahora = millis();
  if (ahora - ultimo < DEBUG_INTERVALO_MS) return;
  ultimo = ahora;

  Serial.printf("RDY=%d  GO=%d\n", listo, go);
}