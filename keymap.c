#include QMK_KEYBOARD_H
#include "keymap_german.h"
extern uint8_t is_master; // nur ein test nimm wieder raus dann


#define BOB 0x00B7    // ·
#define ENDASH 0x2013 //– en dash
#define SCRL 0x2113   //ℓ
#define LOW9 0x201E   //„
#define HIG6 0x201C   // “
#define HIG9 0x201D   // ”
#define EMDASH 0x2014 // — em dash
#define SSS 0x00DF    // ß
#define UHR 0x27F3    // ⟳
#define CUHR 0x27F2   //⟲
#define LSQ 0x201A    // ‚
#define HSQ 0x2018    // ‘
#define RSQ 0x2019    // ’
#define QLA 0x203A    // ›
#define QRA 0x2039    //‹
#define CENT 0x00A2   //¢
#define YEN 0x00A5    // ¥
#define REQ 0x00BB    // »
#define LEQ 0x00AB    // «
#define HI1 0x00B9    // ¹
#define HI2 0x00B2    // ²
#define HI3 0x00B3    // ³ 

// custom_keycodes for strings 
enum custom_keycodes {
    P_LOREM = SAFE_RANGE,
};
// Tap Dance declarations
enum {
    TD_SPC_ENT =0,
    TD_ENT_SPC,
};

enum layer_number { _vou = 0, _VOU, _LEVEL3, _LEVEL4, _QWERTZ, _FKEY };
void matrix_init_user(void) {
    set_unicode_input_mode(UC_WINC);
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* vou  IDEA: I could really use a dotcom tap macro on the dot and a lorem ipsum boilerplate on another level!
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |   ^  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |QWERTZ|
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |TB/FKY|   v  |   .  |   o  |   u  |   ä  |                    |   q  |   g  |   l  |   h  |   f  |  j   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  LV3 |   c  |   a  |   e  |   i  |   y  |-------.    ,-------|   b  |   t  |   r  |   n  |   s  | ß/LV3|
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |SHIFT |   z  |   x  |   ,  |   ü  |   ö  |-------|    |-------|   p  |   d  |   w  |   m  |   k  |LV2   |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   | LAlt | LGUI |LCTRL | /Space  /       \Enter \  |BSPC  |DEL   | LV4  |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */

    [_vou] = LAYOUT(
          DE_CIRC, DE_1, DE_2,   DE_3,    DE_4,    DE_5,                     DE_6, DE_7, DE_8, DE_9, DE_0, TG(_QWERTZ),
LT(_FKEY, KC_TAB), DE_V, DE_DOT, DE_O,    DE_U,    DE_ADIA,                  DE_Q, DE_G, DE_L, DE_H, DE_F, DE_J,
      MO(_LEVEL3), DE_C, DE_A,   DE_E,    DE_I,    DE_Y,                     DE_B, DE_T, DE_R, DE_N, DE_S, MO(_LEVEL3), 
          KC_LSFT, DE_Z, DE_X,   DE_COMM, DE_UDIA, DE_ODIA, KC_NO,    KC_NO, DE_P, DE_D, DE_W, DE_M, DE_K, TT(_VOU), 
                              KC_LALT, KC_LGUI, KC_LCTL, KC_SPC,     TD(TD_ENT_SPC), KC_BSPC, KC_DEL, MO(_LEVEL4)
    ),
    /* VOU
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |   ̌   |  °   |   §  |   ℓ  |   »  |  «   |                    |  $   |  €   |  „   | ”    |  “   |  ß   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  TAB |   V  |   •  |   O  |   U  |   Ä  |                    |   Q  |   G  |   L  |   H  |  F   |  J   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  LV3 |   C  |   A  |   E  |   I  |   Y  |-------.    ,-------|   B  |   T  |   R  |   N  |  S   |  LV3 |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * | SHIFT|   Z  |   X  |  –   |  Ü   |   Ö  |-------|    |-------|   P  |   D  |   W  |   M  |  K   |  LV2 |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   | LAlt | LGUI |LCTRL | /Space  /       \Enter \  |Back  |DEL   | LV4  |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_VOU] = LAYOUT( 
          UC(CUHR), DE_DEG,  DE_SECT, UC(SCRL),   UC(REQ),    UC(LEQ),                   DE_DLR,  DE_EURO, UC(LOW9), UC(HIG6), UC(HIG9), UC(SSS),
          KC_TAB,   S(DE_V), UC(BOB), S(DE_O),    S(DE_U),    S(DE_ADIA),                S(DE_Q), S(DE_G), S(DE_L),  S(DE_H),  S(DE_F),  S(DE_J),
          KC_TRNS,  S(DE_C), S(DE_A), S(DE_E),    S(DE_I),    S(DE_Y),                   S(DE_B), S(DE_T), S(DE_R),  S(DE_N),  S(DE_S),  KC_TRNS,
          KC_TRNS,  S(DE_Z), S(DE_X), UC(ENDASH), S(DE_UDIA), S(DE_ODIA), KC_NO,  KC_NO, S(DE_P), S(DE_D), S(DE_W),  S(DE_M),  S(DE_K),  KC_TRNS, 
                                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    /* LEVEL3
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  ⟳   |  ¹   |  ²   |  ³   |  ›   |  ‹   |                    |  ¢   |  ¥   |   ‚  |  ‘   |  ’   |  -   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  TAB |   ^  |   _  |  {   |   }  |   @  |                    |  !   |   <  |   >  |   =  |   &  |  %   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  LV3 |   \  |   /  |  (   |   )  |   *  |-------.    ,-------|   ?  |   :  |   ;  |   -  |   :  |  LV3 |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * | SHIFT|  #   |  ~   |  [   |   ]  |   $  |-------|    |-------|   +  |  "   |   '  |   |  |   +  |  LV2 |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   | LAlt | LGUI |LCTRL | /Space  /       \Enter \  |Back  |DEL   | LV4  |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */

    [_LEVEL3] = LAYOUT(
          UC(UHR), UC(HI1), UC(HI2), UC(HI3), UC(QLA), UC(QRA),              UC(CENT), UC(YEN), UC(LSQ), UC(HSQ), UC(RSQ), DE_MINS,
          KC_TAB,  DE_CIRC, DE_UNDS, DE_LCBR, DE_RCBR, DE_AT,                DE_EXLM,  DE_LABK, DE_RABK, DE_EQL,  DE_AMPR, DE_PERC,
          KC_TRNS, DE_BSLS, DE_SLSH, DE_LPRN, DE_RPRN, DE_ASTR,              DE_QUES,  DE_COLN, DE_SCLN, DE_MINS, DE_COLN, KC_TRNS, 
          KC_TRNS, DE_HASH, DE_TILD, DE_LBRC, DE_RBRC, DE_DLR, KC_NO, KC_NO, DE_PLUS,  DE_DQUO, DE_QUOT, DE_PIPE, DE_PLUS, KC_TRNS, 
                                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    /* LEVEL4
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | Lorem|      |      |      |      |      |                    |  snek|knight| xmas |      |sleep |power |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      | pgup |  up  | pgdn | pos1 |      |                    |breath|swirl | twin |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  LV3 |  lft |  dwn |  rgt |  ende|      |-------.    ,-------|bl off|RGB ON| HUE+ | SAT+ | VAL+ |  LV3 |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * | SHIFT|      |      |      |      |      |-------|    |-------|  MUTE| MODE | HUE- | SAT- | VAL- |  LV2 |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                  | LAlt | LGUI |LCTRL | /Space  /       \Enter \  |Back  |DEL   | LV4  |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_LEVEL4] = LAYOUT(
          P_LOREM,   XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,                 RGB_M_SN,   RGB_M_K,  RGB_M_X , XXXXXXX, KC_SLEP, KC_PWR, 
          XXXXXXX, KC_PGUP, KC_UP,   KC_PGDN,  KC_HOME, XXXXXXX,                 RGB_M_B,    RGB_M_SW, RGB_M_TW, XXXXXXX, XXXXXXX, XXXXXXX,
          KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END,  XXXXXXX,                 BL_OFF,     RGB_TOG,  RGB_HUI,  RGB_SAI, RGB_VAI, KC_TRNS,
          KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, KC_NO,   KC_NO, KC_KB_MUTE, RGB_MOD,  RGB_HUD,  RGB_SAD, RGB_VAD, KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    /* QWERTZ
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  vou |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Z  |   U  |   I  |   O  |   P  |  Ü   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |CAPS  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   Ö  |  Ä   |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |SHIFT |   Y  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   -  |RShift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   | LAlt | LGUI |LCTRL | /Space  /       \Enter \  |Back  |DEL   | RALT |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */

    [_QWERTZ] = LAYOUT(
          KC_ESC,  DE_1, DE_2, DE_3, DE_4, DE_5,                DE_6, DE_7, DE_8,    DE_9,   DE_0,    KC_TRNS, 
          KC_TAB,  DE_Q, DE_W, DE_E, DE_R, DE_T,                DE_Z, DE_U, DE_I,    DE_O,   DE_P,    DE_UDIA,
          KC_CAPS, DE_A, DE_S, DE_D, DE_F, DE_G,                DE_H, DE_J, DE_K,    DE_L,   DE_ODIA, DE_ADIA,
          KC_LSFT, DE_Y, DE_X, DE_C, DE_V, DE_B, KC_NO,  KC_NO, DE_N, DE_M, DE_COMM, DE_DOT, DE_MINS, KC_RSFT,
                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_RALT
    ),
    /* FKEY
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | trns |      |      |      |      |      |                    |   *  |   7  |   8  |   9  |   -  |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------.    ,-------|   /  |   4  |   5  |   6  |   +  |   -  |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|    |-------|   0  |   1  |   2  |   3  |   =  |   .  |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   | LAlt | LGUI |LCTRL | /Space  /       \Enter \  |Back  |DEL   | LV4  |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_FKEY] = LAYOUT(
          KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
          _______, _______, _______, _______, _______, _______,                     KC_PAST, KC_KP_7, KC_KP_8, KC_KP_9, KC_PMNS, _______,
          _______, _______, _______, _______, _______, _______,                     KC_PSLS, KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, KC_TILD,
          _______, _______, _______, _______, _______, _______, _______,   _______, KC_KP_0, KC_KP_1, KC_KP_2, KC_KP_3, KC_PENT, KC_KP_DOT,
                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};


// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_SPC_ENT] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_ENT),
    [TD_ENT_SPC] = ACTION_TAP_DANCE_DOUBLE(KC_ENT, KC_SPC)
};






//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    } else {
        return OLED_ROTATION_0;
    }
}

void render_lily58_logo(void) {
    static const char PROGMEM lily58_logo[] = {
    // 'logo', 128x32px
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0xc0, 0x40, 0x40, 0xc0, 0x80, 0x80, 0x80, 0x00, 0x00,
    0x80, 0xe0, 0x70, 0x3c, 0x0e, 0x06, 0x0e, 0x3c, 0x70, 0xe0, 0x80, 0x00, 0x00, 0xc0, 0xc0, 0x00,
    0xc0, 0xc0, 0x00, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x80,
    0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xfc, 0xc0, 0x80, 0x80, 0x80, 0x81, 0x83, 0x83,
    0x07, 0x07, 0x0c, 0x18, 0x70, 0xe0, 0x80, 0x00, 0x00, 0x01, 0xff, 0xfc, 0x80, 0xb6, 0xb6, 0x80,
    0xb0, 0xb0, 0x00, 0x36, 0x36, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf1, 0x00, 0x00, 0x00, 0x00, 0xff,
    0xff, 0x00, 0x00, 0x00, 0x30, 0xf0, 0xf0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xf0, 0xf0,
    0x30, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xe1, 0x71, 0x71, 0xf1, 0xf1, 0xe1, 0xc1, 0x81, 0x00, 0x00,
    0x00, 0x00, 0x0c, 0x3f, 0xff, 0xf3, 0xe1, 0xc1, 0xc1, 0x81, 0x81, 0xc3, 0xff, 0x7f, 0x1c, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x70, 0x78, 0xdc, 0xcc, 0x86, 0x06, 0x03, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x03, 0x02, 0x06, 0x84, 0xe1, 0xfb, 0x38, 0x1c, 0x0c, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x03, 0x03, 0x06, 0x86, 0xcc, 0xdc, 0x78, 0x70, 0x20, 0x00, 0xff, 0xff, 0x80, 0x80,
    0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff,
    0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1f, 0x7e, 0xf8, 0xe0, 0xf0, 0x7e, 0x1f, 0x03, 0x00,
    0x00, 0x00, 0x00, 0xe0, 0xe0, 0xc0, 0xc0, 0x80, 0x80, 0x80, 0xc0, 0xe1, 0xff, 0x7f, 0x3f, 0x00,
    0x00, 0x00, 0x3e, 0xff, 0xff, 0xc1, 0xc0, 0x80, 0x81, 0x81, 0xc3, 0xc3, 0xff, 0xfe, 0x3c, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x06, 0x06, 0x06, 0x04, 0x04, 0x04, 0x04, 0x06,
    0x06, 0x02, 0x03, 0x01, 0x01, 0x00, 0x01, 0x01, 0x03, 0x02, 0x06, 0x06, 0x04, 0x04, 0x04, 0x04,
    0x06, 0x06, 0x06, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x01, 0x01, 0x01, 0x00, 0x00, 0x60, 0x60, 0x70, 0x38, 0x1f, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00
};
    oled_write_raw_P(lily58_logo, sizeof(lily58_logo));
}


#    define KEYLOG_LEN 6
char     keylog_str[KEYLOG_LEN] = {};
uint8_t  keylogs_str_idx        = 0;
uint16_t log_timer              = 0;

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void add_keylog(uint16_t keycode) {
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
        keycode = keycode & 0xFF;
    }

    for (uint8_t i = KEYLOG_LEN - 1; i > 0; i--) {
        keylog_str[i] = keylog_str[i - 1];
    }
    if (keycode < 60) {
        keylog_str[0] = code_to_name[keycode];
    }
    keylog_str[KEYLOG_LEN - 1] = 0;

    log_timer = timer_read();
}

void update_log(void) {
    if (timer_elapsed(log_timer) > 750) {
        add_keylog(0);
    }
}

void render_keylogger_status(void) {
    oled_write_P(PSTR("KLogr"), false);
    oled_write(keylog_str, false);
}

void render_default_layer_state(void) {
    oled_write_P(PSTR("Layer"), false);
    oled_write_P(PSTR(" "), false);
    switch (get_highest_layer(layer_state)) {
        case _vou:
            oled_write_P(PSTR("vou"), false);
            break;
        case _VOU:
            oled_write_ln_P(PSTR("CAPS"), false);
            break;
        case _LEVEL3:
            oled_write_P(PSTR("NERD"), false);
            break;
        case _LEVEL4:
            oled_write_ln_P(PSTR("HUE"), false);
            break;
        case _QWERTZ:
            oled_write_P(PSTR("QWERTZ"), false);
        case _FKEY:
            oled_write_ln_P(PSTR("FKEY"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined"), false);
    }
}


void render_status_main(void) {
    // Show keyboard layout
    render_default_layer_state();
    // Add a empty line
    oled_write_P(PSTR("-----"), false);
    render_keylogger_status();
}

bool oled_task_user(void) {
  update_log();
  if (is_keyboard_master()) {
    render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
  } else {
    render_lily58_logo();
  }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case P_LOREM:
               SEND_STRING("Zombie ipsum reversus ab viral inferno, nam rick grimes malum cerebro.\n De carne lumbering animata corpora quaeritis.\n Summus brains sit morbo vel maleficia.\n De apocalypsi gorger omero undead survivor dictum mauris.\n Hi mindless mortuis soulless creaturas, imo evil stalking monstra adventus resi dentevil vultus comedat cerebella viventium.\n Qui animated corpse, cricket bat max brucks terribilem incessu zomby.\n The voodoo sacerdos flesh eater,exe fiat Jeff becum suscitat mortuos comedere carnem virus.\n Zonbi tattered for solum oculi eorum defunctis go lum cerebro. \n Nescio brains an Undead zombies.Sicut malus putrid voodoo horror.\n Nigh tofth eliv ingdead.\n");
            return  false;
            break;
            default:
                add_keylog(keycode);
    }
    return true;
}
#endif 


// Rotary encoder related code
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { // Encoder on master side
    if(IS_LAYER_ON(_VOU)) { // on Raise layer
      // Cursor control
      if (clockwise) {
          tap_code(KC_VOLU);
      } else {
          tap_code(KC_VOLD);
      }
    }
    else {
      if (clockwise) {
          tap_code(KC_UP);
      } else {
          tap_code(KC_DOWN);
      }
    }
  }
  else if (index == 1) { // Encoder on slave side
    if(IS_LAYER_ON(_LEVEL3)) { // on Lower layer
      //
      if (clockwise) {
          tap_code(KC_BSPC);
      } else {
          tap_code(KC_DEL);
      }
    }
    else {
      if (clockwise) {
          tap_code(KC_RIGHT);
      } else {
          tap_code(KC_LEFT);
      }
    }
  }
    return true;
}
#endif
