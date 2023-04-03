#include "TMCStepper.h"
#include "TMC_MACROS.h"

#define SET_REG(SETTING) ENCMODE_register.SETTING = B; write(ENCMODE_register.address, ENCMODE_register.sr);
#define GET_REG(SETTING) ENCMODE_t r{0}; r.sr = ENCMODE(); return r.SETTING;
