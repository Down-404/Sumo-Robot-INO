//debug.h
#pragma once
//include
#include <Arduino.h>
#include "../sensores/sensores.h"

void imprimirSensores(const LecturaSensores& s);

void imprimirArranque(bool listo, bool go);