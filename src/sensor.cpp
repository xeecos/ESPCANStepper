#include "sensor.h"
#include "TLE5012B.h"
TLE5012B *_sensor;
void sensor_init()
{
    _sensor = new TLE5012B();
    int err = _sensor->begin(4, 2, 5, 9);
}
double sensor_position()
{
    return 0.0;
}
double sensor_get_angle()
{
    float ang = 0.0f;
    int err = _sensor->getAngleValue(ang);
    if (err == 0)
    {
        return ang;
    }
    return 0.0;
}
double sensor_get_speed()
{
    float spd = 0.0f;
    int err = _sensor->getAngleSpeed(spd);
    if (err == 0)
    {
        return spd;
    }
    return 0.0;
}