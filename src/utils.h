#pragma once
#include <stdint.h>
#ifndef M_2_PI
#define M_2_PI     6.28318530717958647692   // pi * 2
#endif
#ifndef M_PI
#define M_PI       3.14159265358979323846   // pi
#endif
#ifndef M_PI_2
#define M_PI_2     1.57079632679489661923   // pi/2
#endif
union float2bytes
{
    float v;
    uint8_t bytes[4];
};

uint32_t sqrt_int(uint32_t x);
float atan2_fast(float dy, float dx);