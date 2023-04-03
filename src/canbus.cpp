#include "canbus.h"
#include "config.h"
#include "utils.h"
#include "motion.h"
void canbus_init()
{
    twai_general_config_t g_config = TWAI_GENERAL_CONFIG_DEFAULT((gpio_num_t)CAN_TX, (gpio_num_t)CAN_RX, TWAI_MODE_NORMAL);
    twai_timing_config_t t_config = TWAI_TIMING_CONFIG_500KBITS();
    twai_filter_config_t f_config = TWAI_FILTER_CONFIG_ACCEPT_ALL();
    // Install TWAI driver
    if (twai_driver_install(&g_config, &t_config, &f_config) == ESP_OK)
    {
    }
    // Start TWAI driver
    if (twai_start() == ESP_OK)
    {
    }
}
twai_message_t canbus_message;
bool canbus_available()
{
    if (twai_receive(&canbus_message, pdMS_TO_TICKS(50)) == ESP_OK)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void canbus_receive()
{
    int canid = canbus_message.identifier;
    
    if(canid==CID_MOTION_START)
    {
        motion_start();
    }
    else if(canid==CID_MOTION_STOP)
    {
        motion_stop();
    }
    else
    {
        switch (canid)
        {
            #if ENABLE_AXIS_X==1
            case CID_X_ACCELRATION:
            {
                Long2Bytes lv;
                lv.bytes[0] = canbus_message.data[0];
                lv.bytes[1] = canbus_message.data[1];
                lv.bytes[2] = canbus_message.data[2];
                lv.bytes[3] = canbus_message.data[3];
                motion_set_acceleration(lv.longValue);
            }
            break;
            case CID_X_ACCEL_DISTANCE:
            {
                Uint2Bytes lv;
                lv.bytes[0] = canbus_message.data[0];
                lv.bytes[1] = canbus_message.data[1];
                lv.bytes[2] = canbus_message.data[2];
                lv.bytes[3] = canbus_message.data[3];
                motion_set_accel_distance(lv.uint32Value);
            }
            break;
            case CID_X_DEACCEL_DISTANCE:
            {
                Uint2Bytes lv;
                lv.bytes[0] = canbus_message.data[0];
                lv.bytes[1] = canbus_message.data[1];
                lv.bytes[2] = canbus_message.data[2];
                lv.bytes[3] = canbus_message.data[3];
                motion_set_deaccel_distance(lv.uint32Value);
            }
            break;
            case CID_X_TOTAL_DISTANCE:
            {
                Uint2Bytes lv;
                lv.bytes[0] = canbus_message.data[0];
                lv.bytes[1] = canbus_message.data[1];
                lv.bytes[2] = canbus_message.data[2];
                lv.bytes[3] = canbus_message.data[3];
                motion_set_total_distance(lv.uint32Value);
            }
            break;
            #endif
            #if ENABLE_AXIS_Y==1
            case CID_Y_ACCELRATION:
            {
                Long2Bytes lv;
                lv.bytes[0] = canbus_message.data[0];
                lv.bytes[1] = canbus_message.data[1];
                lv.bytes[2] = canbus_message.data[2];
                lv.bytes[3] = canbus_message.data[3];
                motion_set_acceleration(lv.longValue);
            }
            break;
            case CID_Y_ACCEL_DISTANCE:
            {
                Uint2Bytes lv;
                lv.bytes[0] = canbus_message.data[0];
                lv.bytes[1] = canbus_message.data[1];
                lv.bytes[2] = canbus_message.data[2];
                lv.bytes[3] = canbus_message.data[3];
                motion_set_accel_distance(lv.uint32Value);
            }
            break;
            case CID_Y_DEACCEL_DISTANCE:
            {
                Uint2Bytes lv;
                lv.bytes[0] = canbus_message.data[0];
                lv.bytes[1] = canbus_message.data[1];
                lv.bytes[2] = canbus_message.data[2];
                lv.bytes[3] = canbus_message.data[3];
                motion_set_deaccel_distance(lv.uint32Value);
            }
            break;
            case CID_Y_TOTAL_DISTANCE:
            {
                Uint2Bytes lv;
                lv.bytes[0] = canbus_message.data[0];
                lv.bytes[1] = canbus_message.data[1];
                lv.bytes[2] = canbus_message.data[2];
                lv.bytes[3] = canbus_message.data[3];
                motion_set_total_distance(lv.uint32Value);
            }
            break;
            #endif
            #if ENABLE_AXIS_Z==1
            case CID_Z_ACCELRATION:
            {
                Long2Bytes lv;
                lv.bytes[0] = canbus_message.data[0];
                lv.bytes[1] = canbus_message.data[1];
                lv.bytes[2] = canbus_message.data[2];
                lv.bytes[3] = canbus_message.data[3];
                motion_set_acceleration(lv.longValue);
            }
            break;
            case CID_Z_ACCEL_DISTANCE:
            {
                Uint2Bytes lv;
                lv.bytes[0] = canbus_message.data[0];
                lv.bytes[1] = canbus_message.data[1];
                lv.bytes[2] = canbus_message.data[2];
                lv.bytes[3] = canbus_message.data[3];
                motion_set_accel_distance(lv.uint32Value);
            }
            break;
            case CID_Z_DEACCEL_DISTANCE:
            {
                Uint2Bytes lv;
                lv.bytes[0] = canbus_message.data[0];
                lv.bytes[1] = canbus_message.data[1];
                lv.bytes[2] = canbus_message.data[2];
                lv.bytes[3] = canbus_message.data[3];
                motion_set_deaccel_distance(lv.uint32Value);
            }
            break;
            case CID_Z_TOTAL_DISTANCE:
            {
                Uint2Bytes lv;
                lv.bytes[0] = canbus_message.data[0];
                lv.bytes[1] = canbus_message.data[1];
                lv.bytes[2] = canbus_message.data[2];
                lv.bytes[3] = canbus_message.data[3];
                motion_set_total_distance(lv.uint32Value);
            }
            break;
            #endif
        }
    }
}

void canbus_send(twai_message_t msg)
{
    if (twai_transmit(&msg, pdMS_TO_TICKS(100)) == ESP_OK)
    {
    }
}