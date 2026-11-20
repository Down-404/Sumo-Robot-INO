// encoders.cpp
#include "encoders.h"
#include "../config/config.h"
#include <Wire.h>


static uint16_t angulo[NUM_ENC];
static bool activo[NUM_ENC];