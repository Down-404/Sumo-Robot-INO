/*
*   config.h
*   Constantes de ajuste de la estrategia del robot.
*   Aqui se cambian las constantes
*/ 

#pragma once

//Includes
#include <Arduino.h> //Por #include <cstdint>


//distancias----------------------------------------------------------------------------------------------------------------

constexpr uint16_t ENEMY_THRESHOLD = 400; //A que distancia se va a considerar visto el enemigo
constexpr uint16_t BACK_SENSOR_DIFF = 200; //Sensor trasero
//menor a este valor es igual a empuja
constexpr uint16_t PUSH_THRESHOLD  = 150;  //treashold para push

// tiempos------------------------------------------------------------------------------------------------------------------
constexpr uint32_t LINE_TURN_TIME_MS        = 300;//cuanto dura line
constexpr uint32_t ENEMY_LOST_TIME_MS       = 500;//cuanto dura enemy lost
constexpr uint32_t PUSHING_LOSING_TIME_MS   = 400;//cuanto dura Pushing Losing
constexpr uint32_t ENEMY_BEHIND_TIME_MS     = 400;//cuanto tiempo dura enemy behind 


//velocidades con constantes------------------------------------------------------------------------------------------------
constexpr float SEARCH_V       = 0.25f;
constexpr float SEARCH_W       = 5.0f;//arco para barrer el dohyo
constexpr float TURN_W         = 10.0f;//giro rapido en sitio
constexpr float ATTACK_V       = 0.9f;
constexpr float PUSH_V         = 1.2f;
constexpr float PUSH_LOSING_V  = 1.3f;
constexpr float LINE_BACK_V    = 0.7f;//salida al ver linea delantera
constexpr float LINE_TURN_W    = 6.0f;
constexpr float LINE_FWD_V     = 0.8f;//salida al ver linea trasera
constexpr float LINE_REAR_W    = 3.0f;

//PINS----------------------------------------------------------------------------------------------------------

//I2C----------------------------
//4x VL53L0X + AS5600 #1
constexpr uint8_t I2C0_SDA = 8;
constexpr uint8_t I2C0_SCL = 9;

//AS5600 #2 
constexpr uint8_t I2C1_SDA = 4;
constexpr uint8_t I2C1_SCL = 5;
//-------------------------------

//AS5600
constexpr uint8_t NUM_ENC = 2;
enum EncIndice : uint8_t { ENC_IZQ = 0, ENC_DER = 1 };   // confirma cual es cual, numeracion
// ENC_IZQ en Wire (I2C0, pines 8/9)
// ENC_DER en Wire1 (I2C1, pines 4/5)
constexpr uint8_t AS5600_DIR = 0x36;  //la misma para los dos

//PWM motores
constexpr uint32_t MOT_PWM_FREQ = 5000;   // Hz
constexpr uint8_t  MOT_PWM_BITS = 8;      // 0-255

//inversion de motores, por si acaso
constexpr bool MOT_IZQ_INVERTIDO = false;
constexpr bool MOT_DER_INVERTIDO = false;

//VL53L0X
constexpr uint8_t NUM_VLX = 4; //numero VLX
enum VlxIndice : uint8_t { 
    VLX_FL = 0, 
    VLX_FRENTE = 1, 
    VLX_FR = 2, 
    VLX_ATRAS = 3 
};
constexpr uint8_t VLX_XSHUT[NUM_VLX] = {14, 15, 16, 17};
constexpr uint8_t VLX_DIR[NUM_VLX]   = {0x30, 0x31, 0x32, 0x33};

//QTR
constexpr uint8_t NUM_QTR = 4; //cantidad de QTR
enum QtrIndice : uint8_t { QTR_FL = 0, QTR_FR = 1, QTR_RL = 2, QTR_RR = 3 }; //numerar QTR

constexpr uint8_t QTR_PIN_FL = 7;   // Front_L
constexpr uint8_t QTR_PIN_FR = 6;   // Front_R
constexpr uint8_t QTR_PIN_RL = 2;   // Back_L
constexpr uint8_t QTR_PIN_RR = 1;   // Back_R

constexpr uint8_t QTR_PIN[NUM_QTR] = {QTR_PIN_FL, QTR_PIN_FR, QTR_PIN_RL, QTR_PIN_RR};

constexpr uint16_t QTR_UMBRAL = 2000;       // CALIBRAR en el dohyo (0-4095)
constexpr bool QTR_BLANCO_ES_BAJO = true;   // blanco es valor bajo si true

//BTS7960 der
constexpr uint8_t MOT_DER_RPWM = 12;
constexpr uint8_t MOT_DER_LPWM = 13;
constexpr uint8_t MOT_DER_R_EN = 38;
constexpr uint8_t MOT_DER_L_EN = 39;

//BTS7960 izq
constexpr uint8_t MOT_IZQ_RPWM = 40;
constexpr uint8_t MOT_IZQ_LPWM = 41;
constexpr uint8_t MOT_IZQ_R_EN = 42;
constexpr uint8_t MOT_IZQ_L_EN = 47;

//ModR01
constexpr uint8_t MODR01_RDY = 10;
constexpr uint8_t MODR01_GO  = 11;

//RGB_ESP
constexpr uint8_t RGB_ESP  = 48;

//extra
constexpr bool DEBUG_SERIAL = true;// false = no imprime nada
constexpr uint32_t DEBUG_INTERVALO_MS = 200; //que tan rapido
