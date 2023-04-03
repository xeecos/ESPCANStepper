#include "service.h"
#include <Arduino.h>
#include "stepper.h"
#include "laser.h"
#include "motor.h"
#include "canbus.h"
void service_init()
{
    canbus_init();
    laser_init();
    motor_init();
    stepper_init();
}
void service_run()
{
    if(canbus_available())
    {
        canbus_receive();
    }
}