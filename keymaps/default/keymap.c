/* Copyright (C) 2023 jonylee@hfd
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "lib/lib8tion/lib8tion.h"
#include "rgb_matrix.h"

enum __layers {
    WIN_B,
    WIN_W,
    WIN_FN,
    MAC_B,
    MAC_W,
    MAC_FN
};

enum custom_keycodes {
    PARENS = SAFE_RANGE
};

const uint16_t PROGMEM both_shifts_combo[] = {TD(0), TD(1), COMBO_END};

combo_t key_combos[] = {
    COMBO(both_shifts_combo, PARENS)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        if (keycode == PARENS) {
            SEND_STRING("()" SS_TAP(X_LEFT));
            return false;
        }
    }
    return true;
}

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [WIN_B] = LAYOUT_all( /* Base */
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12,   KC_DEL,           KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,KC_EQL,   KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,KC_RBRC,  KC_BSLS,          KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,KC_NUHS,  KC_ENT,           KC_PGDN,
        TD(0),   KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          TD(1),   KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             QK_LEAD, MO(WIN_FN),KC_RCTL,        KC_LEFT, KC_DOWN, KC_RGHT),

    [WIN_W] = LAYOUT_all( /* Base */
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, KC_W,    _______,
        _______, _______, _______,                   _______,                            _______,MO(WIN_FN),_______,          KC_A,    KC_S,    KC_D),

    [WIN_FN] = LAYOUT_all( /* WASD/↑←↓→ */
        _______, KC_MYCM, KC_MAIL, KC_WSCH, KC_WHOM, KC_MSEL, KC_MPLY, KC_MPRV, KC_MNXT, _______, _______, _______, _______, _______,           RM_NEXT,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RM_SPDD, RM_SPDU, _______,           _______,
        _______, _______,TG(WIN_W),_______, _______, _______, _______, _______, KC_INS,  PDF(MAC_B),KC_PSCR,_______, _______, RM_NEXT,           _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, RM_TOGG, _______, _______, RM_NEXT, RM_HUEU,           _______,
        _______, _______, _______, _______, KC_CALC, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______,          _______,  RM_VALU, _______,
        _______, GU_TOGG, _______,                   _______,                            _______, _______, _______,          RM_SATD,  RM_VALD, RM_SATU),

    [MAC_B] = LAYOUT_all( /* Base */
        KC_ESC,  KC_BRID, KC_BRIU, KC_MCTL, KC_LPAD, KC_F5,   KC_F6,   KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD,KC_VOLU,  KC_DEL,           KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,KC_EQL,   KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,KC_RBRC,  KC_BSLS,          KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,KC_NUHS,  KC_ENT,           KC_PGDN,
        TD(0),   KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          TD(1),   KC_UP,   KC_END,
        KC_LCTL, KC_LALT, KC_LGUI,                   KC_SPC,                             QK_LEAD, MO(MAC_FN),KC_RCTL,        KC_LEFT, KC_DOWN, KC_RGHT),

    [MAC_W] = LAYOUT_all( /* WASD/↑←↓→ */
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, KC_W,    _______,
        _______, _______, _______,                   _______,                            _______, MO(MAC_FN), _______,          KC_A,    KC_S,    KC_D),

    [MAC_FN] = LAYOUT_all( /* FN */
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,  KC_F9,    KC_F10,  KC_F11,  KC_F12,  KC_DEL,            RM_NEXT,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RM_SPDD, RM_SPDU, _______,           _______,
        _______, _______,TG(MAC_W),_______, _______, _______, _______, _______, KC_INS,  PDF(WIN_B),KC_PSCR,_______, _______, RM_NEXT,           _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, RM_TOGG, _______, _______, RM_NEXT, RM_HUEU,           _______,
        _______, _______, _______, _______, KC_CALC, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______,          _______,  RM_VALU, _______,
        _______, _______, _______,                   _______,                            _______, _______, _______,          RM_SATD,  RM_VALD, RM_SATU)
};


// clang-format off
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [WIN_B] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [WIN_W] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [WIN_FN] = { ENCODER_CCW_CW(RM_VALU, RM_VALD) },
    [MAC_B] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [MAC_W] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [MAC_FN] = { ENCODER_CCW_CW(RM_VALU, RM_VALD) }
};
#endif

void leader_end_user(void) {
    if (leader_sequence_two_keys(KC_G, KC_A)) {
        // git add .
        SEND_STRING("git add ." SS_TAP(X_ENTER));
    }
    if (leader_sequence_two_keys(KC_G, KC_C)) {
        // git commit -m "" and move cursor inside quotes
        SEND_STRING("git commit -m \"\"" SS_TAP(X_LEFT));
    }
    if (leader_sequence_two_keys(KC_G, KC_P)) {
        // git push
        SEND_STRING("git push" SS_TAP(X_ENTER));
    }
}

// --- CUSTOM RGB OVERRIDES ---
// We hook into standard QMK effect IDs so that VIA shows them in the menu correctly!
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t effect = rgb_matrix_get_mode();
    
    if (effect == RGB_MATRIX_PIXEL_FLOW || 
        effect == RGB_MATRIX_JELLYBEAN_RAINDROPS || 
        effect == RGB_MATRIX_SOLID_SPLASH || 
        effect == RGB_MATRIX_MULTISPLASH ||
        effect == RGB_MATRIX_SOLID_REACTIVE_WIDE) {
        
        uint32_t timer = timer_read32();
        uint8_t speed = rgb_matrix_config.speed;
        
        // Clear background for reactive effects to prevent standard animation bleed
        for (uint8_t i = led_min; i < led_max; i++) {
            rgb_matrix_set_color(i, 0, 0, 0);
        }

        if (effect == RGB_MATRIX_PIXEL_FLOW) { 
            // OVERWRITTEN WITH: Aurora Borealis
            for (uint8_t i = led_min; i < led_max; i++) {
                uint8_t time_offset = (timer / 20) - g_led_config.point[i].x;
                // Gently shift hue between Green (80) and Purple (190)
                uint8_t hue = 80 + scale8(sin8(time_offset), 110);
                HSV hsv = { hue, 255, rgb_matrix_config.hsv.v };
                RGB rgb = hsv_to_rgb(hsv);
                rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
            }
        }
        else if (effect == RGB_MATRIX_JELLYBEAN_RAINDROPS) { 
            // OVERWRITTEN WITH: Liquid Mercury
            for (uint8_t i = led_min; i < led_max; i++) {
                // Slower undulation
                uint8_t time_offset = (timer / 30) + (g_led_config.point[i].x / 2) + (g_led_config.point[i].y / 2);
                uint8_t val = 60 + scale8(sin8(time_offset), 195); 
                // Subtle metallic blue tint: Hue 130, Saturation 40
                HSV hsv = { 130, 40, scale8(val, rgb_matrix_config.hsv.v) }; 
                RGB rgb = hsv_to_rgb(hsv);
                rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
            }
        }
        else if (effect == RGB_MATRIX_SOLID_SPLASH) { 
            // OVERWRITTEN WITH: Sakura Bloom
            uint8_t count = g_last_hit_tracker.count;
            for (uint8_t i = led_min; i < led_max; i++) {
                HSV hsv = { 220, 255, 0 }; // Pink base
                uint8_t val = 0;
                uint8_t sat = 255;
                for (uint8_t j = 0; j < count; j++) {
                    int16_t dx = g_led_config.point[i].x - g_last_hit_tracker.x[j];
                    int16_t dy = g_led_config.point[i].y - g_last_hit_tracker.y[j];
                    
                    uint8_t dist = sqrt16(dx * dx + dy * dy); 
                    uint16_t tick = scale16by8(g_last_hit_tracker.tick[j], qadd8(speed, 1));
                    uint16_t effect_time = tick - dist;
                    
                    if (effect_time < 255 && tick >= dist) {
                        uint8_t intensity = 255 - effect_time;
                        val = qadd8(val, intensity);
                        sat = qsub8(sat, intensity / 2); // gets whiter as it gets brighter
                    }
                }
                hsv.v = scale8(val, rgb_matrix_config.hsv.v);
                hsv.s = sat;
                RGB rgb = hsv_to_rgb(hsv);
                rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
            }
        }
        else if (effect == RGB_MATRIX_MULTISPLASH) { 
            // OVERWRITTEN WITH: Event Horizon
            uint8_t count = g_last_hit_tracker.count;
            for (uint8_t i = led_min; i < led_max; i++) {
                HSV hsv = { 190, 255, 0 }; // Deep purple
                uint8_t val = 0;
                for (uint8_t j = 0; j < count; j++) {
                    int16_t dx = g_led_config.point[i].x - g_last_hit_tracker.x[j];
                    int16_t dy = g_led_config.point[i].y - g_last_hit_tracker.y[j];
                    uint8_t dist = sqrt16(dx * dx + dy * dy); 
                    
                    uint16_t tick = scale16by8(g_last_hit_tracker.tick[j], qadd8(speed, 1));
                    uint16_t time = tick * 2; // explosion speed multiplier
                    uint16_t effect_time = time - dist;
                    
                    if (effect_time < 255 && time >= dist) {
                        uint8_t intensity = 255 - effect_time;
                        val = qadd8(val, intensity);
                    }
                }
                hsv.v = scale8(val, rgb_matrix_config.hsv.v);
                RGB rgb = hsv_to_rgb(hsv);
                rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
            }
        }
        else if (effect == RGB_MATRIX_SOLID_REACTIVE_WIDE) {
            // OVERWRITTEN WITH: Reactive Matrix Drop
            uint8_t count = g_last_hit_tracker.count;
            for (uint8_t i = led_min; i < led_max; i++) {
                HSV hsv = { rgb_matrix_config.hsv.h, rgb_matrix_config.hsv.s, 0 }; 
                uint8_t val = 0;
                for (uint8_t j = 0; j < count; j++) {
                    int16_t dx = g_led_config.point[i].x - g_last_hit_tracker.x[j];
                    int16_t dy = g_led_config.point[i].y - g_last_hit_tracker.y[j];
                    
                    // Allow small horizontal bleed (stagger tolerance), and only flow downwards
                    if (abs(dx) <= 12 && dy >= -4) {
                        uint16_t tick = scale16by8(g_last_hit_tracker.tick[j], qadd8(speed, 1));
                        uint16_t time = tick * 2; // drop speed
                        uint16_t effect_time = time - dy;
                        
                        if (effect_time < 255 && time >= dy) {
                            uint8_t intensity = 255 - effect_time;
                            val = qadd8(val, intensity);
                        }
                    }
                }
                hsv.v = scale8(val, rgb_matrix_config.hsv.v);
                RGB rgb = hsv_to_rgb(hsv);
                rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
            }
        }
        else if (effect == RGB_MATRIX_SOLID_REACTIVE_CROSS) {
            // OVERWRITTEN WITH: Neon Laser
            uint8_t count = g_last_hit_tracker.count;
            for (uint8_t i = led_min; i < led_max; i++) {
                HSV hsv = { 130, 255, 0 }; // Cyan base
                uint8_t val = 0;
                for (uint8_t j = 0; j < count; j++) {
                    int16_t dx = g_led_config.point[i].x - g_last_hit_tracker.x[j];
                    int16_t dy = g_led_config.point[i].y - g_last_hit_tracker.y[j];
                    
                    // Only light up the exact row (horizontal laser)
                    if (abs(dy) <= 6) {
                        uint16_t tick = scale16by8(g_last_hit_tracker.tick[j], qadd8(speed, 1));
                        uint16_t time = tick * 4; // fast laser speed
                        uint16_t dist = abs(dx); 
                        
                        uint16_t effect_time = time - dist;
                        if (effect_time < 255 && time >= dist) {
                            uint8_t intensity = 255 - effect_time;
                            val = qadd8(val, intensity);
                            if (intensity > 150) {
                                hsv.h = 220; // Core of the laser burns pink
                            }
                        }
                    }
                }
                hsv.v = scale8(val, rgb_matrix_config.hsv.v);
                RGB rgb = hsv_to_rgb(hsv);
                rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
            }
        }
        else if (effect == RGB_MATRIX_SOLID_REACTIVE_NEXUS) {
            // OVERWRITTEN WITH: Supernova
            uint8_t count = g_last_hit_tracker.count;
            for (uint8_t i = led_min; i < led_max; i++) {
                HSV hsv = { 20, 255, 0 }; // Orange base
                uint8_t val = 0;
                for (uint8_t j = 0; j < count; j++) {
                    int16_t dx = g_led_config.point[i].x - g_last_hit_tracker.x[j];
                    int16_t dy = g_led_config.point[i].y - g_last_hit_tracker.y[j];
                    uint8_t dist = sqrt16(dx * dx + dy * dy); 
                    
                    // Starburst shape: horizontal, vertical, and diagonal lines
                    if (abs(dx) <= 6 || abs(dy) <= 6 || abs(abs(dx) - abs(dy)) <= 6) {
                        uint16_t tick = scale16by8(g_last_hit_tracker.tick[j], qadd8(speed, 1));
                        uint16_t time = tick * 3;
                        uint16_t effect_time = time - dist;
                        if (effect_time < 255 && time >= dist) {
                            uint8_t intensity = 255 - effect_time;
                            val = qadd8(val, intensity);
                            if (intensity > 180) {
                                hsv.h = 40; // Yellow-hot core
                            } else if (intensity < 80) {
                                hsv.h = 190; // Deep purple ember fade
                            }
                        }
                    }
                }
                hsv.v = scale8(val, rgb_matrix_config.hsv.v);
                RGB rgb = hsv_to_rgb(hsv);
                rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
            }
        }
        else if (effect == RGB_MATRIX_HUE_BREATHING) {
            // OVERWRITTEN WITH: Cyberpunk Pulse
            uint8_t time_offset = (timer * speed) / 100;
            uint8_t phase = time_offset % 255;
            uint8_t val = 0;
            
            // Double heartbeat rhythm
            if (phase < 60) {
                val = scale8(sin8(phase * 4), 255); // First beat
            } else if (phase > 80 && phase < 140) {
                val = scale8(sin8((phase - 80) * 4), 200); // Second beat
            } else {
                val = 20; // Dim background glow
            }
            
            // Alternate hue between Neon Pink (210) and Electric Cyan (130) on every heartbeat
            uint8_t cycle = (time_offset / 255);
            uint8_t hue = (cycle % 2 == 0) ? 210 : 130;
            
            for (uint8_t i = led_min; i < led_max; i++) {
                HSV hsv = { hue, 255, scale8(val, rgb_matrix_config.hsv.v) };
                RGB rgb = hsv_to_rgb(hsv);
                rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
            }
        }
        else if (effect == RGB_MATRIX_PIXEL_RAIN) {
            // OVERWRITTEN WITH: Blood Rain
            for (uint8_t i = led_min; i < led_max; i++) {
                uint8_t time_offset = (timer / 15) - (g_led_config.point[i].y * 2);
                uint8_t col_hash = (g_led_config.point[i].x * 17) % 255;
                uint8_t phase = time_offset + col_hash;
                
                uint8_t val = 0;
                if (phase > 200) {
                    // Bright tip of the rain drop
                    val = scale8((phase - 200) * 4, 255); 
                } else {
                    // Fading red trail
                    val = scale8(phase, 60); 
                }
                
                HSV hsv = { 0, 255, scale8(val, rgb_matrix_config.hsv.v) }; // Crimson Red
                RGB rgb = hsv_to_rgb(hsv);
                rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
            }
        }
    }
    return false; // let default indicators run over top of our effects
}

// --- TAP DANCE LOGIC ---

typedef struct {
    bool is_press_action;
    uint8_t state;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

uint8_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return MORE_TAPS;
        else return MORE_TAPS;
    }
    return MORE_TAPS;
}

static tap lshift_tap_state = {
    .is_press_action = true,
    .state = 0
};

void lshift_finished(tap_dance_state_t *state, void *user_data) {
    lshift_tap_state.state = cur_dance(state);
    switch (lshift_tap_state.state) {
        case SINGLE_TAP: 
            SEND_STRING("[]" SS_TAP(X_LEFT));
            break;
        case SINGLE_HOLD: 
            register_code(KC_LSFT); 
            break;
        case DOUBLE_TAP: 
            SEND_STRING("[]" SS_TAP(X_LEFT));
            break;
        case DOUBLE_HOLD: 
            register_code(KC_LSFT); 
            break;
    }
}

void lshift_reset(tap_dance_state_t *state, void *user_data) {
    if (lshift_tap_state.state == SINGLE_HOLD || lshift_tap_state.state == DOUBLE_HOLD) {
        unregister_code(KC_LSFT);
    }
    lshift_tap_state.state = 0;
}

static tap rshift_tap_state = {
    .is_press_action = true,
    .state = 0
};

void rshift_finished(tap_dance_state_t *state, void *user_data) {
    rshift_tap_state.state = cur_dance(state);
    switch (rshift_tap_state.state) {
        case SINGLE_TAP: 
            SEND_STRING("{}" SS_TAP(X_LEFT));
            break;
        case SINGLE_HOLD: 
            register_code(KC_RSFT); 
            break;
        case DOUBLE_TAP: 
            SEND_STRING("{}" SS_TAP(X_LEFT));
            break;
        case DOUBLE_HOLD: 
            register_code(KC_RSFT); 
            break;
    }
}

void rshift_reset(tap_dance_state_t *state, void *user_data) {
    if (rshift_tap_state.state == SINGLE_HOLD || rshift_tap_state.state == DOUBLE_HOLD) {
        unregister_code(KC_RSFT);
    }
    rshift_tap_state.state = 0;
}

tap_dance_action_t tap_dance_actions[] = {
    [0] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lshift_finished, lshift_reset),
    [1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, rshift_finished, rshift_reset)
};
