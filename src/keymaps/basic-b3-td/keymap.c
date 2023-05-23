#include QMK_KEYBOARD_H

#include "features/custom_shift_keys.h"

    const custom_shift_key_t custom_shift_keys[] = {
      {KC_DOT , KC_COMM}, // Shift . is ,
      {KC_SLSH, KC_COLN}, // Shift / is :
      {KC_MINS, KC_UNDS}, // Shift - is _
      {KC_LCBR, KC_RCBR}, // Shift { is }
      {KC_LBRC, KC_RBRC}, // Shift [ is ]
      {KC_PIPE, KC_BSLS}, /* Shift | is \ */
      {KC_LT  , KC_GT  }, // Shift < is >
      // {KC_LPRN, KC_RPRN}, // Shift ( is )
      {KC_QUES, KC_EXLM}, // Shift ? is !
      {KC_QUOT, KC_DQT }, // Shift ' is "
      {KC_EQL , KC_PLUS}, // Shift = is +
      {KC_BSPC, KC_DEL }, // Shift backspace is delete
      {KC_BRIGHTNESS_UP, KC_BRIGHTNESS_DOWN}, // Shift ' is "
      {KC_AUDIO_VOL_UP, KC_AUDIO_VOL_DOWN}, // Shift ' is "
      {KC_MEDIA_NEXT_TRACK, KC_MEDIA_PREV_TRACK} // Shift ' is "
    };

    uint8_t NUM_CUSTOM_SHIFT_KEYS = sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

    bool process_record_user(uint16_t keycode, keyrecord_t* record) {
      if (!process_custom_shift_keys(keycode, record)) { return false; }
      // Your macros ...

      return true;
    }

    enum tap_dance_codes {
      // PIPE_END,
      // EXT_CTL,

      // NAV_RGUI,
      // NAV_RALT,
      // NAV_RCTL,
      // NAV_RSFT,
      //
      // NUM_RGUI,
      // NUM_RSFT,
      //
      // SYM_LCTL,
      // SYM_LALT,
      // SYM_LGUI,
      // SYM_LSFT,
      //
      // BAS_LALT,

    };

#define _BAS 0
#define _NAV 1
#define _NUM 2
#define _SYM 3
#define _FNC 4

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
// #define TD_LT   TD(NAV_RGUI)
// #define TD_LPRN TD(NAV_RALT)
// #define TD_LCBR TD(NAV_RCTL)
// #define TD_LBRC TD(NAV_RSFT)

//2 NUMERICAL
// #define TD_EQL  TD(NUM_RGUI)
// #define TD_5    RALT_T(KC_5)
// #define TD_6    RCTL_T(KC_6)
// #define TD_PLUS TD(NUM_RSFT)

//3 SYMBOLS
D
//4 FUNCTIONAL
#define TD_F11  LSFT_T(KC_F11)
#define TD_F4   LCTL_T(KC_F4)
#define TD_F5   LALT_T(KC_F5)

    // #define LT2_COL LT(_RAISE, KC_SCLN)

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
        KC_LSFT  ,KC_LCTL  ,KC_LALT  ,XXXXXXX  ,KC_LGUI  ,KC_EQL   ,KC_4     ,TD_5     ,TD_6     ,KC_PLUS  ,
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

    extern bool g_suspend_state;
#define GET_TAP_KC(dual_role_key) dual_role_key & 0xFF
    uint16_t last_keycode = KC_NO;
    uint8_t last_modifier = 0;

    typedef struct {
        bool is_press_action;
        uint8_t step;
    } tap;

    enum {
        TD_NONE,
        TD_UNKNOWN,
        TD_SINGLE_TAP,
        TD_SINGLE_HOLD,
        TD_DOUBLE_SINGLE_TAP
    };

    static tap dance_state = {
        .is_press_action = true,
        .step = TD_NONE
    };


    uint8_t cur_dance(tap_dance_state_t *state) {
        if (state->count == 1) {
            if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
            else return TD_SINGLE_HOLD;
        }
        return TD_UNKNOWN; // Any number higher than the maximum state value you return above

    }

    void td_fin16(tap_dance_state_t *state, uint16_t  keycode_TAP, uint8_t  keycode_HOLD){
        dance_state.step = cur_dance(state);
        switch (dance_state.step) {
            case TD_SINGLE_TAP:         register_code16(keycode_TAP);                      break;
            case TD_SINGLE_HOLD:        register_mods(MOD_BIT(keycode_HOLD));               break;
            default: break;
        }
    }

    void td_rst16(tap_dance_state_t *state, uint16_t  keycode_TAP, uint8_t  keycode_HOLD) {
        wait_ms(10);
        switch (dance_state.step) {
            case TD_SINGLE_TAP:         unregister_code16(keycode_TAP);        break;
            case TD_SINGLE_HOLD:        unregister_mods(MOD_BIT(keycode_HOLD)); break;
            default: break;
        }
        dance_state.step = 0;
    }

    //NAV
    // void nav_rgui_finished(tap_dance_state_t *state, void *user_data) { td_fin16(state,KC_LT,KC_RGUI); }
    // void nav_rgui_reset(tap_dance_state_t *state, void *user_data)    { td_rst16(state,KC_LT,KC_RGUI); }
    //
    // void nav_ralt_finished(tap_dance_state_t *state, void *user_data) { td_fin16(state,KC_LPRN,KC_RALT); }
    // void nav_ralt_reset(tap_dance_state_t *state, void *user_data)    { td_rst16(state,KC_LPRN,KC_RALT); }
    //
    // void nav_rctl_finished(tap_dance_state_t *state, void *user_data) { td_fin16(state,KC_LCBR,KC_RCTL); }
    // void nav_rctl_reset(tap_dance_state_t *state, void *user_data)    { td_rst16(state,KC_LCBR,KC_RCTL); }
    //
    // void nav_rsft_finished(tap_dance_state_t *state, void *user_data) { td_fin16(state,KC_LBRC,KC_RSFT); }
    // void nav_rsft_reset(tap_dance_state_t *state, void *user_data)    { td_rst16(state,KC_LBRC,KC_RSFT); }
    //
    // //NUM
    // void num_rgui_finished(tap_dance_state_t *state, void *user_data) { td_fin16(state,KC_EQL,KC_RGUI); }
    // void num_rgui_reset(tap_dance_state_t *state, void *user_data)    { td_rst16(state,KC_EQL,KC_RGUI); }
    //
    // void num_rsft_finished(tap_dance_state_t *state, void *user_data) { td_fin16(state,KC_PLUS,KC_RSFT); }
    // void num_rsft_reset(tap_dance_state_t *state, void *user_data)    { td_rst16(state,KC_PLUS,KC_RSFT); }
    //
    // void bas_lalt_finished(tap_dance_state_t *state, void *user_data) { td_fin16(state,KC_LBRC,KC_LSFT); }
    // void bas_lalt_reset(tap_dance_state_t *state, void *user_data)    { td_rst16(state,KC_LBRC,KC_LSFT); }

    // --
    tap_dance_action_t tap_dance_actions[] = {
            // [NAV_RGUI] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, nav_rgui_finished, nav_rgui_reset),
            // [NAV_RALT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, nav_ralt_finished, nav_ralt_reset),
            // [NAV_RCTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, nav_rctl_finished, nav_rctl_reset),
            // [NAV_RSFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, nav_rsft_finished, nav_rsft_reset),
            //
            // [NUM_RGUI] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, num_rgui_finished, num_rgui_reset),
            // [NUM_RSFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, num_rsft_finished, num_rsft_reset),
            //
            // [BAS_LALT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, bas_lalt_finished, bas_lalt_reset),
    };
      // NUM_LGUI,
      // NUM_LSFT,
