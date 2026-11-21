//sumo.ino
//includes---------------------------
//sensores
#include "src/sensores/sensores.h"
//RTT
#include "src/RTT/arranque.h"
//motor BTS
#include "src/motores/bts.h"
//Debug
#include "src/debug/debug.h"


void setup(){
    Serial.begin(115200);
    delay(500);
    iniciarSensores();
    iniciarArranque();
}
void loop(){

    LecturaSensores s = leerSensores(); //valor sensores
    bool listo = moduloListo();
    bool go = arranqueActivo();

    //Imprimir
    imprimirSensores(s);
    imprimirArranque(listo, go);
}