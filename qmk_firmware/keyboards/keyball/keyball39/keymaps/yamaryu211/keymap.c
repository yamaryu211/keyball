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
    KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                            KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     ,
    KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                            KC_H     , KC_J     , KC_K     , KC_L     , KC_MINS  ,
    KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,                            KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  ,
    KC_LCTL  , KC_LGUI  , KC_LALT  ,LSFT_T(KC_LNG2),LT(1,KC_SPC),LT(3,KC_LNG1),KC_BSPC,LT(2,KC_ENT),LSFT_T(KC_LNG2),KC_RALT,KC_RGUI, KC_RSFT
  ),

  [1] = LAYOUT_universal(
    KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_RBRC  ,                            KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   ,
    KC_F5    , KC_EXLM  , S(KC_6)  ,S(KC_INT3), S(KC_8)  ,                           S(KC_INT1), KC_BTN1  , KC_PGUP  , KC_BTN2  , KC_SCLN  ,
    S(KC_EQL),S(KC_LBRC),S(KC_7)   , S(KC_2)  ,S(KC_RBRC),                            KC_LBRC  , KC_DLR   , KC_PGDN  , KC_BTN3  , KC_F11   ,
    KC_INT1  , KC_EQL   , S(KC_3)  , _______  , _______  , _______  ,      TO(2)    , TO(0)    , _______  , KC_RALT  , KC_RGUI  , KC_F12
  ),

  [2] = LAYOUT_universal(
    KC_TAB   , KC_7     , KC_8     , KC_9     , KC_MINS  ,                            KC_NUHS  , _______  , KC_BTN3  , _______  , KC_BSPC  ,
   S(KC_QUOT), KC_4     , KC_5     , KC_6     ,S(KC_SCLN),                            S(KC_9)  , KC_BTN1  , KC_UP    , KC_BTN2  , KC_QUOT  ,
    KC_SLSH  , KC_1     , KC_2     , KC_3     ,S(KC_MINS),                           S(KC_NUHS), KC_LEFT  , KC_DOWN  , KC_RGHT  , _______  ,
    KC_ESC   , KC_0     , KC_DOT   , KC_DEL   , KC_ENT   , KC_BSPC  ,      _______  , _______  , _______  , _______  , _______  , _______
  ),

  [3] = LAYOUT_universal(
    RGB_TOG  , AML_TO   , AML_I50  , AML_D50  , _______  ,                            _______  , _______  , SSNP_HOR , SSNP_VRT , SSNP_FRE ,
    RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , SCRL_DVI ,                            _______  , _______  , _______  , _______  , _______  ,
    RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , SCRL_DVD ,                            CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , KBC_SAVE ,
    QK_BOOT  , KBC_RST  , _______  , _______  , _______  , _______  ,      _______  , _______  , _______  , _______  , KBC_RST  , QK_BOOT
  ),
  // 追加レイヤーの定義
  // TODO: 時間があったらデフォルトキーマップを設定する
  [4] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  ,                            _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  ,                            _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  ,                            _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,      _______ ,  _______  , _______  , _______  , _______  , _______  
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

#ifdef RGBLIGHT_ENABLE
    // レイヤーとLEDを連動させる（レイヤー6のみを点灯させる）
    uint8_t layer = biton32(state);
    switch (layer)
    {
    // case 0:
    //     rgblight_enable_noeeprom();
    //     rgblight_sethsv(0, 0, 10);
    //     break;
    // case 2:
    //     rgblight_enable_noeeprom();
    //     rgblight_sethsv(120, 100, 10);
    //     break;
    // case 3:
    //     rgblight_enable_noeeprom();
    //     rgblight_sethsv(240, 100, 10);
    //     break;
    case 4:
        //rgblight_disable_noeeprom();
        rgblight_sethsv(0, 0, 10);
        break;

    default:
        //rgblight_enable_noeeprom();
        rgblight_sethsv(171,100,10);
    }
#endif

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
  //const uint16_t PROGMEM combo_esc[] = {KC_Q, KC_W, COMBO_END};
  //const uint16_t PROGMEM combo_tab[] = {KC_A, KC_S, COMBO_END};
  //const uint16_t PROGMEM combo_tab_alt[] = {KC_S, KC_D, COMBO_END};
  const uint16_t PROGMEM combo_left_click[] = {KC_J, KC_K, COMBO_END};
  const uint16_t PROGMEM combo_right_click[] = {KC_K, KC_L, COMBO_END};
  const uint16_t PROGMEM combo_middle_click[] = {KC_J, KC_L, COMBO_END};
  // レイヤー・モディファイアキーを含むコンボキーの設定
  //const uint16_t PROGMEM combo_esc2[] = {MT(MOD_LGUI, KC_Q), KC_W, COMBO_END};
  //const uint16_t PROGMEM combo_tab2[] = {MT(MOD_LCTL, KC_A), MT(MOD_LALT, KC_S), COMBO_END};
  //const uint16_t PROGMEM combo_tab2_alt[] = {MT(MOD_LALT, KC_S), LT(2, KC_D), COMBO_END};
  const uint16_t PROGMEM combo_left_click2[] = {LT(1, KC_J), LT(2, KC_K), COMBO_END};
  const uint16_t PROGMEM combo_right_click2[] = {LT(2, KC_K), MT(MOD_LALT, KC_L), COMBO_END};
  const uint16_t PROGMEM combo_middle_click2[] = {LT(1, KC_J), MT(MOD_LALT, KC_L), COMBO_END};
  // 大西配列用のコンボキーの設定
  //const uint16_t PROGMEM combo_esc3[] = {MT(MOD_LGUI, KC_Q), KC_L, COMBO_END};
  //const uint16_t PROGMEM combo_tab3[] = {MT(MOD_LCTL, KC_E), MT(MOD_LALT, KC_I), COMBO_END};
  //const uint16_t PROGMEM combo_tab3_alt[] = {MT(MOD_LALT, KC_I), LT(2, KC_A), COMBO_END};
  const uint16_t PROGMEM combo_left_click3[] = {LT(1, KC_T), LT(2, KC_N), COMBO_END};
  const uint16_t PROGMEM combo_right_click3[] = {LT(2, KC_N), MT(MOD_LALT, KC_S), COMBO_END};
  const uint16_t PROGMEM combo_middle_click3[] = {LT(1, KC_T), MT(MOD_LALT, KC_S), COMBO_END};

  combo_t key_combos[] = {
      //[0] = COMBO(combo_esc, KC_ESC),
      //[1] = COMBO(combo_tab, KC_TAB),
      [0] = COMBO(combo_left_click, KC_BTN1),
      [1] = COMBO(combo_right_click, KC_BTN2),
      [2] = COMBO(combo_middle_click, KC_BTN3),
      //[5] = COMBO(combo_esc2, KC_ESC),
      //[6] = COMBO(combo_tab2, KC_TAB),
      [3] = COMBO(combo_left_click2, KC_BTN1),
      [4] = COMBO(combo_right_click2, KC_BTN2),
      [5] = COMBO(combo_middle_click2, KC_BTN3),
      //[10] = COMBO(combo_esc3, KC_ESC),
      //[11] = COMBO(combo_tab3, KC_TAB),
      [6] = COMBO(combo_left_click3, KC_BTN1),
      [7] = COMBO(combo_right_click3, KC_BTN2),
      [8] = COMBO(combo_middle_click3, KC_BTN3),
      // [15] = COMBO(combo_tab_alt, KC_TAB),
      // [16] = COMBO(combo_tab2_alt, KC_TAB),
      // [17] = COMBO(combo_tab3_alt, KC_TAB),
  };
#endif