#include "utils.h"

uint32_t sqrt_int(uint32_t x)
{
    uint32_t v_bit = 15;
    uint32_t n = 0;
    uint32_t b = 0x8000;

    if (x <= 1)
        return x;

    while (b)
    {
        uint32_t temp = ((n << 1) + b) << v_bit--;
        if (x >= temp)
        {
            n += b;
            x -= temp;
        }
        b >>= 1;
    }
    return n;
};
static const float atan2_p1 = 0.9997878412794807f * (float)(180.0f / M_PI);
static const float atan2_p3 = -0.3258083974640975f * (float)(180.0f / M_PI);
static const float atan2_p5 = 0.1555786518463281f * (float)(180.0f / M_PI);
static const float atan2_p7 = -0.04432655554792128f * (float)(180.0f / M_PI);
static const float atan2_DBL_EPSILON = 2.2204460492503131e-016;
float atan2_fast(float dy, float dx)
{
    // 快速atan運算
    float ax = dx > 0 ? dx : -dx, ay = dy ? dy : -dy;
    float a, c, c2;
    if (ax >= ay)
    {
        c = ay / (ax + static_cast<float>(atan2_DBL_EPSILON));
        c2 = c * c;
        a = (((atan2_p7 * c2 + atan2_p5) * c2 + atan2_p3) * c2 + atan2_p1) * c;
    }
    else
    {
        c = ax / (ay + static_cast<float>(atan2_DBL_EPSILON));
        c2 = c * c;
        a = 90.f - (((atan2_p7 * c2 + atan2_p5) * c2 + atan2_p3) * c2 + atan2_p1) * c;
    }
    if (dx < 0)
        a = 180.f - a;
    if (dy < 0)
        a = 360.f - a;
    return a * M_PI / 180.0f;
}