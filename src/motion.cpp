#include "motion.h"
#include "stepper.h"
#include "utils.h"
#include <Arduino.h>
static hw_timer_t *_timer = NULL;
uint32_t _speed = 0;
uint32_t _max_speed = 0;
uint32_t _acceleration = 0;
uint32_t _position = 0;
uint32_t _accel_distance;
uint32_t _distance;
uint32_t _deaccel_distance;
void _motion_run();
void _motion_recalc();
void motion_init()
{

    _timer = timerBegin(0, 80, true);
    timerAttachInterrupt(_timer, &_motion_run, true);
    timerAlarmWrite(_timer, 10000, true);
    timerAlarmEnable(_timer);
}
void _motion_run()
{
    _motion_recalc();
}
void _motion_recalc()
{
    int _interval = 10000;
    if(_position < _distance)
    {
        if (_position < _accel_distance)
        {
            _speed = sqrt_int(2 * _acceleration + _speed * _speed);
        }
        else if (_position > _distance - _deaccel_distance)
        {
            _speed += sqrt_int(_speed * _speed - 2 * _acceleration);
        }
        else
        {
        }
        _interval = 1000000 / _speed;
        _position++;
        stepper_step();
    }
    timerAlarmWrite(_timer, _interval, true);
}

void motion_set_acceleration(int32_t acceleration)
{
    if(acceleration>0)
    {
        _acceleration = acceleration;
        stepper_set_direction(false);
    }
    else
    {
        _acceleration = -acceleration;
        stepper_set_direction(true);
    }
}
void motion_set_accel_distance(uint32_t distance)
{
    _accel_distance = distance;
}
void motion_set_deaccel_distance(uint32_t distance)
{
    _deaccel_distance = distance;
}
void motion_set_total_distance(uint32_t distance)
{
    _position = distance;
    _distance = distance;
}
void motion_start()
{
    _position = 0;
}
void motion_stop()
{
    
}
void motion_set_power(uint16_t power)
{
    
}
void motion_set_pwm(int16_t pwm)
{
    
}

uint32_t motion_get_speed()
{
    return _speed;
}
uint32_t motion_get_max_speed()
{
    return _max_speed;
}