#include "laser.h"
#include "Arduino.h"
#include "config.h"
static uint32_t _pwm = 1;
void laser_init()
{
    ledcAttachPin(LASER_PWM_PIN, 1);
    ledcSetup(1, 5000, 14);
    laser_power(0);
}
void laser_power(uint32_t pwm)
{
    if(pwm>16384)
    {
        pwm = 16384;
    }
    if(_pwm!=pwm)
    {
        _pwm = pwm;
        ledcWrite(14,pwm);
    }
}