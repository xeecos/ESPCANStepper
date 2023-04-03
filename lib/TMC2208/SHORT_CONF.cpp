#include "TMCStepper.h"
#include "TMC_MACROS.h"

#define SET_REG(SETTING) SHORT_CONF_register.SETTING = B; write(SHORT_CONF_register.address, SHORT_CONF_register.sr)
#define GET_REG(SETTING) return SHORT_CONF_register.SETTING
