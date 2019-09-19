/*
 * This file is part of MCUSim, an XSPICE library with microcontrollers.
 *
 * Copyright (C) 2017-2019 MCUSim Developers, see AUTHORS.txt for contributors.
 *
 * MCUSim is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * MCUSim is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 *
 * Graphics for SH1106-based displays.
 */
#include <stdint.h>
#include <string.h>
#include <avr/pgmspace.h>

#include "mcusim/avr-gcc/avr/drivers/display/sh1106_graphics.h"

/* Symbols 6x8 pixels */
static const uint8_t PROGMEM zero[] =	{ 0x00, 0x3C, 0x42, 0x42, 0x3C, 0x00 };
static const uint8_t PROGMEM one[] =	{ 0x00, 0x00, 0x04, 0x7E, 0x00, 0x00 };
static const uint8_t PROGMEM two[] =	{ 0x00, 0x44, 0x62, 0x52, 0x4C, 0x00 };
static const uint8_t PROGMEM three[] =	{ 0x00, 0x24, 0x42, 0x4A, 0x34, 0x00 };
static const uint8_t PROGMEM four[] =	{ 0x00, 0x18, 0x14, 0x7E, 0x10, 0x00 };
static const uint8_t PROGMEM five[] =	{ 0x00, 0x2E, 0x4A, 0x4A, 0x32, 0x00 };
static const uint8_t PROGMEM six[] =	{ 0x00, 0x3C, 0x4A, 0x4A, 0x30, 0x00 };
static const uint8_t PROGMEM seven[] =	{ 0x00, 0x02, 0x62, 0x1A, 0x06, 0x00 };
static const uint8_t PROGMEM eight[] =	{ 0x00, 0x34, 0x4A, 0x4A, 0x34, 0x00 };
static const uint8_t PROGMEM nine[] =	{ 0x00, 0x0C, 0x52, 0x52, 0x3C, 0x00 };
static const uint8_t PROGMEM dot[] =	{ 0x00, 0x00, 0x40, 0x00, 0x00, 0x00 };

static void	write_mem(struct MSIM_SH1106 *, const uint8_t *, size_t);

/* Prints text at the current line of the display. */
int
MSIM_SH1106_Print(struct MSIM_SH1106 *dev, const char *text)
{
	const size_t len = strlen(text);

	MSIM_SH1106_Clean(dev);
	MSIM_SH1106_Write(dev, CB_LASTRAM);

	for (uint32_t i = 0; i < len; i++) {
		switch (text[i]) {
		case '0':
			write_mem(dev, zero, sizeof zero);
			break;
		case '1':
			write_mem(dev, one, sizeof one);
			break;
		case '2':
			write_mem(dev, two, sizeof two);
			break;
		case '3':
			write_mem(dev, three, sizeof three);
			break;
		case '4':
			write_mem(dev, four, sizeof four);
			break;
		case '5':
			write_mem(dev, five, sizeof five);
			break;
		case '6':
			write_mem(dev, six, sizeof six);
			break;
		case '7':
			write_mem(dev, seven, sizeof seven);
			break;
		case '8':
			write_mem(dev, eight, sizeof eight);
			break;
		case '9':
			write_mem(dev, nine, sizeof nine);
			break;
		case '.':
			write_mem(dev, dot, sizeof dot);
			break;
		default:
			break;
		}
	}
	MSIM_SH1106_Send(dev);

	return 0;
}

static void write_mem(struct MSIM_SH1106 *dev, const uint8_t *data, size_t len)
{
	for (size_t i = 0; i < len; i++) {
		MSIM_SH1106_Write(dev, pgm_read_byte(&data[i]));
	}
}
