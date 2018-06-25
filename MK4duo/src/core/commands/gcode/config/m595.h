/**
 * MK4duo Firmware for 3D Printer, Laser and CNC
 *
 * Based on Marlin, Sprinter and grbl
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
 * Copyright (C) 2013 Alberto Cotronei @MagoKimbra
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

/**
 * mcode
 *
 * Copyright (C) 2017 Alberto Cotronei @MagoKimbra
 */

#if ENABLED(SUPPORT_AD8495) || ENABLED(SUPPORT_AD595)

  #define CODE_M595

  /**
   * M595 - set AD595 or AD8495 offset & Gain H<hotend_number> O<offset> S<gain>
   */
  inline void gcode_M595(void) {

    int8_t hh = parser.seen('H') ? parser.value_int() : 0;

    if (!commands.get_target_heater(hh)) return;

    heaters[hh].sensor.ad595_offset = parser.floatval('O');
    heaters[hh].sensor.ad595_gain   = parser.floatval('S', 1);

    SERIAL_EM(MSG_AD595);

    LOOP_HOTEND() {

      if (heaters[h].sensor.ad595_gain == 0) heaters[h].sensor.ad595_gain = 1.0;

      SERIAL_MV(" H", h);
      SERIAL_MV(" Offset: ", heaters[h].sensor.ad595_offset, 3);
      SERIAL_EMV(", Gain: ", heaters[h].sensor.ad595_gain, 3);
    }
  }

#endif // ENABLED(SUPPORT_AD8495) || ENABLED(SUPPORT_AD595)
