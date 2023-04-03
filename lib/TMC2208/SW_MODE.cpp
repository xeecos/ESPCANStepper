#include "TMCStepper.h"
#include "TMC_MACROS.h"

#define SET_REG(SETTING) SW_MODE_register.SETTING = B; write(SW_MODE_register.address, SW_MODE_register.sr)
#define GET_REG(SETTING) SW_MODE_t r{0}; r.sr = SW_MODE(); return r.SETTING
