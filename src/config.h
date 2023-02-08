/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 8
#define MATRIX_COLS 5


//RAW, GND, RST, VCC, F4, F5, F6, F7, B1, B3, B2, B6
//<<USB=PRO-MICRO PINS
// D3,  D2, GND, GND, D1, D0, D4, C6, D7, E6, B4, B5

// wiring of each half
#define MATRIX_ROW_PINS {     B1, B3, B2, B6 }
#define MATRIX_COL_PINS { C6, D7, E6, B4, B5 }

#define DIODE_DIRECTION COL2ROW

/* tapping settings */
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD
#undef TAPPING_TERM
#define TAPPING_TERM 175
#define RETRO_TAPPING

/* mouse key settings */
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY 5
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 16
#undef MOUSEKEY_MOVE_DELTA
#define MOUSEKEY_MOVE_DELTA 1
#undef MOUSEKEY_INITIAL_SPEED
#define MOUSEKEY_INITIAL_SPEED 1
#undef MOUSEKEY_DECELERATED_SPEED
#define MOUSEKEY_DECELERATED_SPEED 12
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 22
#define USB_SUSPEND_WAKEUP_DELAY 0
#undef MOUSEKEY_WHEEL_INTERVAL
#define MOUSEKEY_WHEEL_INTERVAL 83

#undef MOUSEKEY_WHEEL_INTERVAL
#define MOUSEKEY_WHEEL_INTERVAL 83

#undef MOUSEKEY_WHEEL_MAX_SPEED
#define MOUSEKEY_WHEEL_MAX_SPEED 3

/* mouse config commented in favor of ben walleck settings*/
// #define MOUSEKEY_INTERVAL       20
// #define MOUSEKEY_DELAY          0
// #define MOUSEKEY_TIME_TO_MAX    60
// #define MOUSEKEY_MAX_SPEED      7
// #define MOUSEKEY_WHEEL_DELAY 0

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* serial.c configuration for split keyboard */
#define SOFT_SERIAL_PIN D0

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* Enables This makes it easier for fast typists to use dual-function keys */
#define PERMISSIVE_HOLD

/* ws2812 RGB LED */
#define RGB_DI_PIN D3

#define RGBLED_NUM 12    // Number of LEDs


/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
// #define NO_DEBUG

/* disable print */
// #define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
