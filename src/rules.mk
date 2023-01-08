# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina

#shift holding rule
SRC += features/custom_shift_keys.c

# Build Options
#   change yes to no to disable
#
TAP_DANCE_ENABLE = yes      # enabling tab dances
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite

MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = yes        # Commands for debug and configuration
NKRO_ENABLE = no            # Enable N-Key Rollover
BACKLIGHT_ENABLE = no      # Enable keyboard backlight functionality
AUDIO_ENABLE = no           # Audio output
RGBLIGHT_ENABLE = no       # Enable WS2812 RGB underlight.

SPLIT_KEYBOARD = yes
