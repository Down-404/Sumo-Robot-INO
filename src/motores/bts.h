//bts.h
#pragma once
#include <Arduino.h>

void iniciarMotores();
void motores(int izq, int der);   // -255 - 255 positivo es adelante
void detenerMotores();