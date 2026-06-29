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

#pragma once

#define ENCODER_DEFAULT_POS 0x3

/* SPI Config for spi flash*/
#define SPI_DRIVER SPIDQ
#define SPI_SCK_PIN B3
#define SPI_MOSI_PIN B5
#define SPI_MISO_PIN B4
#define SPI_MOSI_PAL_MODE 5

#define EXTERNAL_FLASH_SPI_SLAVE_SELECT_PIN C12

/* I2C Config for LED Driver */
#define SNLED27351_I2C_ADDRESS_1 SNLED27351_I2C_ADDRESS_GND
#define SNLED27351_I2C_ADDRESS_2 SNLED27351_I2C_ADDRESS_VDDIO

#define I2C1_OPMODE OPMODE_I2C
#define I2C1_CLOCK_SPEED 400000 /* 400000 */

#define RGB_TRIGGER_ON_KEYDOWN
#define LEADER_TIMEOUT 1500 // Increased from 350 to 1.5 seconds so you have plenty of time!

// --- RGB CORE FEATURES ---
#define RGB_MATRIX_INDICATORS_ADVANCED
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_KEYREACTIVE_ENABLED

// --- RGB TWEAKS ---
// Typing Heatmap (Makes it fade slower, tweaked to 35ms for balance)
#define RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS 35
#define RGB_MATRIX_TYPING_HEATMAP_INCREASE_STEP 32 // Keeps it highly responsive when hitting keys

// Digital Rain (Increases drop density significantly)
#define RGB_DIGITAL_RAIN_DROPS 40

// --- MACRO FIXES ---
// Slows down SEND_STRING slightly so the OS doesn't drop characters (fixes missing "commit -m")
#define TAP_CODE_DELAY 10
