//bts.cpp
#include "bts.h"
#include "../config/config.h"

static void setMotor(uint8_t pinFwd, uint8_t pinRev, int v, bool invertido){ //limite y sentido
    if(invertido){
        v = -v;
    }
    v = constrain(v, -255, 255);

    if(v > 0){
        ledcWrite(pinWrite(pinRev, 0));
        ledcWrite(pinWrite(pinFwd, v));
    }
    else if (v < 0){
        ledcWrite(pinWrite(pinRev, -v));
        ledcWrite(pinWrite(pinFwd, 0));
    }
    else{
        ledcWrite(pinWrite(pinRev, 0));
        ledcWrite(pinWrite(pinFwd, 0));
    }
}
void iniciarMotores(){

    const uint8_t pwmPines[4] = = {MOT_IZQ_RPWM, MOT_IZQ_LPWM, MOT_DER_RPWM, MOT_DER_LPWM};
    const uint8_t enPines[4]  = {MOT_IZQ_R_EN, MOT_IZQ_L_EN, MOT_DER_R_EN, MOT_DER_L_EN};

    for(uint8_t i = 0; i < 4; i++){// LOW lo mas antes posible para que no salgan volando solos
        pinMode(pwmPines[i], OUTPUT);
        digitalWrite(pwmPines[i], LOW)
    }

    for(uint8_t i = 0; i < 4; i++){ //enables en high, sin enable no mueve
        pinMode(enPines[i], OUTPUT);
        digitalWrite(enPines[i], HIGH);
    }

    for (uint8_t i = 0; i < 4; i++) {//activa el PWM (core 3.x)
    ledcAttach(pwmPines[i], MOT_PWM_FREQ, MOT_PWM_BITS);
    }

    detenerMotores();
}

void motores(int izq, int der){
    setMotor(MOT_IZQ_RPWM, MOT_IZQ_LPWM, izq, MOT_IZQ_INVERTIDO);
    setMotor(MOT_DER_RPWM, MOT_DER_LPWM, der, MOT_DER_INVERTIDO);
}

void detenerMotores() {
  motores(0, 0);
}