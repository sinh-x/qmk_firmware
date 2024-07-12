// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum  ofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _COLEMAK,
    _LOWER,
    _RAISE,
    _ADJUST,
    _MOUSE,
    _LOWER_rev
};

enum custom_keycodes {
    KC_QWERTY = QK_USER,
    KC_COLEMAK,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_CSF12,
    KC_ALTF1,
    KC_WEB1,
    KC_WEB2,
    KC_CGF1,
    KC_CGF2,
    KC_CGF3,
    KC_CGF4,
    KC_CGF5,
    KC_CGF6,
    KC_CGF11,
    KC_CGF12,
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
//        ┌────────┬───┬───────────┬───────────┬───────────┬────────────┐                   ┌────────────┬───────────┬───────────┬───────────┬───┬──────┐
//        │   `    │ 1 │     2     │     3     │     4     │     5      │                   │     6      │     7     │     8     │     9     │ 0 │  =   │
//        ├────────┼───┼───────────┼───────────┼───────────┼────────────┤                   ├────────────┼───────────┼───────────┼───────────┼───┼──────┤
//        │  tab   │ q │     w     │     f     │     p     │     b      │                   │     j      │     l     │     u     │     y     │ ; │  '   │
//        ├────────┼───┼───────────┼───────────┼───────────┼────────────┤                   ├────────────┼───────────┼───────────┼───────────┼───┼──────┤
//        │  esc   │ a │ LCTL_T(r) │ LALT_T(s) │ LSFT_T(t) │ LGUI_T(g)  │                   │ RGUI_T(m)  │ RSFT_T(n) │ RALT_T(e) │ RCTL_T(i) │ o │ bspc │
//        ├────────┼───┼───────────┼───────────┼───────────┼────────────┼───────┐   ┌───────┼────────────┼───────────┼───────────┼───────────┼───┼──────┤
//        │ SH_MON │ x │     c     │     d     │     v     │     z      │ mute  │   │  no   │     /      │     k     │     h     │     ,     │ . │ rsft │
//        └────────┴───┼───────────┼───────────┼───────────┼────────────┼───────┤   ├───────┼────────────┼───────────┼───────────┼───────────┼───┴──────┘
//                     │  TL_UPPR  │    no     │   TT(5)   │ LT(4, spc) │ MO(1) │   │ MO(2) │ LT(4, ent) │   TT(5)   │  SH_TOGG  │  TL_LOWR  │
//                     └───────────┴───────────┴───────────┴────────────┴───────┘   └───────┴────────────┴───────────┴───────────┴───────────┘
[_COLEMAK] = LAYOUT_sinh_x_58(
      KC_GRV , KC_1 , KC_2         , KC_3         , KC_4         , KC_5          ,                         KC_6          , KC_7         , KC_8         , KC_9         , KC_0    , KC_EQL ,
      KC_TAB , KC_Q , KC_W         , KC_F         , KC_P         , KC_B          ,                         KC_J          , KC_L         , KC_U         , KC_Y         , KC_SCLN , KC_QUOT,
      KC_ESC , KC_A , LCTL_T(KC_R) , LALT_T(KC_S) , LSFT_T(KC_T) , LGUI_T(KC_G)  ,                         RGUI_T(KC_M)  , RSFT_T(KC_N) , RALT_T(KC_E) , RCTL_T(KC_I) , KC_O    , KC_BSPC,
      SH_MON , KC_X , KC_C         , KC_D         , KC_V         , KC_Z          , KC_MUTE ,     XXXXXXX , KC_SLSH       , KC_K         , KC_H         , KC_COMM      , KC_DOT  , KC_RSFT,
                      TL_UPPR      , XXXXXXX      , TT(5)        , LT(4, KC_SPC) , MO(1)   ,     MO(2)   , LT(4, KC_ENT) , TT(5)        , SH_TOGG      , TL_LOWR
),

//        ┌──────┬────┬───────────┬───────────┬───────────┬───────────┐                       ┌───────────┬───────────┬───────────┬───────────┬─────┬─────┐
//        │      │ f1 │    f2     │    f3     │    f4     │    f5     │                       │    f6     │    f7     │    f8     │    f9     │ f10 │ f11 │
//        ├──────┼────┼───────────┼───────────┼───────────┼───────────┤                       ├───────────┼───────────┼───────────┼───────────┼─────┼─────┤
//        │ calc │ ~  │   kp_+    │     -     │   kp_*    │     /     │                       │     $     │     <     │     |     │     >     │  `  │ f12 │
//        ├──────┼────┼───────────┼───────────┼───────────┼───────────┤                       ├───────────┼───────────┼───────────┼───────────┼─────┼─────┤
//        │ esc  │ 1  │ LCTL_T(2) │ LALT_T(3) │ LSFT_T(4) │ LGUI_T(5) │                       │ RGUI_T(6) │ RSFT_T(7) │ RALT_T(8) │ RCTL_T(9) │  0  │     │
//        ├──────┼────┼───────────┼───────────┼───────────┼───────────┼─────────┐   ┌─────────┼───────────┼───────────┼───────────┼───────────┼─────┼─────┤
//        │      │ _  │     [     │     {     │     (     │     =     │         │   │         │     \     │     )     │     }     │     ]     │  @  │     │
//        └──────┴────┼───────────┼───────────┼───────────┼───────────┼─────────┤   ├─────────┼───────────┼───────────┼───────────┼───────────┼─────┴─────┘
//                    │           │           │           │           │ TL_LOWR │   │ TL_UPPR │           │           │           │           │
//                    └───────────┴───────────┴───────────┴───────────┴─────────┘   └─────────┴───────────┴───────────┴───────────┴───────────┘
[_LOWER] = LAYOUT_sinh_x_58(
      _______ , KC_F1   , KC_F2        , KC_F3        , KC_F4        , KC_F5        ,                         KC_F6        , KC_F7        , KC_F8        , KC_F9        , KC_F10 , KC_F11 ,
      KC_CALC , KC_TILD , KC_PPLS      , KC_MINS      , KC_PAST      , KC_SLSH      ,                         KC_DLR       , KC_LT        , KC_PIPE      , KC_GT        , KC_GRV , KC_F12 ,
      KC_ESC  , KC_1    , LCTL_T(KC_2) , LALT_T(KC_3) , LSFT_T(KC_4) , LGUI_T(KC_5) ,                         RGUI_T(KC_6) , RSFT_T(KC_7) , RALT_T(KC_8) , RCTL_T(KC_9) , KC_0   , _______,
      _______ , KC_UNDS , KC_LBRC      , KC_LCBR      , KC_LPRN      , KC_EQL       , _______ ,     _______ , KC_BSLS      , KC_RPRN      , KC_RCBR      , KC_RBRC      , KC_AT  , _______,
                          _______      , _______      , _______      , _______      , TL_LOWR ,     TL_UPPR , _______      , _______      , _______      , _______
),

//        ┌─────┬──────┬──────┬──────┬──────┬───────┐                       ┌───────┬───────┬──────────┬──────────────┬─────┬─────────┐
//        │     │      │      │      │      │       │                       │       │       │          │              │     │         │
//        ├─────┼──────┼──────┼──────┼──────┼───────┤                       ├───────┼───────┼──────────┼──────────────┼─────┼─────────┤
//        │     │ ins  │ pscr │ app  │  no  │ caps  │                       │ pgup  │ pRVWD │    up    │    nXTWD     │ no  │   no    │
//        ├─────┼──────┼──────┼──────┼──────┼───────┤                       ├───────┼───────┼──────────┼──────────────┼─────┼─────────┤
//        │     │  no  │ lctl │ lalt │ lsft │ lgui  │                       │ pgdn  │ left  │   down   │ RCTL_T(rght) │ no  │ C(bspc) │
//        ├─────┼──────┼──────┼──────┼──────┼───────┼─────────┐   ┌─────────┼───────┼───────┼──────────┼──────────────┼─────┼─────────┤
//        │     │ C(z) │ C(x) │ C(c) │ C(v) │ again │         │   │         │ lSTRT │ lEND  │ www_back │ www_forward  │ no  │         │
//        └─────┴──────┼──────┼──────┼──────┼───────┼─────────┤   ├─────────┼───────┼───────┼──────────┼──────────────┼─────┴─────────┘
//                     │      │      │      │       │ TL_LOWR │   │ TL_UPPR │       │       │          │              │
//                     └──────┴──────┴──────┴───────┴─────────┘   └─────────┴───────┴───────┴──────────┴──────────────┘
[_RAISE] = LAYOUT_sinh_x_58(
      _______ , _______ , _______ , _______ , _______ , _______ ,                         _______  , _______  , _______ , _______         , _______ , _______   ,
      _______ , KC_INS  , KC_PSCR , KC_APP  , XXXXXXX , KC_CAPS ,                         KC_PGUP  , KC_PRVWD , KC_UP   , KC_NXTWD        , XXXXXXX , XXXXXXX   ,
      _______ , XXXXXXX , KC_LCTL , KC_LALT , KC_LSFT , KC_LGUI ,                         KC_PGDN  , KC_LEFT  , KC_DOWN , RCTL_T(KC_RGHT) , XXXXXXX , C(KC_BSPC),
      _______ , C(KC_Z) , C(KC_X) , C(KC_C) , C(KC_V) , KC_AGIN , _______ ,     _______ , KC_LSTRT , KC_LEND  , KC_WBAK , KC_WFWD         , XXXXXXX , _______   ,
                          _______ , _______ , _______ , _______ , TL_LOWR ,     TL_UPPR , _______  , _______  , _______ , _______
),

//        ┌─────────┬────┬──────┬──────┬──────┬─────┐               ┌─────┬──────┬──────┬──────┬─────┬─────┐
//        │ QK_BOOT │ no │  no  │  no  │  no  │ no  │               │ no  │  no  │  no  │  no  │ no  │ no  │
//        ├─────────┼────┼──────┼──────┼──────┼─────┤               ├─────┼──────┼──────┼──────┼─────┼─────┤
//        │   f1    │ f2 │  f3  │  f4  │  f5  │ f6  │               │ f7  │  f8  │  f9  │ f10  │ f11 │ f12 │
//        ├─────────┼────┼──────┼──────┼──────┼─────┤               ├─────┼──────┼──────┼──────┼─────┼─────┤
//        │   no    │ 1  │  2   │  3   │  4   │  5  │               │  6  │  7   │  8   │  9   │  0  │ no  │
//        ├─────────┼────┼──────┼──────┼──────┼─────┼─────┐   ┌─────┼─────┼──────┼──────┼──────┼─────┼─────┤
//        │   no    │ no │ vold │ mute │ volu │ no  │ no  │   │ no  │ no  │ mprv │ mply │ mnxt │ no  │ no  │
//        └─────────┴────┼──────┼──────┼──────┼─────┼─────┤   ├─────┼─────┼──────┼──────┼──────┼─────┴─────┘
//                       │      │      │      │     │     │   │     │     │      │      │      │
//                       └──────┴──────┴──────┴─────┴─────┘   └─────┴─────┴──────┴──────┴──────┘
[_ADJUST] = LAYOUT_sinh_x_58(
      QK_BOOT , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                         XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
      KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   ,                         KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12 ,
      XXXXXXX , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    ,                         KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , XXXXXXX,
      XXXXXXX , XXXXXXX , KC_VOLD , KC_MUTE , KC_VOLU , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX , KC_MPRV , KC_MPLY , KC_MNXT , XXXXXXX , XXXXXXX,
                          _______ , _______ , _______ , _______ , _______ ,     _______ , _______ , _______ , _______ , _______
),

//        ┌──────┬───────┬──────┬──────┬──────┬───────┐               ┌──────┬──────┬──────┬──────┬───────┬───────┐
//        │  no  │  no   │  no  │  no  │  no  │  no   │               │  no  │  no  │  no  │  no  │  no   │  no   │
//        ├──────┼───────┼──────┼──────┼──────┼───────┤               ├──────┼──────┼──────┼──────┼───────┼───────┤
//        │  no  │ cSF12 │ wEB1 │ wEB2 │  no  │ aLTF1 │               │ wh_u │ btn1 │ ms_u │ btn2 │ btn3  │  no   │
//        ├──────┼───────┼──────┼──────┼──────┼───────┤               ├──────┼──────┼──────┼──────┼───────┼───────┤
//        │ cGF1 │ cGF2  │ cGF3 │ cGF4 │ cGF5 │ cGF6  │               │ wh_d │ ms_l │ ms_d │ ms_r │ cGF11 │ cGF12 │
//        ├──────┼───────┼──────┼──────┼──────┼───────┼─────┐   ┌─────┼──────┼──────┼──────┼──────┼───────┼───────┤
//        │  no  │ lctl  │ btn1 │ btn2 │ btn3 │  no   │ no  │   │ no  │  no  │  no  │  no  │  no  │ rctl  │  no   │
//        └──────┴───────┼──────┼──────┼──────┼───────┼─────┤   ├─────┼──────┼──────┼──────┼──────┼───────┴───────┘
//                       │      │      │      │       │     │   │     │      │      │      │      │
//                       └──────┴──────┴──────┴───────┴─────┘   └─────┴──────┴──────┴──────┴──────┘
[_MOUSE] = LAYOUT_sinh_x_58(
      XXXXXXX , XXXXXXX  , XXXXXXX    , XXXXXXX    , XXXXXXX    , XXXXXXX  ,                         XXXXXXX       , XXXXXXX    , XXXXXXX    , XXXXXXX     , XXXXXXX    , XXXXXXX ,
      XXXXXXX , KC_CSF12 , KC_WEB1    , KC_WEB2    , XXXXXXX    , KC_ALTF1 ,                         KC_MS_WH_UP   , KC_MS_BTN1 , KC_MS_UP   , KC_MS_BTN2  , KC_MS_BTN3 , XXXXXXX ,
      KC_CGF1 , KC_CGF2  , KC_CGF3    , KC_CGF4    , KC_CGF5    , KC_CGF6  ,                         KC_MS_WH_DOWN , KC_MS_LEFT , KC_MS_DOWN , KC_MS_RIGHT , KC_CGF11   , KC_CGF12,
      XXXXXXX , KC_LCTL  , KC_MS_BTN1 , KC_MS_BTN2 , KC_MS_BTN3 , XXXXXXX  , XXXXXXX ,     XXXXXXX , XXXXXXX       , XXXXXXX    , XXXXXXX    , XXXXXXX     , KC_RCTL    , XXXXXXX ,
                           _______    , _______    , _______    , _______  , _______ ,     _______ , _______       , _______    , _______    , _______
),

//        ┌──────┬────┬───────────┬───────────┬───────────┬───────────┐                       ┌───────────┬───────────┬───────────┬───────────┬─────┬─────┐
//        │      │ f1 │    f2     │    f3     │    f4     │    f5     │                       │    f6     │    f7     │    f8     │    f9     │ f10 │ f11 │
//        ├──────┼────┼───────────┼───────────┼───────────┼───────────┤                       ├───────────┼───────────┼───────────┼───────────┼─────┼─────┤
//        │ calc │ !  │     $     │     (     │     {     │     [     │                       │     *     │     7     │     8     │     9     │  +  │ f12 │
//        ├──────┼────┼───────────┼───────────┼───────────┼───────────┤                       ├───────────┼───────────┼───────────┼───────────┼─────┼─────┤
//        │ esc  │ #  │ LCTL_T(@) │ LALT_T()) │ LSFT_T(}) │ LGUI_T(]) │                       │ RGUI_T(/) │ RSFT_T(4) │ RALT_T(5) │ RCTL_T(6) │  -  │     │
//        ├──────┼────┼───────────┼───────────┼───────────┼───────────┼─────────┐   ┌─────────┼───────────┼───────────┼───────────┼───────────┼─────┼─────┤
//        │      │ \  │     >     │     <     │     |     │     &     │         │   │         │     =     │     1     │     2     │     3     │  0  │     │
//        └──────┴────┼───────────┼───────────┼───────────┼───────────┼─────────┤   ├─────────┼───────────┼───────────┼───────────┼───────────┼─────┴─────┘
//                    │           │           │           │           │ TL_LOWR │   │ TL_UPPR │           │           │           │           │
//                    └───────────┴───────────┴───────────┴───────────┴─────────┘   └─────────┴───────────┴───────────┴───────────┴───────────┘
[_LOWER_rev] = LAYOUT_sinh_x_58(
      _______ , KC_F1   , KC_F2         , KC_F3           , KC_F4           , KC_F5           ,                         KC_F6           , KC_F7        , KC_F8        , KC_F9        , KC_F10  , KC_F11 ,
      KC_CALC , KC_EXLM , KC_DLR        , KC_LPRN         , KC_LCBR         , KC_LBRC         ,                         KC_ASTR         , KC_7         , KC_8         , KC_9         , KC_PLUS , KC_F12 ,
      KC_ESC  , KC_HASH , LCTL_T(KC_AT) , LALT_T(KC_RPRN) , LSFT_T(KC_RCBR) , LGUI_T(KC_RBRC) ,                         RGUI_T(KC_SLSH) , RSFT_T(KC_4) , RALT_T(KC_5) , RCTL_T(KC_6) , KC_MINS , _______,
      _______ , KC_BSLS , KC_GT         , KC_LT           , KC_PIPE         , KC_AMPR         , _______ ,     _______ , KC_EQL          , KC_1         , KC_2         , KC_3         , KC_0    , _______,
                          _______       , _______         , _______         , _______         , TL_LOWR ,     TL_UPPR , _______         , _______      , _______      , _______
)
};

void handle_key_with_mod(uint16_t keycode, uint8_t mod, keyrecord_t *record) {
    if (record->event.pressed) {
        register_mods(mod);
        register_code(keycode);
    } else {
        unregister_mods(mod);
        unregister_code(keycode);
    }
}
uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Store the current modifier state in the variable for later reference
    mod_state = get_mods();

    switch (keycode) {
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
       // Define WEB1 = Shift_GUI_W - mapped to bspwm-sxhkc open chrome profile 1
        case KC_WEB1:
            handle_key_with_mod(KC_W, MOD_MASK_SG, record);
            break;
        // Define WEB2 = Ctrl_Shift_GUI_W - mapped to bspwm-sxhkc open chrome profile 2
        case KC_WEB2:
            handle_key_with_mod(KC_W, MOD_MASK_CSG, record);
            break;
        // Define Ctrl_Shift_F12 - map to open floating terminal in bspmw sxhkc
        case KC_CSF12:
            handle_key_with_mod(KC_F12, MOD_MASK_CS, record);
            break;
        // Define Super_Shift_F__ - map to open floating terminal in bspmw sxhkc
        case KC_CGF1:
            handle_key_with_mod(KC_F1, MOD_MASK_CG, record);
            break;
        case KC_CGF2:
            handle_key_with_mod(KC_F2, MOD_MASK_CG, record);
            break;
        case KC_CGF3:
            handle_key_with_mod(KC_F3, MOD_MASK_CG, record);
            break;
        case KC_CGF4:
            handle_key_with_mod(KC_F4, MOD_MASK_CG, record);
            break;
        case KC_CGF5:
            handle_key_with_mod(KC_F5, MOD_MASK_CG, record);
            break;
        case KC_CGF6:
            handle_key_with_mod(KC_F6, MOD_MASK_CG, record);
            break;
        case KC_CGF11:
            handle_key_with_mod(KC_F11, MOD_MASK_CG, record);
            break;
        case KC_CGF12:
            handle_key_with_mod(KC_F12, MOD_MASK_CG, record);
            break;
        // Define Alt_F11 - map to open application launcher in bspmw
        case KC_ALTF1:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_MASK_ALT));
                register_code(KC_F1);
            } else {
                unregister_mods(mod_config(MOD_MASK_ALT));
                unregister_code(KC_F1);
            }
            break;
        // Dfefin Del when press Shift + Backspace
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
