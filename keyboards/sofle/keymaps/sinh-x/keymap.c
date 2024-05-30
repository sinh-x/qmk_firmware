   



   // Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _COLEMAK,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    KC_QWERTY = QK_USER,
    KC_COLEMAK,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND
};

/*const uint16_t PROGMEM mouse_wh_down[] = {KC_MS_BTN1, KC_MS_BTN2, KC_MS_DOWN, COMBO_END};
const uint16_t PROGMEM mouse_wh_up[] = {KC_MS_BTN1, KC_MS_BTN2, KC_MS_UP, COMBO_END};*/


combo_t key_combos[] = {

};

// Tap Dance declarations
enum {
    TD_GRAVE_ESC,
    TD_SHIFT_CAP,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Grave, twice for Escape
    [TD_GRAVE_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_GRV, KC_ESC),
    [TD_SHIFT_CAP] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   =  |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  '   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  | Bspc |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | RAISE | LAlt | LGUI |Space| /LOWER  /       \RAISE \  |Space | RGUI | RAlt |LOWER |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT(
  TD(TD_GRAVE_ESC),   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                    KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                              KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_QUOT,
  TD(TD_SHIFT_CAP),   SGUI_T(KC_A),   LSFT_T(KC_S),    LALT_T(KC_D),   LGUI_T(KC_F), LCTL_T(KC_G),                     RCTL_T(KC_H),    LGUI_T(KC_J),    RALT_T(KC_K),    RSFT_T(KC_L), SGUI_T(KC_SCLN),  KC_BSPC,
  KC_LCTL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,           XXXXXXX,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
                 TL_UPPR,KC_LALT,KC_LGUI, KC_LGUI, LT(2,KC_SPC),       LT(3,KC_ENT), KC_RGUI, KC_RGUI, KC_RALT, TL_LOWR
),
/*
 * COLEMAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   =  |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   ;  |   '  |
 * |------+------+------+------+------+------|                    |--- 1---+------+------+------+------+------|
 * |LShift|   A  |   R  |   S  |   T  |   D  |-------.    ,-------|   H  |   N  |   E  |   I  |   O  | Bspc |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | LCTR |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   /  |   K  |   H  |   ,  |   .  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'`
 *            | RAISE | LAlt | LGUI |Space| /LOWER  /       \RAISE \  |Space | RGUI | RAlt |LOWER |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_COLEMAK] = LAYOUT(
  TD(TD_GRAVE_ESC),   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  KC_TAB,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                                KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,  KC_QUOT,
  TD(TD_SHIFT_CAP),   SGUI_T(KC_A),   LSFT_T(KC_R),    LALT_T(KC_S),    LGUI_T(KC_T),  LCTL_T(KC_G),                RCTL_T(KC_M),    LGUI_T(KC_N),    RALT_T(KC_E),    RSFT_T(KC_I),    SGUI_T(KC_O),  KC_BSPC,
  KC_LCTL,   KC_X,    KC_C,    KC_D,    KC_V,   KC_Z, KC_MUTE,          XXXXXXX, KC_SLSH, KC_K,    KC_H, KC_COMM,  KC_DOT, KC_RSFT,
                 TL_UPPR,KC_LALT,KC_LGUI, KC_LGUI, LT(2,KC_SPC),       LT(3,KC_ENT), KC_RGUI, KC_RGUI, KC_RALT, TL_LOWR
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   +  |   7 |   8  |   9   |   *  |                    |   [  |   $  |   (  |   )  |   &  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   -  |   4  |   5  |   6  |   /  |-------.    ,-------|   ]  |   @  |   ,  |   .  |   |  |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|  =   |  1   |  2   |   3  |   0  |-------|    |-------|   ^  |   #  |   ;  |   :  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | RAISE | LAlt | LGUI |Space| /LOWER  /       \RAISE \  | Enter| RGUI | RAlt |LOWER |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT(
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                 KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  KC_GRV,    KC_PLUS,    KC_7,    KC_8,    KC_9,    KC_ASTR,            KC_LBRC,  KC_DLR, KC_LPRN, KC_RPRN,  KC_AMPR,  KC_F12,
  _______, KC_MINS,  KC_4, KC_5,  KC_6, KC_SLSH,                       KC_RBRC,  KC_AT, KC_COMM, KC_DOT, KC_PIPE, _______,
  _______,  KC_EQL, KC_1, KC_2, KC_3, KC_0, _______,           _______, KC_CIRC,  KC_HASH, KC_LT, KC_GT, KC_BSLS, _______,
                       _______, _______, _______, _______, TL_LOWR,       TL_UPPR, _______, _______, _______, _______
),
/* RAISE
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  | Ins  | Pscr | Menu |      |      |                    | PG_UP| PWrd |  Up  | NWrd | DLine| Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------| PG_DN| Left | Down | Rigth|  Del | Bspc |
 * |------+------+------+------+------+------|  MUTE  |    |       |------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste| Redo |-------|    |-------|      | LStr |      | LEnd |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | RAISE | LAlt | LGUI |Space| /LOWER  /       \RAISE \  | Enter| RGUI | RAlt |LOWER |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT(
  _______, _______ , _______ , _______ , _______ , _______,                           _______,  _______  , _______,  _______ ,  _______ ,_______,
  _______,  KC_INS,  KC_PSCR,   KC_APP,  XXXXXXX, XXXXXXX,                        KC_PGUP, KC_PRVWD,   KC_UP, KC_NXTWD,C(KC_BSPC), KC_BSPC,
  _______, KC_LALT,  KC_LCTL,  KC_LSFT,  XXXXXXX, KC_CAPS,                       KC_PGDN,  KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL, KC_BSPC,
  _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), KC_AGIN,  _______,       _______,  XXXXXXX, KC_LSTRT, XXXXXXX, KC_LEND,   XXXXXXX, _______,
                         _______, _______, _______, _______, TL_LOWR,       TL_UPPR, _______, _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      | VOLDO| MUTE | VOLUP|      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | QK_BOOT|      |QWERTY|COLEMAK|      |      |                 |SCRL_UP| M_Bt1| MS_UP| M_Bt2|   | NEXT |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |MACWIN|      |      | TG(1)|-------.    ,-------|SCRL_DN| MS_L| MS_D | MS_R |      | PLAY |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      | CT_M1| M_Bt1| M_Bt2|      | TG(0)|-------|    |-------|      | CT_M1|      |      |      | PREV |
 * `-----------------------------------------/       /     \      \----------------------------------------'
 *            | RAISE | LAlt | LGUI |Space| /LOWER  /       \RAISE \  | Enter| RGUI | RAlt |LOWER |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX , XXXXXXX,  XXXXXXX ,  XXXXXXX , XXXXXXX, XXXXXXX,                        XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
  QK_BOOT  , XXXXXXX,KC_QWERTY,KC_COLEMAK,CG_TOGG,XXXXXXX,                          KC_MS_WH_UP, KC_MS_BTN1, KC_MS_UP, KC_MS_BTN2, XXXXXXX, KC_MNXT,
  XXXXXXX , XXXXXXX,CG_TOGG, XXXXXXX,    XXXXXXX,  TG(1),                           KC_MS_WH_DOWN, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, XXXXXXX, KC_MPLY,
  XXXXXXX , LCTL(KC_MS_BTN1), KC_MS_BTN1, KC_MS_BTN2, XXXXXXX,  TG(0), XXXXXXX,     XXXXXXX, XXXXXXX, LCTL(KC_MS_BTN1), XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV,
                   _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
  )
};

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Store the current modifier state in the variable for later reference
    mod_state = get_mods();

    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case KC_BSPC:
        {
            // Initialize a boolean variable that keeps track
            // of the delete key status: registered or not?
            static bool delkey_registered;
            if (record->event.pressed) {
                // Detect the activation of either shift keys
                if (mod_state & MOD_MASK_SHIFT) {
                    // First temporarily canceling both shifts so that
                    // shift isn't applied to the KC_DEL keycode
                    del_mods(MOD_MASK_SHIFT);
                    register_code(KC_DEL);
                    // Update the boolean variable to reflect the status of KC_DEL
                    delkey_registered = true;
                    // Reapplying modifier state so that the held shift key(s)
                    // still work even after having tapped the Backspace/Delete key.
                    set_mods(mod_state);
                    return false;
                }
            } else { // on release of KC_BSPC
                // In case KC_DEL is still being sent even after the release of KC_BSPC
                if (delkey_registered) {
                    unregister_code(KC_DEL);
                    delkey_registered = false;
                    return false;
                }
            }
            // Let QMK process the KC_BSPC keycode as usual outside of shift
            return true;
        }
    }
    return true;
}

void leader_start_user(void) {
    // Do something when the leader key is pressed
}

void leader_end_user(void) {

}