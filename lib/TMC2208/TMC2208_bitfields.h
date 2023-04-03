#pragma once
#pragma pack(push, 1)


struct GCONF_t {
  constexpr static uint8_t address = 0x00;
  union {
    uint32_t sr : 18;
    struct {
      bool  i_scale_analog : 1, // 2130, 5130
            internal_rsense : 1, // 2130, 5130
            en_pwm_mode : 1,
            enc_commutation : 1, // 2130, 5130
            shaft : 1,
            diag0_error : 1,
            diag0_otpw : 1,
            diag0_stall : 1,
            diag1_stall : 1,
            diag1_index : 1,
            diag1_onstate : 1,
            diag1_steps_skipped : 1,
            diag0_int_pushpull : 1,
            diag1_pushpull : 1,
            small_hysteresis : 1,
            stop_enable : 1,
            direct_mode : 1;
    };
  };
};

struct IHOLD_IRUN_t {
  constexpr static uint8_t address = 0x10;
  union {
    uint32_t sr : 20;
    struct {
      uint8_t ihold : 5,
                    : 3,
              irun : 5,
                   : 3,
              iholddelay : 4;
    };
  };
};

struct GSTAT_t {
  constexpr static uint8_t address = 0x01;
  union {
    uint8_t sr : 3;
    struct {
      bool  reset : 1,
            drv_err : 1,
            uv_cp : 1;
    };
  };
};

struct IOIN_t {
  constexpr static uint8_t address = 0x04;
  union {
    uint32_t sr;
    struct {
      bool  step : 1,
            dir : 1,
            dcen_cfg4 : 1,
            dcin_cfg5 : 1,
            drv_enn_cfg6 : 1,
            dco : 1,
            : 2;
      uint16_t : 16;
      uint8_t version : 8;
    };
  };
};

struct TPOWERDOWN_t {
  constexpr static uint8_t address = 0x11;
  uint8_t sr : 8;
};

struct TPWMTHRS_t {
  constexpr static uint8_t address = 0x13;
  uint32_t sr : 20;
};

struct TCOOLTHRS_t {
  constexpr static uint8_t address = 0x14;
  uint32_t sr : 20;
};

struct THIGH_t {
  constexpr static uint8_t address = 0x15;
  uint32_t sr : 20;
};

struct XDIRECT_t {
  constexpr static uint8_t address = 0x2D;
  union {
    uint32_t sr : 25;
    struct {
      int16_t coil_A : 9;
      int8_t         : 7;
      int16_t coil_B : 9;
    };
  };
};

struct VDCMIN_t {
  constexpr static uint8_t address = 0x33;
  uint32_t sr : 23;
};

struct CHOPCONF_t {
  constexpr static uint8_t address = 0x6C;
  union {
    uint32_t sr : 32;
    struct {
      uint8_t toff : 4,
              hstrt : 3,
              hend : 4,
                   : 1;
      bool    disfdcc : 1,
              rndtf : 1,
              chm : 1;
      uint8_t tbl : 2;
      bool    vsense : 1,
              vhighfs : 1,
              vhighchm : 1;
      uint8_t sync : 4, // 2130, 5130
              mres : 4;
      bool    intpol : 1,
              dedge : 1,
              diss2g : 1;
    };
    struct { // TMC5160
      uint32_t     : 20;
      uint8_t tpfd : 4; // 5160
      uint16_t     : 7;
      bool diss2vs : 1; // TMC5160 only
    };
  };
};

struct COOLCONF_t {
  constexpr static uint8_t address = 0x6D;
  union {
    uint32_t sr : 25;
    struct {
      uint8_t semin : 4,
                    : 1,
              seup : 2,
                    : 1,
              semax : 4,
                    : 1,
              sedn : 2;
      bool    seimin : 1;
      int8_t  sgt : 7,
                  : 1;
      bool    sfilt : 1;
    };
  };
};

struct DCCTRL_t {
	constexpr static uint8_t address = 0x6E;
	union {
		uint32_t sr : 24;
		struct {
			uint16_t dc_time : 10,
				: 6;
			uint8_t dc_sg : 8;
		};
	};
};

struct SLAVECONF_t {
  constexpr static uint8_t address = 0x03;
  union {
    uint16_t sr : 12;
    struct {
      uint8_t slaveaddr : 8;
      uint8_t senddelay : 4;
    };
  };
};

struct PWM_AUTO_t {
  constexpr static uint8_t address = 0x72;
  union {
    uint32_t sr : 24;
    struct {
      uint8_t pwm_ofs_auto : 8,
                           : 8,
              pwm_grad_auto : 8;
    };
  };
};
namespace TMC2208_n {
  struct GCONF_t {
    constexpr static uint8_t address = 0x00;
    union {
      uint16_t sr : 10;
      struct {
        bool  i_scale_analog : 1,
              internal_rsense : 1,
              en_spreadcycle : 1,
              shaft : 1,
              index_otpw : 1,
              index_step : 1,
              pdn_disable : 1,
              mstep_reg_select : 1,
              multistep_filt : 1,
              test_mode : 1;
      };
    };
  };
}

namespace TMC2208_n {
  struct IOIN_t {
    constexpr static uint8_t address = 0x06;
    union {
      uint32_t sr;
      struct {
        bool  enn : 1,
              : 1,
              ms1 : 1,
              ms2 : 1,
              diag : 1,
              : 1,
              pdn_uart : 1,
              step : 1,
              sel_a : 1,
              dir : 1;
        uint16_t : 14;
        uint8_t version : 8;
      };
    };
  };
}

namespace TMC2224_n {
  struct IOIN_t {
    constexpr static uint8_t address = 0x06;
    union {
      uint32_t sr;
      struct {
        bool  : 1,
              pdn_uart : 1,
              spread : 1,
              dir : 1,
              enn : 1,
              step : 1,
              ms1 : 1,
              ms2 : 1,
              sel_a : 1;
        uint16_t : 15;
        uint8_t version : 8;
      };
    };
  };
}

struct FACTORY_CONF_t {
  constexpr static uint8_t address = 0x07;
  union {
    uint16_t sr;
    struct {
        uint8_t fclktrim : 5,
                         : 3,
                ottrim : 2;
    };
  };
};

namespace TMC2208_n {
  struct VACTUAL_t {
    constexpr static uint8_t address = 0x22;
    uint32_t sr;
  };
}

struct MSCURACT_t {
  constexpr static uint8_t address = 0x6B;
  union {
    uint32_t sr : 25;
    struct {
      int16_t cur_a : 9,
                    : 7,
              cur_b : 9;
    };
  };
};

namespace TMC2208_n {
  struct CHOPCONF_t {
    constexpr static uint8_t address = 0x6C;
    union {
      uint32_t sr;
      struct {
        uint8_t toff : 4,
                hstrt : 3,
                hend : 4,
                     : 4,
                tbl : 2;
        bool    vsense : 1;
        uint8_t : 6,
                mres : 4;
        bool    intpol : 1,
                dedge : 1,
                diss2g : 1,
                diss2vs : 1;
      };
    };
  };

  struct PWMCONF_t {
    constexpr static uint8_t address = 0x70;
    union {
      uint32_t sr;
      struct {
        uint8_t pwm_ofs : 8,
                pwm_grad : 8,
                pwm_freq : 2;
        bool pwm_autoscale : 1,
             pwm_autograd : 1;
        uint8_t freewheel : 2,
                          : 2,
                pwm_reg : 4,
                pwm_lim : 4;
      };
    };
  };

  struct DRV_STATUS_t {
    constexpr static uint8_t address = 0x6F;
    union {
      uint32_t sr;
      struct {
        bool otpw : 1,
             ot : 1,
             s2ga : 1,
             s2gb : 1,
             s2vsa : 1,
             s2vsb : 1,
             ola : 1,
             olb : 1,
             t120 : 1,
             t143 : 1,
             t150 : 1,
             t157 : 1;
        uint8_t : 4,
                cs_actual : 5,
                : 3,
                : 6;
        bool stealth : 1,
             stst : 1;
      };
    };
  };

  struct PWM_SCALE_t {
    constexpr static uint8_t address = 0x71;
    union {
      uint32_t sr;
      struct {
        uint8_t pwm_scale_sum : 8,
                : 8;
        int16_t pwm_scale_auto : 9;
      };
    };
  };
}

#pragma pack(pop)
