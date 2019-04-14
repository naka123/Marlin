/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2019 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "../../inc/MarlinConfig.h"

#if ENABLED(DELTA)

#include "../gcode.h"

  #include "../../module/delta.h"
  #include "../../module/motion.h"

  #define DEBUG_OUT ENABLED(DEBUG_LEVELING_FEATURE)
  #include "../../core/debug_out.h"

  /**
   * M667: Set delta diagonal rod trim
   */
  void GcodeSuite::M667() {
    if (DEBUGGING(LEVELING)) DEBUG_ECHOLNPGM(">>> M667");
    LOOP_XYZ(i) {
      if (parser.seen(axis_codes[i])) {
        const float v = parser.value_linear_units();
        delta_diagonal_rod_trim[i] = v;
        if (DEBUGGING(LEVELING)) DEBUG_ECHOLNPAIR("delta_diagonal_rod_trim[", axis_codes[i], "] = ", delta_diagonal_rod_trim[i]);
      }
    }
    if (DEBUGGING(LEVELING)) DEBUG_ECHOLNPGM("<<< M667");
  }


#endif // DELTA
