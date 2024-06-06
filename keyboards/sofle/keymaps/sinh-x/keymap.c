// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum  ofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _COLEMAK,
    _LOWER,
    _RAISE,
    _ADJUST,
    _MOUSE
};

enum custom_keycodes {
    KC_QWERTY = QK_USER,
    KC_COLEMAK,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_CSF12,
};

// Tap Dance declarations
enum {
    TD_GRAVE_ESC,
    TD_SHIFT_CAP,
    TD_QUOTE,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Grave, twice for Escape
    [TD_GRAVE_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_GRV),
    [TD_SHIFT_CAP] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
    [TD_QUOTE] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_QUOT)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//        ┌────────┬───┬───────────┬───────────┬───────────┬───────────┐                             ┌───────────┬───────────┬───────────┬───────────┬───┬──────┐
//        │   `    │ 1 │     2     │     3     │     4     │     5     │                             │     =     │     6     │     7     │     8     │ 9 │  0   │
//        ├────────┼───┼───────────┼───────────┼───────────┼───────────┤                             ├───────────┼───────────┼───────────┼───────────┼───┼──────┤
//        │  tab   │ q │     w     │     e     │     r     │     t     │                             │     y     │     u     │     i     │     o     │ p │  '   │
//        ├────────┼───┼───────────┼───────────┼───────────┼───────────┤                             ├───────────┼───────────┼───────────┼───────────┼───┼──────┤
//        │  esc   │ a │ LCTL_T(s) │ LALT_T(d) │ LSFT_T(f) │ LGUI_T(g) │                             │ RGUI_T(h) │ RSFT_T(j) │ RALT_T(k) │ RCTL_T(l) │ ; │ bspc │
//        ├────────┼───┼───────────┼───────────┼───────────┼───────────┼────────────┐   ┌────────────┼───────────┼───────────┼───────────┼───────────┼───┼──────┤
//        │ SH_MON │ z │     x     │     c     │     v     │     b     │    mute    │   │     no     │     n     │     m     │     ,     │     .     │ / │ rsft │
//        └────────┴───┼───────────┼───────────┼───────────┼───────────┼────────────┤   ├────────────┼───────────┼───────────┼───────────┼───────────┼───┴──────┘
//                     │  TL_UPPR  │  SH_TOGG  │   lgui    │   TT(5)   │ LT(2, spc) │   │ LT(3, ent) │   TT(5)   │   rgui    │  SH_TOGG  │  TL_LOWR  │           
//                     └───────────┴───────────┴───────────┴───────────┴────────────┘   └────────────┴───────────┴───────────┴───────────┴───────────┘           
[_QWERTY] = LAYOUT_sinh_x_58(
      KC_GRV , KC_1 , KC_2         , KC_3         , KC_4         , KC_5         ,                                     KC_EQL       , KC_6         , KC_7         , KC_8         , KC_9    , KC_0   ,
      KC_TAB , KC_Q , KC_W         , KC_E         , KC_R         , KC_T         ,                                     KC_Y         , KC_U         , KC_I         , KC_O         , KC_P    , KC_QUOT,
      KC_ESC , KC_A , LCTL_T(KC_S) , LALT_T(KC_D) , LSFT_T(KC_F) , LGUI_T(KC_G) ,                                     RGUI_T(KC_H) , RSFT_T(KC_J) , RALT_T(KC_K) , RCTL_T(KC_L) , KC_SCLN , KC_BSPC,
      SH_MON , KC_Z , KC_X         , KC_C         , KC_V         , KC_B         , KC_MUTE       ,     XXXXXXX       , KC_N         , KC_M         , KC_COMM      , KC_DOT       , KC_SLSH , KC_RSFT,
                      TL_UPPR      , SH_TOGG      , KC_LGUI      , TT(5)        , LT(2, KC_SPC) ,     LT(3, KC_ENT) , TT(5)        , KC_RGUI      , SH_TOGG      , TL_LOWR                         
),

//        ┌────────┬───┬───────────┬───────────┬───────────┬───────────┐                             ┌───────────┬───────────┬───────────┬───────────┬───┬──────┐
//        │   `    │ 1 │     2     │     3     │     4     │     5     │                             │     =     │     6     │     7     │     8     │ 9 │  0   │
//        ├────────┼───┼───────────┼───────────┼───────────┼───────────┤                             ├───────────┼───────────┼───────────┼───────────┼───┼──────┤
//        │  tab   │ q │     w     │     f     │     p     │     b     │                             │     j     │     l     │     u     │     y     │ ; │  '   │
//        ├────────┼───┼───────────┼───────────┼───────────┼───────────┤                             ├───────────┼───────────┼───────────┼───────────┼───┼──────┤
//        │  esc   │ a │ LCTL_T(r) │ LALT_T(s) │ LSFT_T(t) │ LGUI_T(g) │                             │ RGUI_T(m) │ RSFT_T(n) │ RALT_T(e) │ RCTL_T(i) │ o │ bspc │
//        ├────────┼───┼───────────┼───────────┼───────────┼───────────┼────────────┐   ┌────────────┼───────────┼───────────┼───────────┼───────────┼───┼──────┤
//        │ SH_MON │ x │     c     │     d     │     v     │     z     │    mute    │   │     no     │     /     │     k     │     h     │     ,     │ . │ rsft │
//        └────────┴───┼───────────┼───────────┼───────────┼───────────┼────────────┤   ├────────────┼───────────┼───────────┼───────────┼───────────┼───┴──────┘
//                     │  TL_UPPR  │  SH_TOGG  │   lgui    │   TT(5)   │ LT(2, spc) │   │ LT(3, ent) │   TT(5)   │   rgui    │  SH_TOGG  │  TL_LOWR  │           
//                     └───────────┴───────────┴───────────┴───────────┴────────────┘   └────────────┴───────────┴───────────┴───────────┴───────────┘           
[_COLEMAK] = LAYOUT_sinh_x_58(
      KC_GRV , KC_1 , KC_2         , KC_3         , KC_4         , KC_5         ,                                     KC_EQL       , KC_6         , KC_7         , KC_8         , KC_9    , KC_0   ,
      KC_TAB , KC_Q , KC_W         , KC_F         , KC_P         , KC_B         ,                                     KC_J         , KC_L         , KC_U         , KC_Y         , KC_SCLN , KC_QUOT,
      KC_ESC , KC_A , LCTL_T(KC_R) , LALT_T(KC_S) , LSFT_T(KC_T) , LGUI_T(KC_G) ,                                     RGUI_T(KC_M) , RSFT_T(KC_N) , RALT_T(KC_E) , RCTL_T(KC_I) , KC_O    , KC_BSPC,
      SH_MON , KC_X , KC_C         , KC_D         , KC_V         , KC_Z         , KC_MUTE       ,     XXXXXXX       , KC_SLSH      , KC_K         , KC_H         , KC_COMM      , KC_DOT  , KC_RSFT,
                      TL_UPPR      , SH_TOGG      , KC_LGUI      , TT(5)        , LT(2, KC_SPC) ,     LT(3, KC_ENT) , TT(5)        , KC_RGUI      , SH_TOGG      , TL_LOWR                         
),

//        ┌──────┬────┬─────┬─────┬─────┬─────┐                       ┌─────┬─────┬─────┬─────┬─────┬─────┐
//        │      │ f1 │ f2  │ f3  │ f4  │ f5  │                       │ f6  │ f7  │ f8  │ f9  │ f10 │ f11 │
//        ├──────┼────┼─────┼─────┼─────┼─────┤                       ├─────┼─────┼─────┼─────┼─────┼─────┤
//        │ calc │ 9  │  8  │  7  │  +  │  *  │                       │  [  │  {  │  (  │  $  │  !  │ f12 │
//        ├──────┼────┼─────┼─────┼─────┼─────┤                       ├─────┼─────┼─────┼─────┼─────┼─────┤
//        │ esc  │ 6  │  5  │  4  │  -  │  /  │                       │  ]  │  }  │  )  │  @  │  #  │     │
//        ├──────┼────┼─────┼─────┼─────┼─────┼─────────┐   ┌─────────┼─────┼─────┼─────┼─────┼─────┼─────┤
//        │      │ 3  │  2  │  1  │  0  │  =  │         │   │         │  &  │  |  │  <  │  >  │  \  │     │
//        └──────┴────┼─────┼─────┼─────┼─────┼─────────┤   ├─────────┼─────┼─────┼─────┼─────┼─────┴─────┘
//                    │     │     │     │     │ TL_LOWR │   │ TL_UPPR │     │     │     │     │            
//                    └─────┴─────┴─────┴─────┴─────────┘   └─────────┴─────┴─────┴─────┴─────┘            
[_LOWER] = LAYOUT_sinh_x_58(
      _______ , KC_F1 , KC_F2   , KC_F3   , KC_F4   , KC_F5   ,                         KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11 ,
      KC_CALC , KC_9  , KC_8    , KC_7    , KC_PLUS , KC_ASTR ,                         KC_LBRC , KC_LCBR , KC_LPRN , KC_DLR  , KC_EXLM , KC_F12 ,
      KC_ESC  , KC_6  , KC_5    , KC_4    , KC_MINS , KC_SLSH ,                         KC_RBRC , KC_RCBR , KC_RPRN , KC_AT   , KC_HASH , _______,
      _______ , KC_3  , KC_2    , KC_1    , KC_0    , KC_EQL  , _______ ,     _______ , KC_AMPR , KC_PIPE , KC_LT   , KC_GT   , KC_BSLS , _______,
                        _______ , _______ , _______ , _______ , TL_LOWR ,     TL_UPPR , _______ , _______ , _______ , _______                    
),

//        ┌─────┬──────┬──────┬──────┬──────┬───────┐                       ┌──────────┬───────┬─────────────┬───────┬─────────┬──────┐
//        │     │      │      │      │      │       │                       │          │       │             │       │         │      │
//        ├─────┼──────┼──────┼──────┼──────┼───────┤                       ├──────────┼───────┼─────────────┼───────┼─────────┼──────┤
//        │     │ ins  │ pscr │ app  │  no  │ caps  │                       │   pgup   │ pRVWD │     up      │ nXTWD │ C(bspc) │ bspc │
//        ├─────┼──────┼──────┼──────┼──────┼───────┤                       ├──────────┼───────┼─────────────┼───────┼─────────┼──────┤
//        │     │ lalt │ lctl │ lsft │  no  │  no   │                       │   pgdn   │ left  │    down     │ rght  │ C(del)  │ bspc │
//        ├─────┼──────┼──────┼──────┼──────┼───────┼─────────┐   ┌─────────┼──────────┼───────┼─────────────┼───────┼─────────┼──────┤
//        │     │ C(z) │ C(x) │ C(c) │ C(v) │ again │         │   │         │ www_back │ lSTRT │ www_forward │ lEND  │   no    │      │
//        └─────┴──────┼──────┼──────┼──────┼───────┼─────────┤   ├─────────┼──────────┼───────┼─────────────┼───────┼─────────┴──────┘
//                     │      │      │      │       │ TL_LOWR │   │ TL_UPPR │          │       │             │       │                 
//                     └──────┴──────┴──────┴───────┴─────────┘   └─────────┴──────────┴───────┴─────────────┴───────┘                 
[_RAISE] = LAYOUT_sinh_x_58(
      _______ , _______ , _______ , _______ , _______ , _______ ,                         _______ , _______  , _______ , _______  , _______    , _______,
      _______ , KC_INS  , KC_PSCR , KC_APP  , XXXXXXX , KC_CAPS ,                         KC_PGUP , KC_PRVWD , KC_UP   , KC_NXTWD , C(KC_BSPC) , KC_BSPC,
      _______ , KC_LALT , KC_LCTL , KC_LSFT , XXXXXXX , XXXXXXX ,                         KC_PGDN , KC_LEFT  , KC_DOWN , KC_RGHT  , C(KC_DEL)  , KC_BSPC,
      _______ , C(KC_Z) , C(KC_X) , C(KC_C) , C(KC_V) , KC_AGIN , _______ ,     _______ , KC_WBAK , KC_LSTRT , KC_WFWD , KC_LEND  , XXXXXXX    , _______,
                          _______ , _______ , _______ , _______ , TL_LOWR ,     TL_UPPR , _______ , _______  , _______ , _______                        
),

//        ┌─────────┬─────┬────────┬─────────┬─────┬─────┐               ┌──────┬──────┬──────┬──────┬──────┬──────┐
//        │   no    │ no  │   no   │   no    │ no  │ no  │               │  no  │ vold │ mute │ volu │  no  │  no  │
//        ├─────────┼─────┼────────┼─────────┼─────┼─────┤               ├──────┼──────┼──────┼──────┼──────┼──────┤
//        │ QK_BOOT │ f9  │   f8   │   f7    │ f5  │ f6  │               │ wh_u │ btn1 │ ms_u │ btn2 │ btn3 │ mnxt │
//        ├─────────┼─────┼────────┼─────────┼─────┼─────┤               ├──────┼──────┼──────┼──────┼──────┼──────┤
//        │   no    │ f11 │  f10   │   no    │ f3  │ f4  │               │ wh_d │ ms_l │ ms_d │ ms_r │  no  │ mply │
//        ├─────────┼─────┼────────┼─────────┼─────┼─────┼─────┐   ┌─────┼──────┼──────┼──────┼──────┼──────┼──────┤
//        │   no    │ f12 │ qWERTY │ cOLEMAK │ f1  │ f2  │ no  │   │ no  │  no  │  no  │  no  │  no  │  no  │ mprv │
//        └─────────┴─────┼────────┼─────────┼─────┼─────┼─────┤   ├─────┼──────┼──────┼──────┼──────┼──────┴──────┘
//                        │        │         │     │     │     │   │     │      │      │      │      │              
//                        └────────┴─────────┴─────┴─────┴─────┘   └─────┴──────┴──────┴──────┴──────┘              
[_ADJUST] = LAYOUT_sinh_x_58(
      XXXXXXX , XXXXXXX , XXXXXXX   , XXXXXXX    , XXXXXXX , XXXXXXX ,                         XXXXXXX       , KC_VOLD    , KC_MUTE    , KC_VOLU     , XXXXXXX    , XXXXXXX,
      QK_BOOT , KC_F9   , KC_F8     , KC_F7      , KC_F5   , KC_F6   ,                         KC_MS_WH_UP   , KC_MS_BTN1 , KC_MS_UP   , KC_MS_BTN2  , KC_MS_BTN3 , KC_MNXT,
      XXXXXXX , KC_F11  , KC_F10    , XXXXXXX    , KC_F3   , KC_F4   ,                         KC_MS_WH_DOWN , KC_MS_LEFT , KC_MS_DOWN , KC_MS_RIGHT , XXXXXXX    , KC_MPLY,
      XXXXXXX , KC_F12  , KC_QWERTY , KC_COLEMAK , KC_F1   , KC_F2   , XXXXXXX ,     XXXXXXX , XXXXXXX       , XXXXXXX    , XXXXXXX    , XXXXXXX     , XXXXXXX    , KC_MPRV,
                          _______   , _______    , _______ , _______ , _______ ,     _______ , _______       , _______    , _______    , _______                           
),

//        ┌────┬───────┬──────┬──────┬──────┬─────┐               ┌──────┬──────┬──────┬──────┬──────┬────┐
//        │ no │  no   │  no  │  no  │  no  │ no  │               │  no  │  no  │  no  │  no  │  no  │ no │
//        ├────┼───────┼──────┼──────┼──────┼─────┤               ├──────┼──────┼──────┼──────┼──────┼────┤
//        │ no │ cSF12 │  no  │  no  │  ~   │ no  │               │ wh_u │ btn1 │ ms_u │ btn2 │ btn3 │ no │
//        ├────┼───────┼──────┼──────┼──────┼─────┤               ├──────┼──────┼──────┼──────┼──────┼────┤
//        │ no │  no   │  no  │  no  │  no  │ no  │               │ wh_d │ ms_l │ ms_d │ ms_r │  no  │ no │
//        ├────┼───────┼──────┼──────┼──────┼─────┼─────┐   ┌─────┼──────┼──────┼──────┼──────┼──────┼────┤
//        │ no │ lctl  │ btn1 │ btn2 │ btn3 │ no  │ no  │   │ no  │  no  │  no  │  no  │  no  │ rctl │ no │
//        └────┴───────┼──────┼──────┼──────┼─────┼─────┤   ├─────┼──────┼──────┼──────┼──────┼──────┴────┘
//                     │      │      │      │     │     │   │     │      │      │      │      │            
//                     └──────┴──────┴──────┴─────┴─────┘   └─────┴──────┴──────┴──────┴──────┘            
[_MOUSE] = LAYOUT_sinh_x_58(
      XXXXXXX , XXXXXXX  , XXXXXXX    , XXXXXXX    , XXXXXXX    , XXXXXXX ,                         XXXXXXX       , XXXXXXX    , XXXXXXX    , XXXXXXX     , XXXXXXX    , XXXXXXX,
      XXXXXXX , KC_CSF12 , XXXXXXX    , XXXXXXX    , KC_TILD    , XXXXXXX ,                         KC_MS_WH_UP   , KC_MS_BTN1 , KC_MS_UP   , KC_MS_BTN2  , KC_MS_BTN3 , XXXXXXX,
      XXXXXXX , XXXXXXX  , XXXXXXX    , XXXXXXX    , XXXXXXX    , XXXXXXX ,                         KC_MS_WH_DOWN , KC_MS_LEFT , KC_MS_DOWN , KC_MS_RIGHT , XXXXXXX    , XXXXXXX,
      XXXXXXX , KC_LCTL  , KC_MS_BTN1 , KC_MS_BTN2 , KC_MS_BTN3 , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX       , XXXXXXX    , XXXXXXX    , XXXXXXX     , KC_RCTL    , XXXXXXX,
                           _______    , _______    , _______    , _______ , _______ ,     _______ , _______       , _______    , _______    , _______                           
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
        case KC_CSF12:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_MASK_CS));
                register_code(KC_ESC);
            } else {
                unregister_mods(mod_config(MOD_MASK_CS));
                unregister_code(KC_ESC);
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
