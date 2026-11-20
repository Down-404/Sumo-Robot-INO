//sensores.cpp
//includes
#include "sensores.h"
//sensores individuales
#include "vlx.h"
#include "qtr.h"
//I2C
#include <Wire.h>

void IniciarSensores(){
    Wire.begin(I2C0_SDA, I2C0_SCL);   // el bus se inicia una vez aqui el SDA SCL
    Wire.setClock(400000);
    iniciarVLX();
    iniciarQTR();
    //luego iniciar encoders linea etc
}

LecturaSensores leerSensores(){
    actualizarVLX();
    actualizarQTR();

    LecturaSensores s; //s arbitrario
    for(uint8_t i = 0; i < NUM_VLX; i++){ //for por cada sensor
        s.dist[i] = distanciaVLF(i); //por cada ciclo escoge VLX 
    }
    for (uint8_t i = 0; i < NUM_QTR; i++) { //valor crudo y bool
    s.qtr[i]   = valorQTR(i);
    s.linea[i] = lineaQTR(i);
    }
    return s; 
}