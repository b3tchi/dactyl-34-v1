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
      EXT_CTL,
      SYM_LCTL,
      SYM_LALT,
      SYM_LGUI,
      SYM_LSFT,
      BAS_LALT,
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
#define TD_LT   TD(SYM_LGUI)
#define TD_LPRN TD(SYM_LALT)
#define TD_LCBR TD(SYM_LCTL)
#define TD_LBRC TD(SYM_LSFT)

//2 NUMERICAL
#define TD_5    RALT_T(KC_5)
#define TD_6    RCTL_T(KC_6)

//3 SYMBOLS

//4 FUNCTIONAL
#define TD_F11  LSFT_T(KC_F11)
#define TD_F4   LCTL_T(KC_F4)
#define TD_F5   LALT_T(KC_F5)

    // #define LT2_COL LT(_RAISE, KC_SCLN)

    const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        [_BAS] = LAYOUT_5x4(
            KC_MINS              ,KC_SLSH          ,KC_DOT              ,KC_P          ,KC_Y             ,KC_F              ,KC_G              ,KC_C              ,KC_R             ,KC_L ,
            TD_A    ,TD_O,TD_E   ,KC_U          ,TD_I,TD_D ,KC_H              ,TD_T      ,TD_N,TD_S ,
            KC_ESCAPE            ,KC_Q             ,KC_J                ,KC_K          ,KC_X             ,KC_B              ,KC_M              ,KC_W              ,KC_V             ,KC_Z ,
            TD_TAB         ,TD_SPACE   ,TD_ENTER      ,TD_BSPC
        ),
        [_NAV] = LAYOUT_5x4(
            KC_1                 ,KC_2             ,KC_3                ,KC_4          ,KC_GT                ,KC_EQL            ,KC_NO         ,KC_NO             ,KC_NO            ,KC_RGHT,
            MT(MOD_LSFT,KC_TAB)  ,MT(MOD_LCTL,KC_1),MT(MOD_LALT,KC_EQL) ,KC_EXLM       ,MT(MOD_RGUI,KC_QUOT) ,TD_LT      ,KC_LEFT       ,TD_LPRN      ,TD_LCBR     ,TD_LBRC, //KC_LBRC
            KC_ESCAPE            ,KC_NO            ,KC_DOWN             ,KC_UP         ,KC_NO                ,KC_GT             ,KC_NO         ,KC_RPRN           ,KC_RCBR          ,KC_RBRC,
            TO(0)                ,KC_SPACE         ,KC_ENTER            ,KC_BSPC
        ),
        [_NUM] = LAYOUT_5x4(
            KC_F10               ,KC_F7             ,KC_F8               ,KC_F9        ,KC_NO                ,KC_MINS              ,KC_7  ,KC_8              ,KC_9          ,KC_NO     ,
            MT(MOD_LSFT,KC_F11)  ,MT(MOD_LCTL,KC_F4),MT(MOD_LALT,KC_F5)  ,KC_F6        ,MT(MOD_RGUI,KC_QUOT) ,MT(MOD_RGUI,KC_QUOT) ,KC_4  ,TD_5 ,TD_6,KC_PLUS  ,
            KC_F12               ,KC_F1             ,KC_F2               ,KC_F3        ,KC_NO                ,KC_0                 ,KC_1  ,KC_2              ,KC_3          ,KC_NO     ,
            TO(0)                ,KC_SPACE          ,KC_ENTER            ,KC_BSPC
        ),
        [_SYM] = LAYOUT_5x4(
            KC_BSLS              ,KC_AMPR       ,KC_ASTR             ,KC_TILD              ,KC_GRV       ,KC_MINS      ,KC_7         ,KC_8               ,KC_9               ,KC_MS_RIGHT    ,
            KC_PIPE              ,KC_DLR        ,KC_PERC             ,KC_CIRC              ,KC_QUOT      ,KC_EQL       ,KC_SCLN         ,KC_5               ,KC_6               ,KC_ENTER       ,
            KC_QUES              ,KC_EXLM       ,KC_AT               ,KC_HASH              ,KC_DQT       ,KC_0         ,KC_1         ,KC_2               ,KC_3               ,KC_LGUI        ,
            TO(0)                ,KC_SPACE      ,KC_ENTER            ,KC_BSPC
        ),
        [_FNC] = LAYOUT_5x4(
            KC_F10               ,KC_F7             ,KC_F8               ,KC_F9        ,KC_NO                ,KC_MINS              ,KC_7  ,KC_8              ,KC_9          ,KC_NO     ,
            TD_F11  ,TD_F4, TD_F5  ,KC_F6        ,KC_RGUI ,MT(MOD_RGUI,KC_QUOT) ,KC_4  ,MT(MOD_LALT,KC_5) ,MT(MOD_RCTL,KC_6),KC_NO  ,
            KC_F12               ,KC_F1             ,KC_F2               ,KC_F3        ,KC_NO                ,KC_0                 ,KC_1  ,KC_2              ,KC_3          ,KC_NO     ,
            TO(0)                ,KC_SPACE      ,KC_ENTER            ,KC_BSPC
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

    // void on_pipe_end(tap_dance_state_t *state, void *user_data);
    // uint8_t pipe_end_dance_step(tap_dance_state_t *state);
    // void pipe_end_finished(tap_dance_state_t *state, void *user_data);
    // void pipe_end_reset(tap_dance_state_t *state, void *user_data);
    //
    // void on_pipe_end(tap_dance_state_t *state, void *user_data) {
    //     if(state->count == 3) {
    //         tap_code16(KC_PIPE);
    //         tap_code16(KC_PIPE);
    //         tap_code16(KC_PIPE);
    //     }
    //     if(state->count > 3) {
    //         tap_code16(KC_PIPE);
    //     }
    // }
    //
    // uint8_t pipe_end_dance_step(tap_dance_state_t *state) {
    //     if (state->count == 1) {
    //         if (state->interrupted || !state->pressed) return SINGLE_TAP;
    //         else return SINGLE_HOLD;
    //     } else if (state->count == 2) {
    //         if (state->interrupted) return DOUBLE_SINGLE_TAP;
    //         else if (state->pressed) return DOUBLE_HOLD;
    //         else return DOUBLE_TAP;
    //     }
    //     return MORE_TAPS;
    // }
    // void pipe_end_finished(tap_dance_state_t *state, void *user_data) {
    //     dance_state.step = pipe_end_dance_step(state);
    //     switch (dance_state.step) {
    //         case SINGLE_TAP: register_code16(KC_PIPE); break;
    //         case SINGLE_HOLD: register_code16(KC_END); break;
    //         case DOUBLE_TAP: register_code16(KC_PIPE); register_code16(KC_PIPE); break;
    //         case DOUBLE_SINGLE_TAP: tap_code16(KC_PIPE); register_code16(KC_PIPE);
    //     }
    // }
    //
    // void pipe_end_reset(tap_dance_state_t *state, void *user_data) {
    //     wait_ms(10);
    //     switch (dance_state.step) {
    //         case SINGLE_TAP: unregister_code16(KC_PIPE); break;
    //         case SINGLE_HOLD: unregister_code16(KC_END); break;
    //         case DOUBLE_TAP: unregister_code16(KC_PIPE); break;
    //         case DOUBLE_SINGLE_TAP: unregister_code16(KC_PIPE); break;
    //     }
    //     dance_state.step = 0;
    // }

    // --
    // uint8_t sym_lgui_dance_step(tap_dance_state_t *state);
    // void sym_lgui_finished(tap_dance_state_t *state, void *user_data);
    // void sym_lgui_reset(tap_dance_state_t *state, void *user_data);

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

    void sym_lgui_finished(tap_dance_state_t *state, void *user_data) {
        td_fin16(state,KC_LT,KC_LGUI);
    }

    void sym_lgui_reset(tap_dance_state_t *state, void *user_data) {
        td_rst16(state,KC_LT,KC_LGUI);
    }

    // --
    void sym_lalt_finished(tap_dance_state_t *state, void *user_data) {
        td_fin16(state,KC_LPRN,KC_LALT);
    }

    void sym_lalt_reset(tap_dance_state_t *state, void *user_data) {
        td_rst16(state,KC_LPRN,KC_LALT);
    }

    // --
    // uint8_t sym_lctl_dance_step(tap_dance_state_t *state);
    // void sym_lctl_finished(tap_dance_state_t *state, void *user_data);
    // void sym_lctl_reset(tap_dance_state_t *state, void *user_data);
    //
    // uint8_t sym_lctl_dance_step(tap_dance_state_t *state) {
    //     if (state->count == 1) {
    //         if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
    //         else return TD_SINGLE_HOLD;
    //     }
    //     return TD_UNKNOWN; // Any number higher than the maximum state value you return above
    //
    // }

    void sym_lctl_finished(tap_dance_state_t *state, void *user_data) {
        td_fin16(state,KC_LCBR,KC_LCTL);
        // dance_state.step = cur_dance(state);
        // switch (dance_state.step) {
        //     case TD_SINGLE_TAP:         register_code16(KC_LCBR);                      break;
        //     case TD_SINGLE_HOLD:        register_mods(MOD_BIT(KC_LCTL));               break;
        //     default: break;
        // }
    }

    void sym_lctl_reset(tap_dance_state_t *state, void *user_data) {
        td_rst16(state,KC_LCBR,KC_LCTL);
        // wait_ms(10);
        // switch (dance_state.step) {
        //     case TD_SINGLE_TAP:         unregister_code16(KC_LCBR);        break;
        //     case TD_SINGLE_HOLD:        unregister_mods(MOD_BIT(KC_LCTL)); break;
        //     default: break;
        // }
        // dance_state.step = 0;
    }

    // --
    // uint8_t sym_lsft_dance_step(tap_dance_state_t *state);
    // void sym_lsft_finished(tap_dance_state_t *state, void *user_data);
    // void sym_lsft_reset(tap_dance_state_t *state, void *user_data);
    //
    // uint8_t sym_lsft_dance_step(tap_dance_state_t *state) {
    //     if (state->count == 1) {
    //         if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
    //         else return TD_SINGLE_HOLD;
    //     }
    //     return TD_UNKNOWN; // Any number higher than the maximum state value you return above
    //
    // }

    void sym_lsft_finished(tap_dance_state_t *state, void *user_data) { td_fin16(state,KC_LBRC,KC_LSFT); }
        // dance_state.step = cur_dance(state);
        // switch (dance_state.step) {
        //     case TD_SINGLE_TAP:         register_code16(KC_LBRC);                      break;
        //     case TD_SINGLE_HOLD:        register_mods(MOD_BIT(KC_LSFT));               break;
        //     default: break;
        // }
    // }

    void sym_lsft_reset(tap_dance_state_t *state, void *user_data) { td_rst16(state,KC_LBRC,KC_LSFT); }
        // wait_ms(10);
        // switch (dance_state.step) {
        //     case TD_SINGLE_TAP:         unregister_code16(KC_LBRC);        break;
        //     case TD_SINGLE_HOLD:        unregister_mods(MOD_BIT(KC_LSFT)); break;
        //     default: break;
        // }
        // dance_state.step = 0;
    // }

    // --
    // uint8_t bas_lalt_dance_step(tap_dance_state_t *state);
    // void bas_lalt_finished(tap_dance_state_t *state, void *user_data);
    // void bas_lalt_reset(tap_dance_state_t *state, void *user_data);

    // uint8_t bas_lalt_dance_step(tap_dance_state_t *state) {
    //     if (state->count == 1) {
    //         if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
    //         else return TD_SINGLE_HOLD;
    //     }
    //     return TD_UNKNOWN; // Any number higher than the maximum state value you return above
    //
    // }

    void bas_lalt_finished(tap_dance_state_t *state, void *user_data) { td_fin16(state,KC_LBRC,KC_LSFT); }// dance_state.step = cur_dance(state);
        // switch (dance_state.step) {
        //     case TD_SINGLE_TAP:         register_code(KC_T);                      break;
        //     case TD_SINGLE_HOLD:        register_mods(MOD_BIT(KC_LALT));          break;
        //     default: break;
        // }
    // }

    void bas_lalt_reset(tap_dance_state_t *state, void *user_data) { td_rst16(state,KC_LBRC,KC_LSFT); }
        // wait_ms(10);
        // switch (dance_state.step) {
        //     case TD_SINGLE_TAP:         unregister_code(KC_T);        break;
        //     case TD_SINGLE_HOLD:        unregister_mods(MOD_BIT(KC_LSFT)); break;
        //     default: break;
        // }
        // dance_state.step = 0;
    // }

    // --
    tap_dance_action_t tap_dance_actions[] = {
            // [PIPE_END] = ACTION_TAP_DANCE_FN_ADVANCED(on_pipe_end, pipe_end_finished, pipe_end_reset),
            [SYM_LCTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sym_lctl_finished, sym_lctl_reset),
            [SYM_LALT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sym_lalt_finished, sym_lalt_reset),
            [SYM_LGUI] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sym_lgui_finished, sym_lgui_reset),
            [SYM_LSFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sym_lsft_finished, sym_lsft_reset),
            [BAS_LALT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, bas_lalt_finished, bas_lalt_reset),
    };
