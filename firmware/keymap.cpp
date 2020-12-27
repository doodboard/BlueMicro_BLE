/*
Copyright 2018 <Pierre Constantineau>

3-Clause BSD License

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/
#include "keymap.h"
 
std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix =
    {KEYMAP(
        KC_TAB, KC_W, KC_R, KC_U, KC_O, KC_BSPC,
    KC_LCTL, KC_S, KC_F, KC_J, KC_L, KC_QUOT,
    KC_LSFT, KC_X, KC_V, KC_M, KC_DOT, KC_HAEN,
    KC_BSPC, KC_LGUI, LAYER_1, LAYER_2, KC_RBRC, KC_DEL,
    KC_ENT, KC_LALT, KC_SPC, KC_SPC, KC_LBRC, KC_ENT,
    KC_Z, KC_C, KC_B, KC_N, KC_COMM, KC_SLSH,
    KC_A, KC_D, KC_G, KC_H, KC_K, KC_SCLN,
    KC_Q, KC_E, KC_T, KC_Y, KC_I, KC_P)};

void setupKeymap() {

    uint32_t layer1[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP(
    KC_ESC, KC_8, KC_LEFT, KC_U, KC_O, KC_EQL,
    KC_LCTL, KC_5, KC_DOWN, KC_J, KC_L, KC_QUOT,
    KC_LSFT, KC_2, KC_V, KC_M, KC_DOT, KC_LSFT,
    KC_0, KC_DOT, KC_NO, KC_NO, KC_LBRC, KC_RBRC,
    KC_ENT, KC_LALT, KC_SPC, KC_SPC, KC_SPC, KC_ENT,
    KC_1, KC_3, KC_B, KC_N, KC_COMM, KC_SLSH,
    KC_4, KC_6, KC_UP, KC_H, KC_K, KC_SCLN,
    KC_7, KC_9, KC_RIGHT, KC_Y, KC_I, KC_MINS);

    uint32_t layer2[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP(
    KC_GRV, KC_W, KC_R, KC_U, KC_O, UF2_DFU,
    KC_LCTL, KC_S, KC_F, KC_J, KC_L, PRINT_BATTERY,
    KC_LSFT, KC_X, KC_V, KC_M, KC_DOT, KC_LSFT,
    KC_BSPC, KC_LGUI, KC_NO, KC_NO, KC_LBRC, KC_RBRC,
    KC_ENT, KC_LALT, KC_SPC, KC_SPC, KC_SPC, KC_ENT,
    KC_Z, KC_C, KC_B, KC_N, KC_COMM, KC_SLSH,
    KC_A, KC_D, KC_G, KC_H, KC_K, KC_SCLN,
    KC_Q, KC_E, KC_T, KC_Y, KC_I, KC_P);

    /*
     * add the other layers
     */
    for (int row = 0; row < MATRIX_ROWS; ++row)
    {
        for (int col = 0; col < MATRIX_COLS; ++col)
        {
            matrix[row][col].addActivation(_L1, Method::PRESS, layer1[row][col]);
            matrix[row][col].addActivation(_L2, Method::PRESS, layer2[row][col]);
        }
    }

}
