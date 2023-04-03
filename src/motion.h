#pragma once
#include <stdint.h>
void motion_init();
void motion_set_acceleration(int32_t acceleration);
void motion_set_accel_distance(uint32_t distance);
void motion_set_deaccel_distance(uint32_t distance);
void motion_set_total_distance(uint32_t distance);
void motion_start();
void motion_stop();
void motion_set_power(uint16_t power);
void motion_set_pwm(int16_t pwm);
uint32_t motion_get_speed();
uint32_t motion_get_max_speed();