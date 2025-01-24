/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

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

#include QMK_KEYBOARD_H

#include "quantum.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default (VIA)
  [0] = LAYOUT_universal(
    KC_Q           , KC_W         , KC_E           , KC_R            , KC_T           ,                                  KC_Y          , KC_U            , KC_I        , KC_O           , KC_P            ,
    LCTL_T(KC_A)   , LALT_T(KC_S) , LT(2, KC_D)    , LT(1, KC_F)     , KC_G           ,                                  KC_H          , LT(1, KC_J)     , LT(2, KC_K) , LALT_T(KC_L)   , LCTL_T(KC_MINS) ,
    LSFT_T(KC_Z)   , LGUI_T(KC_X) , KC_C           , KC_V            , KC_B           ,                                  KC_N          , KC_M            , KC_COMM     , LGUI_T(KC_DOT) , LSFT_T(KC_SLSH) ,
    LT(1, KC_LNG2) , KC_ESC       , LGUI_T(KC_TAB) , KC_LALT         , LCTL_T(KC_DEL) , LSFT_T(KC_SPC) , LT(1, KC_ENT) , LT(2,KC_BSPC) , _______         , _______     , _______        , LT(3, KC_LNG1)
  ),

  [1] = LAYOUT_universal(
    KC_KP_SLASH , KC_7    , KC_8       , KC_9       , KC_KP_ASTERISK ,                      KC_ESC  , KC_NO   , KC_NO    , KC_NO            , LALT(KC_PSCR) ,
    KC_KP_MINUS , KC_4    , KC_5       , KC_6       , KC_KP_PLUS     ,                      KC_LEFT , KC_DOWN , KC_UP    , LALT_T(KC_RIGHT) , _______       ,
    KC_0        , KC_1    , KC_2       , KC_3       , KC_EQUAL       ,                      KC_HOME , KC_PGDN , KC_PGUP  , KC_END           , _______       ,
    MO(4)       , _______ , S(KC_LGUI) , S(KC_LALT) , S(KC_LCTL)     , _______  , _______ , _______ , _______ , _______  , _______          , MO(4)
  ),

  [2] = LAYOUT_universal(
    KC_QUOT , S(KC_QUOT) , S(KC_1)    , S(KC_SLSH) , S(KC_GRAVE) ,                     KC_BSLS , S(KC_LBRC) , S(KC_RBRC) , KC_NO      , S(KC_5)  ,
    S(KC_2) , KC_SCLN    , S(KC_4)    , S(KC_COMM) , S(KC_DOT)   ,                     S(KC_3) , S(KC_9)    , S(KC_0)    , S(KC_BSLS) , KC_EQUAL ,
    KC_NO   , S(KC_8)    , S(KC_SCLN) , S(KC_6)    , KC_GRAVE    ,                     S(KC_7) , KC_LBRC    , KC_RBRC    , KC_NO      , KC_SLSH  ,
    _______ , _______    , _______    , _______    , _______     , _______ , _______ , _______ , _______    , _______    , _______    , _______
  ),

  [3] = LAYOUT_universal(
    KC_F10  , KC_F7       , KC_F8   , KC_F9   , KC_NO   ,                     LGUI(KC_TAB) , LCTL(KC_PGUP)   , LCTL(KC_PGDN)  , KC_NO      , LSG(KC_S) ,
    KC_F11  , KC_F4       , KC_F5   , KC_F6   , KC_NO   ,                     LCTL(KC_W)   , LCTL(S(KC_TAB)) , LCTL(KC_TAB)   , LCTL(KC_T) , KC_NO     ,
    KC_F12  , LCTL(KC_F1) , KC_F2   , KC_F3   , KC_NO   ,                     KC_NO        , LALT(KC_LEFT)   , LALT(KC_RIGHT) , KC_NO      , KC_NO     ,
    _______ , _______     , _______ , _______ , _______ , _______ , _______ , _______      , _______         , _______        , _______    , _______
  ),
  // 追加レイヤーの定義
  [4] = LAYOUT_universal(
    KC_NO    , KC_NO    , KC_NO   , DT_PRNT , SSNP_VRT ,                     KC_BRIU , KC_BRID , KC_MUTE , KC_VOLD , KC_VOLU ,
    CPI_I100 , SCRL_DVI , AML_I50 , DT_UP   , SSNP_HOR ,                     KC_NO   , KC_NO   , KC_NO   , KC_NO   , _______ ,
    CPI_D100 , SCRL_DVD , AML_D50 , DT_DOWN , SSNP_FRE ,                     KC_NO   , KC_NO   , KC_NO   , KC_NO   , _______ ,
    _______  , _______  , _______ , _______ , _______  , _______ , _______ , _______ , _______ , _______ , _______ , _______  
  ),
  // [5] = LAYOUT_universal(
  //   _______  , _______  , _______  , _______  , _______  ,                            _______  , _______  , _______  , _______  , _______  ,
  //   _______  , _______  , _______  , _______  , _______  ,                            _______  , _______  , _______  , _______  , _______  ,
  //   _______  , _______  , _______  , _______  , _______  ,                            _______  , _______  , _______  , _______  , _______  ,
  //   _______  , _______  , _______  , _______  , _______  , _______  ,      _______ ,  _______  , _______  , _______  , _______  , _______  
  // ),
};
// clang-format on

// レイヤーによるスクロール設定
layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    // レイヤーが3の時にスクロールモード（自由）を有効にする
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
    keyball_handle_auto_mouse_layer_change(state);
#endif

// #ifdef RGBLIGHT_ENABLE
//     // レイヤーとLEDを連動させる（レイヤー6のみを点灯させる）
//     uint8_t layer = biton32(state);
//     switch (layer)
//     {
//     // case 0:
//     //     rgblight_enable_noeeprom();
//     //     rgblight_sethsv(0, 0, 10);
//     //     break;
//     // case 2:
//     //     rgblight_enable_noeeprom();
//     //     rgblight_sethsv(120, 100, 10);
//     //     break;
//     // case 3:
//     //     rgblight_enable_noeeprom();
//     //     rgblight_sethsv(240, 100, 10);
//     //     break;
//     case 4:
//         rgblight_disable_noeeprom();
//         break;

//     default:
//         rgblight_enable_noeeprom();
//         rgblight_sethsv(171,100,10);
//     }
// #endif

    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif

// // コンボキーの設定
#ifdef COMBO_ENABLE
  const uint16_t PROGMEM combo_esc[] = {KC_Q, KC_W, COMBO_END};
  const uint16_t PROGMEM combo_tab[] = {KC_A, KC_S, COMBO_END};
  const uint16_t PROGMEM combo_tab_alt[] = {KC_S, KC_D, COMBO_END};
  const uint16_t PROGMEM combo_left_click[] = {KC_J, KC_K, COMBO_END};
  const uint16_t PROGMEM combo_right_click[] = {KC_K, KC_L, COMBO_END};
  const uint16_t PROGMEM combo_middle_click[] = {KC_J, KC_L, COMBO_END};
  // レイヤー・モディファイアキーを含むコンボキーの設定
  const uint16_t PROGMEM combo_esc2[] = {MT(MOD_LGUI, KC_Q), KC_W, COMBO_END};
  const uint16_t PROGMEM combo_tab2[] = {MT(MOD_LCTL, KC_A), MT(MOD_LALT, KC_S), COMBO_END};
  const uint16_t PROGMEM combo_tab2_alt[] = {MT(MOD_LALT, KC_S), LT(2, KC_D), COMBO_END};
  const uint16_t PROGMEM combo_left_click2[] = {LT(1, KC_J), LT(2, KC_K), COMBO_END};
  const uint16_t PROGMEM combo_right_click2[] = {LT(2, KC_K), MT(MOD_LALT, KC_L), COMBO_END};
  const uint16_t PROGMEM combo_middle_click2[] = {LT(1, KC_J), MT(MOD_LALT, KC_L), COMBO_END};
  // 大西配列用のコンボキーの設定
  const uint16_t PROGMEM combo_esc3[] = {KC_Q, KC_L, COMBO_END}; 
  const uint16_t PROGMEM combo_tab3[] = {MT(MOD_LCTL, KC_E), MT(MOD_LALT, KC_I), COMBO_END};
  const uint16_t PROGMEM combo_tab3_alt[] = {MT(MOD_LALT, KC_I), LT(2, KC_A), COMBO_END};
  const uint16_t PROGMEM combo_left_click3[] = {LT(1, KC_T), LT(2, KC_N), COMBO_END};
  const uint16_t PROGMEM combo_right_click3[] = {LT(2, KC_N), MT(MOD_LALT, KC_S), COMBO_END};
  const uint16_t PROGMEM combo_middle_click3[] = {LT(1, KC_T), MT(MOD_LALT, KC_S), COMBO_END};

  combo_t key_combos[] = {
      COMBO(combo_esc, KC_ESC),
      //[1] = COMBO(combo_tab, KC_TAB),
      // COMBO(combo_left_click, KC_BTN1),
      //[2] = COMBO(combo_right_click, KC_BTN2),
      // [3] = COMBO(combo_middle_click, KC_BTN3),
      // [4] = COMBO(combo_esc2, KC_ESC),
      //[6] = COMBO(combo_tab2, KC_TAB),
      COMBO(combo_left_click2, KC_BTN1),
      COMBO(combo_right_click2, KC_BTN2),
      COMBO(combo_middle_click2, KC_BTN3),
      COMBO(combo_esc3, KC_ESC),
      //[11] = COMBO(combo_tab3, KC_TAB),
      COMBO(combo_left_click3, KC_BTN1),
      COMBO(combo_right_click3, KC_BTN2),
      COMBO(combo_middle_click3, KC_BTN3),
      // [12] = COMBO(combo_tab_alt, KC_TAB),
      COMBO(combo_tab2_alt, KC_TAB),
      COMBO(combo_tab3_alt, KC_TAB),
  };
#endif