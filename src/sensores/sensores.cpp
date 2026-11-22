//sensores.cpp
//includes
#include "sensores.h"
//sensores individuales
#include "vlx.h"
#include "qtr.h"
#include "encoder.h"
//I2C
#include <Wire.h>

void iniciarSensores(){
    //inciar I2C
    Wire.begin(I2C0_SDA, I2C0_SCL);
    Wire.setClock(400000);
    //Bus2 
    Wire1.begin(I2C1_SDA, I2C1_SCL);// el bus se inicia una vez aqui el SDA SCL
    //reloj
    Wire1.setClock(400000);
    //inciar sensores
    iniciarVLX();
    iniciarQTR();
    iniciarEncoders();
  
}

LecturaSensores leerSensores(){
    actualizarVLX();
    actualizarQTR();
    actualizarEncoders();

    LecturaSensores s; //s arbitrario

    //VLX
    for(uint8_t i = 0; i < NUM_VLX; i++){//for por cada sensor
        s.dist[i] = distanciaVLX(i); //por cada ciclo escoge VLX 
    }
    //SENSOR LINEA
    for (uint8_t i = 0; i < NUM_QTR; i++){//valor crudo y bool
        s.qtr[i]   = valorQTR(i);
        s.linea[i] = lineaQTR(i);
    }
    //ENCODER
    for(uint8_t i = 0; i < NUM_ENC; i++){
        s.encRaw[i] = anguloRawEncoder(i);
        s.encActivo[i] = encoderActivo(i);
    }
    return s; 
}