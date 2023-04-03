#include "service.h"
#include <Arduino.h>
#include "stepper.h"
#include "laser.h"
#include "motor.h"
#include "canbus.h"
#include "log.h"
void service_init()
{
    LOG_INIT(115200);
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