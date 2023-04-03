#include "stepper.h"
#include "config.h"
#include "TMCStepper.h"
#include <HardwareSerial.h>
#include <Arduino.h>

HardwareSerial _uart(1);
TMC2208Stepper _stepper(&_uart, 0.39);

int32_t _current_position = 0;
bool _dir = false;
bool _step_status = false;

void stepper_init()
{
    pinMode(STEP_PIN, OUTPUT);
    pinMode(DIR_PIN, OUTPUT);
    stepper_disable();

    _uart.begin(115200, SERIAL_8N1, RX_PIN, TX_PIN);
    _stepper.begin();
    while (_stepper.test_connection())
    {
        delay(1000);
    }
    _stepper.internal_Rsense(false);
    _stepper.dedge(true);
    _stepper.microsteps(MICROSTEPS);
    _stepper.rms_current(500);
    _stepper.toff(2);
    _stepper.push();
}
void stepper_set_current(int ma)
{
    ma = ma > 1000 ? 1000 : ma;
    ma = ma < 10 ? 10 : ma;
    _stepper.rms_current(ma);
    _stepper.push();
}
void stepper_set_microstep(int ms)
{
    ms = ms > 256 ? 256 : ms;
    ms = ms < 1 ? 1 : ms;
    _stepper.microsteps(ms);
    _stepper.push();
}
int32_t stepper_get_position()
{
    return _current_position;
} 
void stepper_step(bool dir)
{
    _current_position += dir ? 1 : -1;
    stepper_set_direction(dir);
    digitalWrite(STEP_PIN, _step_status);
    _step_status = !_step_status;
}
void stepper_reset(int32_t pos)
{
    _current_position = pos;
}
void stepper_set_direction(bool dir)
{
    if (_dir != dir)
    {
        _dir = dir;
        digitalWrite(DIR_PIN, dir);
    }
}
void stepper_enable()
{
}
void stepper_disable()
{
}