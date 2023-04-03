#pragma once
#include <stdint.h>
void motion_init();
void motion_add(uint32_t acceleration, uint32_t accel_distance, uint32_t distance, uint32_t deaccel_distance, uint16_t power, int16_t pwm);
uint32_t motion_get_speed();
uint32_t motion_get_max_speed();