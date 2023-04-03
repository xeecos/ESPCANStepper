#include <Arduino.h>
#include "service.h"
void setup()
{
    service_init();
}

void loop()
{
    service_run();
}