/**
 * MK4duo Firmware for 3D Printer, Laser and CNC
 *
 * Based on Marlin, Sprinter and grbl
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 * Copyright (c) 2019 Alberto Cotronei @MagoKimbra
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 */
#pragma once

#include <avr/wdt.h>

class Watchdog {

  public: /** Constructor */

    Watchdog() {}

  public: /** Public Function */

    // Initialize watchdog with a 4 second interrupt time
    static void init(void);

    // Reset watchdog. MUST be called at least every 4 seconds.
    static void reset(void);

    // Enable the watchdog with the specified timeout.
    FORCE_INLINE static void enable(uint32_t timeout) { wdt_enable(timeout); }

};

extern Watchdog watchdog;
