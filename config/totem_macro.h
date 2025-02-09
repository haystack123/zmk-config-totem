#pragma once

#define WRAP_QUOTE(X) #X

// clang-format off
#define IRONHEE_MACRO(NAME, ...) \
  NAME: NAME { \
    label = WRAP_QUOTE(MACRO_ ## NAME); \
    compatible = "zmk,behavior-macro"; \
    #binding-cells = <0>; \
    wait-ms = <1>; \
    tap-ms = <1>; \
    bindings = __VA_ARGS__; \
  };
#define IRONHEE_HOME_ROW(NAME, HOLD, TAP, HOLD_TRIGGER_KEY_POSITIONS) \
  NAME: NAME { \
    compatible = "zmk,behavior-hold-tap"; \
    label = WRAP_QUOTE(HOLD_TAP_ ## NAME); \
    #binding-cells = <2>; \
    flavor = "balanced"; \
    tapping-term-ms = <280>; \
    quick-tap-ms = <175>; \
    require-prior-idle-ms = <150>; \
    bindings = <HOLD>, <TAP>; \
    hold-trigger-key-positions = <HOLD_TRIGGER_KEY_POSITIONS>; \
    hold-trigger-on-release; \
  };
#define IRONHEE_THUM_ROW(NAME, HOLD, TAP) \
  NAME: NAME { \
    compatible = "zmk,behavior-hold-tap"; \
    label = WRAP_QUOTE(HOLD_TAP_ ## NAME); \
    #binding-cells = <2>; \
    flavor = "hold-preferred"; \
    tapping-term-ms = <280>; \
    quick-tap-ms = <175>; \
    bindings = <HOLD>, <TAP>; \
  };
#define IRONHEE_MORP_SHIFT(NAME, BINDING_BASE, BINDING_MORP) \
  NAME: NAME { \
    compatible = "zmk,behavior-mod-morph"; \
    label = WRAP_QUOTE(MORP_SHIFT_ ## NAME); \
    #binding-cells = <0>; \
    bindings = <BINDING_BASE>, <BINDING_MORP>; \
    mods = <(MOD_LSFT|MOD_RSFT)>; \
  };
#define IRONHEE_COMBO_HORI(NAME, KEY_POSITIONS, BINDINGS) \
  combo_ ## NAME { \
    timeout-ms = <32>; \
    key-positions = <KEY_POSITIONS>; \
    bindings = <BINDINGS>; \
  };
#define IRONHEE_COMBO_VERT(NAME, KEY_POSITIONS, BINDINGS) \
  combo_ ## NAME { \
    timeout-ms = <32>; \
    key-positions = <KEY_POSITIONS>; \
    bindings = <BINDINGS>; \
  };
// clang-format on
