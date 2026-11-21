#pragma once

/* Select hand configuration */
#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

// Home row mods: tap-preferred hold-tap, 250ms, no quick-tap (ZMK &hm)
#define TAPPING_TERM 250
#define TAPPING_TERM_PER_KEY
#define QUICK_TAP_TERM 0
// ZMK require-prior-idle-ms = 200
#define FLOW_TAP_TERM 200

// Combos are positional in ZMK: resolve combo keys from the base layer so
// they fire on every layer, same as the ZMK config.
#define COMBO_TERM 18
#define COMBO_ONLY_FROM_LAYER 0
