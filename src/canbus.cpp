#include "canbus.h"
#include "config.h"

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
    switch (canid)
    {
    }
}

void canbus_send(twai_message_t msg)
{
    if (twai_transmit(&msg, pdMS_TO_TICKS(100)) == ESP_OK)
    {
    }
}