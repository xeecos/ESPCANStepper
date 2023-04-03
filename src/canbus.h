#pragma once
#include "driver/twai.h"
void canbus_init();
bool canbus_available();
void canbus_receive();
void canbus_send(twai_message_t frame);