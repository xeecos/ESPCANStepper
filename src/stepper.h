#pragma once
#include <stdint.h>
void stepper_init();
void stepper_enable();
void stepper_disable();
int32_t stepper_get_position();
void stepper_step();
void stepper_reset(int32_t pos);
void stepper_set_direction(bool dir);
void stepper_set_current(int ma);
void stepper_set_microstep(int ms);