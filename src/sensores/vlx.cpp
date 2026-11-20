//vlx.cpp
#include "vlx.h"
#include "../config/config.h" // .. Salir de carpeta
#include <Wire.h> //I2C
#include <Adafruit_VL53L0X.h> //libraria VLX53L0X


static Adafruit_VL53L0X sensores[NUM_VLX];
static bool activo[NUM_VLX];
static uint16_t dist[NUM_VLX];

void iniciarVLX(){
    for (uint8_t i = 0; i < NUM_VLX; i++) { //ciclo for, cantidad de VLX sensores
    pinMode(VLX_XSHUT[i], OUTPUT); //set como output salida
    digitalWrite(VLX_XSHUT[i], LOW); //escribir, low
    activo[i] = false; //activo o no Sirve o no
    dist[i] = 0xFFFF; //valor inicial
  }
  
  delay(10);

  for (uint8_t i = 0; i < NUM_VLX; i++) {
    bool ok = false;
    for (uint8_t intento = 0; intento < 3 && !ok; intento++) {
      digitalWrite(VLX_XSHUT[i], HIGH);
      delay(30);
      ok = sensores[i].begin(VLX_DIR[i], false, &Wire);
      if (!ok) { digitalWrite(VLX_XSHUT[i], LOW); delay(10); }
    }
    if (ok) {
      activo[i] = true;
      sensores[i].startRangeContinuous(25);
    }
    Serial.printf("VLX %d: %s\n", i, ok ? "OK" : "ERROR"); //print si hay error
  }
}

void actualizarVLX(){
    for (uint8_t i = 0; i < NUM_VLX; i++) {
    if (!activo[i]) continue;
    if (sensores[i].isRangeComplete()) {
      uint16_t d = sensores[i].readRange();
      dist[i] = (d >= 8000) ? 0xFFFF : d;
      /*  Lo mismo, si se cumple lo que dice hace lo primero si no lo segundo
      if (d >= 8000) {
      dist[i] = 0xFFFF;
      } else {
      dist[i] = d;
      }
      */
    }
  }
}

uint16_t distanciaVLX(uint8_t i) { return dist[i]; } //regresa valor