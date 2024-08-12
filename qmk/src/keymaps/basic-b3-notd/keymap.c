#include QMK_KEYBOARD_H

#include "features/custom_shift_keys.h"

const custom_shift_key_t custom_shift_keys[] = {
  {KC_DOT , KC_COMM}, // Shift . is ,
  {KC_SLSH, KC_COLN}, // Shift / is :
  {KC_MINS, KC_UNDS} // Shift - is _
};

uint8_t NUM_CUSTOM_SHIFT_KEYS = sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_custom_shift_keys(keycode, record)) { return false; }
  // Your macros ...

  return true;
}

//LAYERS
#define _BAS 0
#define _NAV 1
#define _NUM 2
#define _SYM 3
#define _FNC 4

//0 BASIC
#define TD_A    LSFT_T(KC_A)
#define TD_O    LCTL_T(KC_O)
#define TD_E    LALT_T(KC_E)
#define TD_I    LGUI_T(KC_I)
#define TD_D    RGUI_T(KC_D)
#define TD_T    RALT_T(KC_T)
#define TD_N    RCTL_T(KC_N)
#define TD_S    RSFT_T(KC_S)

#define TD_TAB LT(_FNC,KC_TAB)
#define TD_SPACE LT(_SYM,KC_SPACE)
#define TD_ENTER LT(_NAV,KC_ENTER)
#define TD_BSPC LT(_NUM,KC_BSPC)

//4 FUNCTIONAL
#define TD_F11  LSFT_T(KC_F11)
#define TD_F4   LCTL_T(KC_F4)
#define TD_F5   LALT_T(KC_F5)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BAS] = LAYOUT_5x4(
    KC_MINS  ,KC_SLSH  ,KC_DOT   ,KC_P     ,KC_Y     ,KC_F     ,KC_G     ,KC_C     ,KC_R     ,KC_L     ,
    TD_A     ,TD_O     ,TD_E     ,KC_U     ,TD_I     ,TD_D     ,KC_H     ,TD_T     ,TD_N     ,TD_S     ,
    KC_ESCAPE,KC_Q     ,KC_J     ,KC_K     ,KC_X     ,KC_B     ,KC_M     ,KC_W     ,KC_V     ,KC_Z     ,
                                  TD_TAB   ,TD_SPACE ,TD_ENTER ,TD_BSPC
    ),
    [_NAV] = LAYOUT_5x4(
    XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,KC_RGHT  ,
    KC_LSFT  ,KC_LCTL  ,KC_LALT  ,XXXXXXX  ,KC_LGUI  ,KC_LT    ,KC_LEFT  ,KC_LPRN  ,KC_LCBR  ,KC_LBRC  ,
    XXXXXXX  ,XXXXXXX  ,KC_DOWN  ,KC_UP    ,XXXXXXX  ,KC_GT    ,XXXXXXX  ,KC_RPRN  ,KC_RCBR  ,KC_RBRC  ,
                                  KC_TAB   ,KC_SPACE ,KC_ENTER ,XXXXXXX
    ),
    [_NUM] = LAYOUT_5x4(
    XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,KC_7     ,KC_8     ,KC_9     ,XXXXXXX  ,
    KC_LSFT  ,KC_LCTL  ,KC_LALT  ,XXXXXXX  ,KC_LGUI  ,KC_EQL   ,KC_4     ,KC_5     ,KC_6     ,KC_PLUS  ,
    XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,KC_0     ,KC_1     ,KC_2     ,KC_3     ,XXXXXXX  ,
                                  KC_TAB   ,KC_SPACE ,XXXXXXX  ,KC_BSPC
    ),
    [_SYM] = LAYOUT_5x4(
    KC_BSLS  ,KC_AMPR  ,KC_ASTR  ,KC_TILD  ,KC_GRV   ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,
    KC_PIPE  ,KC_DLR   ,KC_PERC  ,KC_CIRC  ,KC_QUOT  ,KC_RGUI  ,KC_SCLN  ,KC_LALT  ,KC_RCTL  ,KC_RSFT  ,
    KC_QUES  ,KC_EXLM  ,KC_AT    ,KC_HASH  ,KC_DQT   ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,
                                  XXXXXXX  ,KC_SPACE ,KC_ENTER ,KC_BSPC
    ),
    [_FNC] = LAYOUT_5x4(
    KC_F10   ,KC_F7    ,KC_F8    ,KC_F9    ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,
    TD_F11   ,TD_F4    ,TD_F5    ,KC_F6    ,KC_LGUI  ,KC_RGUI  ,XXXXXXX  ,KC_LALT  ,KC_RCTL  ,KC_RSFT  ,
    KC_F12   ,KC_F1    ,KC_F2    ,KC_F3    ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,
                                  KC_TAB   ,XXXXXXX  ,KC_ENTER ,KC_BSPC
    )

};
