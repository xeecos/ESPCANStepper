#include "TMCStepper.h"
#include "TMC_MACROS.h"

#define SET_REG(SETTING) PWMCONF_register.SETTING = B; write(PWMCONF_register.address, PWMCONF_register.sr)
#define GET_REG(SETTING) return PWMCONF_register.SETTING

uint32_t TMC2208Stepper::PWMCONF() {
	return read(PWMCONF_register.address);
}
void TMC2208Stepper::PWMCONF(uint32_t input) {
	PWMCONF_register.sr = input;
	write(PWMCONF_register.address, PWMCONF_register.sr);
}

void TMC2208Stepper::pwm_ofs		( uint8_t B ) { PWMCONF_register.pwm_ofs = B; write(PWMCONF_register.address, PWMCONF_register.sr); }
void TMC2208Stepper::pwm_grad		( uint8_t B ) { PWMCONF_register.pwm_grad = B; write(PWMCONF_register.address, PWMCONF_register.sr); }
void TMC2208Stepper::pwm_freq		( uint8_t B ) { PWMCONF_register.pwm_freq = B; write(PWMCONF_register.address, PWMCONF_register.sr); }
void TMC2208Stepper::pwm_autoscale	( bool 	  B ) { PWMCONF_register.pwm_autoscale = B; write(PWMCONF_register.address, PWMCONF_register.sr); }
void TMC2208Stepper::pwm_autograd	( bool    B ) { PWMCONF_register.pwm_autograd = B; write(PWMCONF_register.address, PWMCONF_register.sr); }
void TMC2208Stepper::freewheel		( uint8_t B ) { PWMCONF_register.freewheel = B; write(PWMCONF_register.address, PWMCONF_register.sr); }
void TMC2208Stepper::pwm_reg		( uint8_t B ) { PWMCONF_register.pwm_reg = B; write(PWMCONF_register.address, PWMCONF_register.sr); }
void TMC2208Stepper::pwm_lim		( uint8_t B ) { PWMCONF_register.pwm_lim = B; write(PWMCONF_register.address, PWMCONF_register.sr); }

uint8_t TMC2208Stepper::pwm_ofs()		{ TMC2208_n::PWMCONF_t r{0}; r.sr = PWMCONF(); return r.pwm_ofs;		}
uint8_t TMC2208Stepper::pwm_grad()		{ TMC2208_n::PWMCONF_t r{0}; r.sr = PWMCONF(); return r.pwm_grad;		}
uint8_t TMC2208Stepper::pwm_freq()		{ TMC2208_n::PWMCONF_t r{0}; r.sr = PWMCONF(); return r.pwm_freq;		}
bool 	TMC2208Stepper::pwm_autoscale()	{ TMC2208_n::PWMCONF_t r{0}; r.sr = PWMCONF(); return r.pwm_autoscale;	}
bool 	TMC2208Stepper::pwm_autograd()	{ TMC2208_n::PWMCONF_t r{0}; r.sr = PWMCONF(); return r.pwm_autograd;	}
uint8_t TMC2208Stepper::freewheel()		{ TMC2208_n::PWMCONF_t r{0}; r.sr = PWMCONF(); return r.freewheel;		}
uint8_t TMC2208Stepper::pwm_reg()		{ TMC2208_n::PWMCONF_t r{0}; r.sr = PWMCONF(); return r.pwm_reg;		}
uint8_t TMC2208Stepper::pwm_lim()		{ TMC2208_n::PWMCONF_t r{0}; r.sr = PWMCONF(); return r.pwm_lim;		}
