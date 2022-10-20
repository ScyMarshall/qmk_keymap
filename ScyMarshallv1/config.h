#pragma once

#define UNICODE_SELECTED_MODES UC_WINC
#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 200
#define TAPPING_TOGGLE 2
#define OLED_TIMEOUT 60000
#define OLED_UPDATE_INTERVALL 10
/* RGB light
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_EFFECT_CHRISTMAS
#define RGBLIGHT_EFFECT_ALTERNATING
#define RGBLIGHT_EFFECT_TWINKLE
#define RGBLIGHT_HUE_STEP 5 // number of steps to cycle through the hue by
#define RGBLIGHT_SAT_STEP 10 // number of steps to increment the saturation by
#define RGBLIGHT_VAL_STEP 10 // number of steps to increment the brightness by
#define RGBLIGHT_SLEEP // the RGB lighting will be switched off when the host goes to sleep
//#define RGBLIGHT_LAYERS //
//#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF
 */
// spacesaving
#ifndef NO_DEBUG
#    define NO_DEBUG
#endif
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#    define NO_PRINT
#endif
#define DISABLE_LEADER
#define NO_ACTION_ONESHOT
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
#define NO_MUSIC_MODE
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#undef RGBLIGHT_EFFECT_STATIC_GRADIENT
#undef RGBLIGHT_EFFECT_RGB_TEST