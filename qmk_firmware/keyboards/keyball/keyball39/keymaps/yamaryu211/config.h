/*
This is the c configuration file for the keymap

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

#pragma once

#ifdef RGBLIGHT_ENABLE
//#    define RGBLIGHT_EFFECT_BREATHING
//#    define RGBLIGHT_EFFECT_RAINBOW_MOOD
//#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
//#    define RGBLIGHT_EFFECT_SNAKE
//#    define RGBLIGHT_EFFECT_KNIGHT
//#    define RGBLIGHT_EFFECT_CHRISTMAS
//#    define RGBLIGHT_EFFECT_STATIC_GRADIENT
//#    define RGBLIGHT_EFFECT_RGB_TEST
//#    define RGBLIGHT_EFFECT_ALTERNATING
//#    define RGBLIGHT_EFFECT_TWINKLE
#endif

#define TAP_CODE_DELAY 5

// OLED自動消灯時間を所定60秒から10秒に変更
#define OLED_TIMEOUT 10000 // ミリ秒

// レイヤ―数追加
#define DYNAMIC_KEYMAP_LAYER_COUNT 5

// マウス、スクロール速度デフォルト値の設定
#define KEYBALL_CPI_DEFAULT 900 // マウス速度 (default: 500)
#define KEYBALL_SCROLL_DIV_DEFAULT 5 // スクロール速度 (default: 4)

// AMLはデフォルトで無効にする
//#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
//#define AUTO_MOUSE_DEFAULT_LAYER 5 // マウスレイヤーをレイヤー6に設定
//#define AUTO_MOUSE_LAYER_KEEP_TIME 30000 // マウスレイヤーを維持する時間を30秒に設定

#define SPLIT_LAYER_STATE_ENABLE        // レイヤー情報をサブキーボードに送信する
#define RGBLIGHT_DEFAULT_HUE 142          // バックライトの初期値
#define RGBLIGHT_DEFAULT_SAT 100          // 〃
#define RGBLIGHT_DEFAULT_VAL 30         // 〃

// USB接続時のタイムアウト時間を2.5秒に設定
# define SPLIT_USB_TIMEOUT 2500 // ミリ秒