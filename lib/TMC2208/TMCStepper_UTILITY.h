#ifndef TMCStepper_UTILITY_h
#define TMCStepper_UTILITY_h

void print_HEX(uint32_t data) {
  for(uint8_t B=24; B>=4; B-=8){
    LOG_UART((data>>(B+4))&0xF, HEX);
    LOG_UART((data>>B)&0xF, HEX);
    LOG_UART(":");
  }
  LOG_UART((data>>4)&0xF, HEX);
  LOG_UART(data&0xF, HEX);
}

void print_BIN(uint32_t data) {
  int b = 31;
  for(; b>=24; b--){
    LOG_UART((data>>b)&0b1);
  }
  LOG_UART(".");
  for(; b>=16; b--){
    LOG_UART((data>>b)&0b1);
  }
  LOG_UART(".");
  for(; b>=8; b--){
    LOG_UART((data>>b)&0b1);
  }
  LOG_UART(".");
  for(; b>=0; b--){
    LOG_UART((data>>b)&0b1);
  }
}

#endif
