#include "motion.h"
#include "utils.h"
#include <Arduino.h>
static hw_timer_t *_timer = NULL;
uint32_t _speed = 0;
uint32_t _max_speed = 0;
uint32_t _acceleration = 0;
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
    
    timerAlarmWrite(_timer, _interval, true);
}

void motion_add(uint32_t acceleration, uint32_t accel_distance, uint32_t total_distance, uint32_t deaccel_distance, uint16_t power, int16_t pwm)
{
    _acceleration = acceleration;
    _accel_distance = accel_distance;
    _distance = total_distance;
    _deaccel_distance = deaccel_distance;
}
uint32_t motion_get_speed()
{
    return _speed;
}
uint32_t motion_get_max_speed()
{
    return _max_speed;
}