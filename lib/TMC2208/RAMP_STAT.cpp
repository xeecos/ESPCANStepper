#include "TMCStepper.h"
#include "TMC_MACROS.h"

#define GET_REG(SETTING) RAMP_STAT_t r{0}; r.sr = RAMP_STAT(); return r.SETTING
