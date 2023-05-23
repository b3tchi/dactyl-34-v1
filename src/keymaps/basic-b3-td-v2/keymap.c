#include QMK_KEYBOARD_H

//SHIFT FEATURE
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

// TAP DANCE
//to avoid lot of duplication customized macro function ACTION_TAP_DANCE_FN_ADVANCED
#define MY_ATDFA(user_fn_on_each_tap, user_fn_on_dance_finished, user_fn_on_dance_reset, user_user_data) \
    { .fn = {user_fn_on_each_tap, user_fn_on_dance_finished, user_fn_on_dance_reset}, .user_data = (void *)user_user_data, }

typedef struct {
    uint16_t keycode_TAP;         // Keycode:
    uint8_t keycode_HOLD;         // Keycode:
} td_usr_t;

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_SINGLE_TAP
} td_state_t;

typedef struct {
    bool       is_press_action;
    td_state_t state;
} td_tap_t;

static td_tap_t td_tap_state = {
    .is_press_action = true,
    .state           = TD_NONE
};
// static td_state_t td_state;

// LAYOUT SETUP
enum tap_dance_codes {
    NAV_RGUI,
    NAV_RALT,
    NAV_RCTL,
    NAV_RSFT,

    NUM_RGUI,
    NUM_RSFT,

    SYM_LSFT,
    SYM_LCTL,
    SYM_LALT,
    SYM_LGUI,
};


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

//1 NAVIGATION
#define TD_LT   TD(NAV_RGUI)
#define TD_LPRN TD(NAV_RALT)
#define TD_LCBR TD(NAV_RCTL)
#define TD_LBRC TD(NAV_RSFT)

//2 NUMBERS
#define TD_EQL  TD(NUM_RGUI)
#define TD_5    RALT_T(KC_5)
#define TD_6    RCTL_T(KC_6)
#define TD_PLUS TD(NUM_RSFT)

//3 SYMBOLS
#define TD_PIPE TD(SYM_LSFT)
#define TD_DLR  TD(SYM_LCTL)
#define TD_PERC TD(SYM_LALT)
#define TD_QUOT TD(SYM_LGUI)

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
        KC_LSFT  ,KC_LCTL  ,KC_LALT  ,XXXXXXX  ,KC_LGUI  ,TD_LT    ,KC_LEFT  ,TD_LPRN  ,TD_LCBR  ,TD_LBRC  ,
        XXXXXXX  ,XXXXXXX  ,KC_DOWN  ,KC_UP    ,XXXXXXX  ,KC_GT    ,XXXXXXX  ,KC_RPRN  ,KC_RCBR  ,KC_RBRC  ,
                                      KC_TAB   ,KC_SPACE ,KC_ENTER ,XXXXXXX
    ),
    [_NUM] = LAYOUT_5x4(
        XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,KC_7     ,KC_8     ,KC_9     ,XXXXXXX  ,
        KC_LSFT  ,KC_LCTL  ,KC_LALT  ,XXXXXXX  ,KC_LGUI  ,TD_EQL   ,KC_4     ,TD_5     ,TD_6     ,TD_PLUS  ,
        XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,KC_0     ,KC_1     ,KC_2     ,KC_3     ,XXXXXXX  ,
                                      KC_TAB   ,KC_SPACE ,XXXXXXX  ,KC_BSPC
    ),
    [_SYM] = LAYOUT_5x4(
        KC_BSLS  ,KC_AMPR  ,KC_ASTR  ,KC_TILD  ,KC_GRV   ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,XXXXXXX  ,
        TD_PIPE  ,TD_DLR   ,TD_PERC  ,KC_CIRC  ,TD_QUOT  ,KC_RGUI  ,KC_SCLN  ,KC_LALT  ,KC_RCTL  ,KC_RSFT  ,
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

// extern bool g_suspend_state;
// #define GET_TAP_KC(dual_role_key) dual_role_key & 0xFF
// uint16_t last_keycode = KC_NO;
// uint8_t last_modifier = 0;

//TAP FUNCTIONS
// Determine the tapdance state to return
td_state_t cur_dance(tap_dance_state_t *state) {
     if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    }

    if (state->count == 2) return TD_DOUBLE_SINGLE_TAP;
    else return TD_UNKNOWN; // Any number higher than the maximum state value you return above/ Any number higher than the maximum state value you return above
}

void td_fin16(tap_dance_state_t *state, void *user_data) {
    td_tap_state.state = cur_dance(state);

    uint16_t  keycode_TAP   = ((td_usr_t *)user_data)->keycode_TAP;
    uint8_t  keycode_HOLD   = ((td_usr_t *)user_data)->keycode_HOLD;

    switch (td_tap_state.state) {
        case TD_SINGLE_TAP:
            register_code16(keycode_TAP);
            break;
        case TD_SINGLE_HOLD:
            register_mods(MOD_BIT(keycode_HOLD)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
            break;
        case TD_DOUBLE_SINGLE_TAP: // Allow nesting of 2 parens `((` within tapping term
            tap_code16(keycode_TAP);
            register_code16(keycode_TAP);
            break;
        default:
            break;
    }

}

void td_rst16(tap_dance_state_t *state, void *user_data) {
    uint16_t  keycode_TAP   = ((td_usr_t *)user_data)->keycode_TAP;
    uint8_t  keycode_HOLD   = ((td_usr_t *)user_data)->keycode_HOLD;

    switch (td_tap_state.state) {
        case TD_SINGLE_TAP:
            unregister_code16(keycode_TAP);
            break;
        case TD_SINGLE_HOLD:
            unregister_mods(MOD_BIT(keycode_HOLD)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
            break;
        case TD_DOUBLE_SINGLE_TAP:
            unregister_code16(keycode_TAP);
            break;
        default:
            break;
    }
    td_tap_state.state = TD_NONE;

}

void td_nav_ralt_fin16(tap_dance_state_t *state, void *user_data) {

    td_tap_state.state = cur_dance(state);
    switch (td_tap_state.state) {
        case TD_SINGLE_TAP:         register_code16(KC_LPRN);            break;
        case TD_SINGLE_HOLD:        register_mods(MOD_BIT(KC_RALT));     break;
        default: break;
    }
}

void td_nav_ralt_rst16(tap_dance_state_t *state, void *user_data) {

    switch (td_tap_state.state) {
        case TD_SINGLE_TAP:         unregister_code16(KC_LPRN);            break;
        case TD_SINGLE_HOLD:        unregister_mods(MOD_BIT(KC_RALT));     break;
        default: break;
    }

    td_tap_state.state = TD_NONE;
}

// --
tap_dance_action_t tap_dance_actions[] = {

    [NAV_RGUI] = MY_ATDFA(NULL, td_fin16, td_rst16, &((td_usr_t) {KC_LT, KC_RGUI})),
    [NAV_RCTL] = MY_ATDFA(NULL, td_fin16, td_rst16, &((td_usr_t) {KC_DLR, KC_LCTL})),
    [NAV_RALT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_nav_ralt_fin16, td_nav_ralt_rst16 ),
    [NAV_RSFT] = MY_ATDFA(NULL, td_fin16, td_rst16, &((td_usr_t) {KC_LBRC, KC_RSFT})),

    [NUM_RGUI] = MY_ATDFA(NULL, td_fin16, td_rst16, &((td_usr_t) {KC_EQL, KC_RGUI})),
    [NUM_RSFT] = MY_ATDFA(NULL, td_fin16, td_rst16, &((td_usr_t) {KC_PLUS, KC_RSFT})),

    [SYM_LSFT] = MY_ATDFA(NULL, td_fin16, td_rst16, &((td_usr_t) {KC_PIPE, KC_LSFT})),
    [SYM_LCTL] = MY_ATDFA(NULL, td_fin16, td_rst16, &((td_usr_t) {KC_DLR, KC_LCTL})),
    [SYM_LALT] = MY_ATDFA(NULL, td_fin16, td_rst16, &((td_usr_t) {KC_PERC, KC_LALT})),
    [SYM_LGUI] = MY_ATDFA(NULL, td_fin16, td_rst16, &((td_usr_t) {KC_QUOT, KC_LGUI}))

    // [NAV_RGUI] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_nav_ralt_fin16, td_nav_ralt_rst16 ),
    // [NAV_RCTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_nav_ralt_fin16, td_nav_ralt_rst16 ),
    // [NAV_RALT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_nav_ralt_fin16, td_nav_ralt_rst16 ),
    // [NAV_RSFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_nav_ralt_fin16, td_nav_ralt_rst16 ),
    //
    // [NUM_RGUI] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_nav_ralt_fin16, td_nav_ralt_rst16 ),
    // [NUM_RSFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_nav_ralt_fin16, td_nav_ralt_rst16 ),
    //
    // [SYM_LSFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_nav_ralt_fin16, td_nav_ralt_rst16 ),
    // [SYM_LCTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_nav_ralt_fin16, td_nav_ralt_rst16 ),
    // [SYM_LALT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_nav_ralt_fin16, td_nav_ralt_rst16 ),
    // [SYM_LGUI] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_nav_ralt_fin16, td_nav_ralt_rst16 )

};
