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
#ifndef MSIM_GRH_DISPLAY_SH1106_H_
#define MSIM_GRH_DISPLAY_SH1106_H_ 1

#include "mcusim/avr-gcc/avr/drivers/display/sh1106/sh1106.h"

int	MSIM_SH1106_Print(struct MSIM_SH1106 *dev, const char *text);

#endif /* MSIM_GRH_DISPLAY_SH1106_H_ */
