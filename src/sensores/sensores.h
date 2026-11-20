//sensores.h
#pragma once
#include <Arduino.h>
#include "../config/config.h"

struct LecturaSensores
{
    uint16_t dist[NUM_VLX];
    uint16_t qtr[NUM_QTR];  // valor crudo
    bool linea[NUM_QTR];      
    uint16_t encRaw[NUM_ENC]; 
    //encoders, linea, etc
}; //SI LLEVA ; LOS VOID SON LOS QUE NO LLEVA ;

void iniciarSensores();
LecturaSensores leerSensores();

