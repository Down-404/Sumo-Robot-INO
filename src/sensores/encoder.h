// encoders.h
#pragma once
#include <Arduino.h>

void iniciarEncoders();
void actualizarEncoders();
uint16_t anguloRawEncoder(uint8_t indice);   // 0-4095 (4096 pasos por vuelta)
bool encoderActivo(uint8_t indice);          // false no responde