//vlx.h
#pragma once
//include
#include <Arduino.h>//Por #include <cstdint>

void iniciarVLX();
void actualizarVLX();  // actualizar el vlx 
uint16_t distanciaVLF(uint8_t indice); //ultima distancia en mm 0xFFFF es invalido (no ve pues)