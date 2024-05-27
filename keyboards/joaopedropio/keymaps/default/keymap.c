// Copyright 2023 OakNinja (@oakninja)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "qp.h"
#include "qp_comms.h"

#include "qp_st77xx_opcodes.h"
#include "nyan/nyan.qgf.h"

#include "color.h"
#include "config.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_1x1(
        KC_A
        )
};


painter_device_t lcd;

void keyboard_post_init_kb(void) {
    //Display timeout
    wait_ms(LCD_WAIT_TIME);


    lcd = qp_st7789_make_spi_device(LCD_HEIGHT, LCD_WIDTH, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, LCD_SPI_DIVISOR, SPI_MODE);
    qp_init(lcd, LCD_ROTATION);

    // Some screens have inverted colors
    #ifdef LCD_INVERT_COLOR
    qp_comms_start(lcd);
    qp_comms_command(lcd, ST77XX_CMD_INVERT_ON);
    qp_comms_stop(lcd);
    #endif

    // Display offset
    qp_set_viewport_offsets(lcd, LCD_OFFSET_X, LCD_OFFSET_Y);

    // Power on display, fill with white
    qp_power(lcd, 1);
    qp_rect(lcd, 0, 0, LCD_HEIGHT, LCD_WIDTH, HSV_WHITE, 1);

    // Paint catpaste/Katten Paste
    painter_image_handle_t logo_image = qp_load_image_mem(gfx_nyan);
    qp_animate(lcd, 0, 0, logo_image);

    keyboard_post_init_user();
}