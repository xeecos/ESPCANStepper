#pragma once

#define DEBUG_PRINT(CFG, VAL) LOG_UART(CFG); LOG_UART('('); LOG_UART(VAL, HEX); LOG_UARTln(')')
//#define WRITE_REG(R) write(R##_register.address, R##_register.sr)
//#define READ_REG(R) read(R##_register.address)
