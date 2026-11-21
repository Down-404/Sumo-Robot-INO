// encoders.cpp
#include "encoders.h"
#include "../config/config.h"
#include <Wire.h>


static uint16_t angulo[NUM_ENC];
static bool activo[NUM_ENC];
static TwoWire* bus[NUM_ENC]; //direccion de un bus I2C

static bool leerRaw(TwoWire*& w, uint16_t& out){// manera simple de no usar #include <AS5600.h> en el codigo 
    w.beginTransmission(AS5600_DIR);
    w.write(0x0C);// registro del angulo, envia dato
    if (w.endTransmission(false) != 0) return false;// no contesta
    if (w.requestFrom((uint8_t)AS5600_DIR, (uint8_t)2) != 2) return false;

    uint16_t alto = w.read();
    uint16_t bajo = w.read();
    out = ((alto << 8) | bajo) & 0x0FFF;// solo 12 bits
    return true;
}
void iniciarEncoders(){
    bus[ENC_IZQ] = &Wire;// el encoder izquierdo habla por el bus 0 (& singnifica apunta en este bus)
    bus[ENC_DER] = &Wire1;// bus 1 

    for (uint8_t i = 0; i < NUM_ENC; i++) { //for para incio
        uint16_t v;
        activo[i] = leerRaw(*bus[i], v);        //responde o no
        angulo[i] = activo[i] ? v : 0;
        Serial.printf("ENC %d: %s\n", i, activo[i] ? "OK" : "ERROR"); //imprimir error o OK
    }
}

void actualizarEncoders(){
    for (uint8_t i = 0; i < NUM_ENC; i++) {
    if (!activo[i]) continue;// si no respondio al inicio, lo salta
    uint16_t v;//arbitrario v
    if (leerRaw(*bus[i], v)) angulo[i] = v;// si falla, conserva el ultimo valor
    }
}

uint16_t anguloRawEncoder(uint8_t indice){
    return angulo[indice];
} 

bool encoderActivo(uint8_t indice){
    return angulo[indice];
}