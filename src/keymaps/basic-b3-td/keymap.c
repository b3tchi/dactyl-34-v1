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
};

// #define RAISE MO(_RAISE)
// #define LOWER MO(_LOWER)
//
// #define ONE_GRV LT(1,KC_GRAVE)
// #define CTL_Z LCTL_T(KC_Z)
// #define ALT_SHFT LALT(KC_LSFT)
// #define ALT_MENU LALT_T(KC_MENU)
// #define LG_QUOT LGUI_T(KC_QUOT)
// #define CTL_ESC LCTL_T(KC_ESC)
   #define CTL_LA LCTL_T(KC_LEFT)
   #define CTL_RA LCTL_T(KC_RGHT)
// #define LT2_COL LT(_RAISE, KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_5x4(
        KC_MINS              ,KC_SLSH          ,KC_DOT              ,KC_P          ,KC_Y             ,KC_F              ,KC_G              ,KC_C              ,KC_R             ,KC_L ,
        MT(MOD_LSFT,KC_A)    ,MT(MOD_LCTL,KC_O),MT(MOD_LALT,KC_E)   ,KC_U          ,MT(MOD_LGUI,KC_I),MT(MOD_RGUI,KC_D) ,KC_H              ,TD(BAS_LALT)      ,MT(MOD_RCTL,KC_N),MT(MOD_RSFT,KC_S) ,
        KC_ESCAPE            ,KC_Q             ,KC_J                ,KC_K          ,KC_X             ,KC_B              ,KC_M              ,KC_W              ,KC_V             ,KC_Z ,
        LT(4,KC_TAB)         ,LT(3,KC_SPACE)   ,LT(1,KC_ENTER)      ,LT(2,KC_BSPC)
    ),
    [1] = LAYOUT_5x4(
        KC_1                 ,KC_2             ,KC_3                ,KC_4          ,KC_GT                ,KC_EQL            ,KC_NO         ,KC_NO             ,KC_NO            ,KC_RGHT,
        MT(MOD_LSFT,KC_TAB)  ,MT(MOD_LCTL,KC_1),MT(MOD_LALT,KC_EQL) ,KC_EXLM       ,MT(MOD_RGUI,KC_QUOT) ,TD(SYM_LGUI)      ,KC_LEFT       ,TD(SYM_LALT)      ,TD(SYM_LCTL)     ,TD(SYM_LSFT), //KC_LBRC
        KC_ESCAPE            ,KC_NO            ,KC_DOWN             ,KC_UP         ,KC_NO                ,KC_GT             ,KC_NO         ,KC_RPRN           ,KC_RCBR          ,KC_RBRC,
        TO(0)                ,KC_SPACE         ,KC_ENTER            ,KC_BSPC
    ),
    [2] = LAYOUT_5x4(
        KC_F10               ,KC_F7             ,KC_F8               ,KC_F9        ,KC_NO                ,KC_MINS              ,KC_7  ,KC_8              ,KC_9          ,KC_NO     ,
        MT(MOD_LSFT,KC_F11)  ,MT(MOD_LCTL,KC_F4),MT(MOD_LALT,KC_F5)  ,KC_F6        ,MT(MOD_RGUI,KC_QUOT) ,MT(MOD_RGUI,KC_QUOT) ,KC_4  ,MT(MOD_LALT,KC_5) ,MT(MOD_RCTL,KC_6),KC_NO  ,
        KC_F12               ,KC_F1             ,KC_F2               ,KC_F3        ,KC_NO                ,KC_0                 ,KC_1  ,KC_2              ,KC_3          ,KC_NO     ,
        TO(0)                ,KC_SPACE          ,KC_ENTER            ,KC_BSPC
    ),
    [3] = LAYOUT_5x4(
        KC_BSLS              ,KC_AMPR       ,KC_ASTR             ,KC_TILD              ,KC_GRV       ,KC_MINS      ,KC_7         ,KC_8               ,KC_9               ,KC_MS_RIGHT    ,
        KC_PIPE              ,KC_DLR        ,KC_PERC             ,KC_CIRC              ,KC_QUOT      ,KC_EQL       ,KC_4         ,KC_5               ,KC_6               ,KC_ENTER       ,
        KC_QUES              ,KC_EXLM       ,KC_AT               ,KC_HASH              ,KC_DQT       ,KC_0         ,KC_1         ,KC_2               ,KC_3               ,KC_LGUI        ,
        TO(0)                ,KC_SPACE      ,KC_ENTER            ,KC_BSPC
    ),
    [4] = LAYOUT_5x4(
        KC_F10               ,KC_F7             ,KC_F8               ,KC_F9        ,KC_NO                ,KC_MINS              ,KC_7  ,KC_8              ,KC_9          ,KC_NO     ,
        MT(MOD_LSFT,KC_F11)  ,MT(MOD_LCTL,KC_F4),MT(MOD_LALT,KC_F5)  ,KC_F6        ,MT(MOD_RGUI,KC_QUOT) ,MT(MOD_RGUI,KC_QUOT) ,KC_4  ,MT(MOD_LALT,KC_5) ,MT(MOD_RCTL,KC_6),KC_NO  ,
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
    .step = 0
};

// void on_pipe_end(qk_tap_dance_state_t *state, void *user_data);
// uint8_t pipe_end_dance_step(qk_tap_dance_state_t *state);
// void pipe_end_finished(qk_tap_dance_state_t *state, void *user_data);
// void pipe_end_reset(qk_tap_dance_state_t *state, void *user_data);
//
// void on_pipe_end(qk_tap_dance_state_t *state, void *user_data) {
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
// uint8_t pipe_end_dance_step(qk_tap_dance_state_t *state) {
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
// void pipe_end_finished(qk_tap_dance_state_t *state, void *user_data) {
//     dance_state.step = pipe_end_dance_step(state);
//     switch (dance_state.step) {
//         case SINGLE_TAP: register_code16(KC_PIPE); break;
//         case SINGLE_HOLD: register_code16(KC_END); break;
//         case DOUBLE_TAP: register_code16(KC_PIPE); register_code16(KC_PIPE); break;
//         case DOUBLE_SINGLE_TAP: tap_code16(KC_PIPE); register_code16(KC_PIPE);
//     }
// }
//
// void pipe_end_reset(qk_tap_dance_state_t *state, void *user_data) {
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
uint8_t sym_lgui_dance_step(qk_tap_dance_state_t *state);
void sym_lgui_finished(qk_tap_dance_state_t *state, void *user_data);
void sym_lgui_reset(qk_tap_dance_state_t *state, void *user_data);

uint8_t sym_lgui_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    }
    return TD_UNKNOWN; // Any number higher than the maximum state value you return above

}
void sym_lgui_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = sym_lgui_dance_step(state);
    switch (dance_state.step) {
        case TD_SINGLE_TAP:         register_code16(KC_LT);                      break;
        case TD_SINGLE_HOLD:        register_mods(MOD_BIT(KC_LGUI));               break;
        default: break;
    }
}

void sym_lgui_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case TD_SINGLE_TAP:         unregister_code16(KC_LT);        break;
        case TD_SINGLE_HOLD:        unregister_mods(MOD_BIT(KC_LGUI)); break;
        default: break;
    }
    dance_state.step = 0;
}

// --
uint8_t sym_lalt_dance_step(qk_tap_dance_state_t *state);
void sym_lalt_finished(qk_tap_dance_state_t *state, void *user_data);
void sym_lalt_reset(qk_tap_dance_state_t *state, void *user_data);

uint8_t sym_lalt_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    }
    return TD_UNKNOWN; // Any number higher than the maximum state value you return above

}
void sym_lalt_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = sym_lalt_dance_step(state);
    switch (dance_state.step) {
        case TD_SINGLE_TAP:         register_code16(KC_LPRN);                      break;
        case TD_SINGLE_HOLD:        register_mods(MOD_BIT(KC_LALT));               break;
        default: break;
    }
}

void sym_lalt_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case TD_SINGLE_TAP:         unregister_code16(KC_LPRN);        break;
        case TD_SINGLE_HOLD:        unregister_mods(MOD_BIT(KC_LALT)); break;
        default: break;
    }
    dance_state.step = 0;
}

// --
uint8_t sym_lctl_dance_step(qk_tap_dance_state_t *state);
void sym_lctl_finished(qk_tap_dance_state_t *state, void *user_data);
void sym_lctl_reset(qk_tap_dance_state_t *state, void *user_data);

uint8_t sym_lctl_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    }
    return TD_UNKNOWN; // Any number higher than the maximum state value you return above

}
void sym_lctl_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = sym_lctl_dance_step(state);
    switch (dance_state.step) {
        case TD_SINGLE_TAP:         register_code16(KC_LCBR);                      break;
        case TD_SINGLE_HOLD:        register_mods(MOD_BIT(KC_LCTL));               break;
        default: break;
    }
}

void sym_lctl_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case TD_SINGLE_TAP:         unregister_code16(KC_LCBR);        break;
        case TD_SINGLE_HOLD:        unregister_mods(MOD_BIT(KC_LCTL)); break;
        default: break;
    }
    dance_state.step = 0;
}

// --
uint8_t sym_lsft_dance_step(qk_tap_dance_state_t *state);
void sym_lsft_finished(qk_tap_dance_state_t *state, void *user_data);
void sym_lsft_reset(qk_tap_dance_state_t *state, void *user_data);

uint8_t sym_lsft_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    }
    return TD_UNKNOWN; // Any number higher than the maximum state value you return above

}
void sym_lsft_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = sym_lsft_dance_step(state);
    switch (dance_state.step) {
        case TD_SINGLE_TAP:         register_code16(KC_LBRC);                      break;
        case TD_SINGLE_HOLD:        register_mods(MOD_BIT(KC_LSFT));               break;
        default: break;
    }
}

void sym_lsft_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case TD_SINGLE_TAP:         unregister_code16(KC_LBRC);        break;
        case TD_SINGLE_HOLD:        unregister_mods(MOD_BIT(KC_LSFT)); break;
        default: break;
    }
    dance_state.step = 0;
}

// --
uint8_t bas_lalt_dance_step(qk_tap_dance_state_t *state);
void bas_lalt_finished(qk_tap_dance_state_t *state, void *user_data);
void bas_lalt_reset(qk_tap_dance_state_t *state, void *user_data);

uint8_t bas_lalt_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    }
    return TD_UNKNOWN; // Any number higher than the maximum state value you return above

}
void bas_lalt_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = bas_lalt_dance_step(state);
    switch (dance_state.step) {
        case TD_SINGLE_TAP:         register_code(KC_T);                      break;
        case TD_SINGLE_HOLD:        register_mods(MOD_BIT(KC_LALT));          break;
        default: break;
    }
}

void bas_lalt_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case TD_SINGLE_TAP:         unregister_code(KC_T);        break;
        case TD_SINGLE_HOLD:        unregister_mods(MOD_BIT(KC_LSFT)); break;
        default: break;
    }
    dance_state.step = 0;
}

// --
qk_tap_dance_action_t tap_dance_actions[] = {
        // [PIPE_END] = ACTION_TAP_DANCE_FN_ADVANCED(on_pipe_end, pipe_end_finished, pipe_end_reset),
        [SYM_LCTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sym_lctl_finished, sym_lctl_reset),
        [SYM_LALT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sym_lalt_finished, sym_lalt_reset),
        [SYM_LGUI] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sym_lgui_finished, sym_lgui_reset),
        [SYM_LSFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sym_lsft_finished, sym_lsft_reset),
        [BAS_LALT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, bas_lalt_finished, bas_lalt_reset),
};
