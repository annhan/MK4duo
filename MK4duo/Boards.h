/**
 * MK4duo Firmware for 3D Printer, Laser and CNC
 *
 * Based on Marlin, Sprinter and grbl
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 * Copyright (c) 2020 Alberto Cotronei @MagoKimbra
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
/*
58-18
 */

/*
 * 
 * 
cAI dAT
M352 Y M1
 */
 /*
 onfig:  G21    ; Units in (mm)
Config:Steps per unit:
Config:  M92 X80.000 Y80.000 Z3200.000
Config:  M92 T0 E625.000
Config:Maximum Acceleration (units/s2):
Config:  M201 X3000 Y3000 Z50
Config:  M201 T0 E1000
Config:Maximum feedrates (units/s):
Config:  M203 X300.000 Y300.000 Z2.000
Config:  M203 T0 E100.000
Config:Acceleration (units/s2): P<DEFAULT_ACCELERATION> V<DEFAULT_TRAVEL_ACCELERATION> T* R<DEFAULT_RETRACT_ACCELERATION>
Config:  M204 P3000.000 V3000.000
Config:  M204 T0 R10000.000
Config:Advanced: B<DEFAULT_MIN_SEGMENT_TIME> S<DEFAULT_MIN_FEEDRATE> V<DEFAULT_MIN_TRAVEL_FEEDRATE>
Config:  M205 B20000 S0.000 V0.000
Config:Jerk: X<DEFAULT_XJERK> Y<DEFAULT_YJERK> Z<DEFAULT_ZJERK> T* E<DEFAULT_EJERK>
Config:  M205 X10.000 Y10.000 Z0.400
Config:  M205 T0 E5.000
Config:Set axis max travel:
Config:  M228 S0 X200.000 Y200.000 Z200.000
Config:Set axis min travel:
Config:  M228 S1 X0.000 Y0.000 Z0.000
Config:Total number D<driver extruder> E<Extruder> H<Hotend> B<Bed> C<Chamber> <Fan>
Config:  M353 D1 E1 H1 B0 C0 F2
Config:Hotend assignment T<Tool> H<Hotend>
Config:  M563 T0 D0 H0
Config:Heater Sensor parameters: H<Heater> P<Pin> S<Type> A<R25> B<BetaK> C<Steinhart-Hart C> R<Pullup> L<ADC low offset> O<ADC high offset>:
Config:  M305 H0 P0 S1 A100000.0 B4092.0 C0.0000000000 R4700.0 L0 O0
Config:Heater parameters: H<Heater> P<Pin> A<Power Drive Min> B<Power Drive Max> C<Power Max> F<Freq> L<Min Temp> O<Max Temp> U<Use Pid 0-1> I<Hardware Inverted 0-1> R<Thermal Protection 0-1> Q<Pwm Hardware 0-1>:
Config:  M306 H0 P3 A40 B230 C255 F250 L5 O275 U1 I0 Q1 R0
Config:Heater PID parameters: H<Heater> P<Proportional> I<Integral> D<Derivative>:
Config:  M301 H0 P40.00 I7.00 D60.00
Config:Z raise: Z<point>:
Config:  M217 Z1.00
Config:Hotend offset (unit): T<Tool> X<offset> Y<offset> Z<offset>:
Config:  M218 T0 X0.000 Y0.000 Z0.000
Config:Fans: P<Fan> U<Pin> L<Min Speed> X<Max Speed> I<Hardware Inverted 0-1> H<Auto mode> T<Trig Temp> F<Freq>
Config:  M106 P0 U6 L0 X255 F250 I0 H-1
Config:Fans: P<Fan> U<Pin> L<Min Speed> X<Max Speed> I<Hardware Inverted 0-1> H<Auto mode> T<Trig Temp>
Config:  M106 P1 U5 L0 X255 I0 H0 T50
Config:Endstops logic:
Config:  M123 X0 Y0 Z0
Config:Endstops pullup:
Config:  M124 X0 Y0 Z0
Config:Stepper driver pins E<En pin> D<Dir pin> S<Step pin> L<En logic> M<Step logic>
Config:  M352 X E37 D34 S35 L0 M0
Config:  M352 Y E33 D23 S22 L0 M0
Config:  M352 Z E24 D26 S25 L0 M0
Config:  M352 T0 E48 D46 S47 L0 M0
Config:Stepper Direction
Config:  M569 X0 Y0 Z0
Config:  M569 T0 E0
Config:Stepper driver control Q<Quad stepping> D<Dir delay> P<min pulse> R<max rate>
Config:  M569 Q1 D0 P0 R500000
Stats: Total:0, Finished:0, Failed:0
Stats: Total print time:0s, Longest job:0s
Stats: Power on time:2m 0s
  */
#pragma once

// Macros for board type
#define BOARD_UNKNOWN -1
//#define MB(board) (MOTHERBOARD==1705)
#define MB(board) (MOTHERBOARD==BOARD_##board)

//#define BOARD_ULTRATRONICS    1705    // Ultratronics v1.0 ARM 32 bit board
/**
 * RAMPS 1.3 / 1.4 - ATmega1280, ATmega2560
 */
#define BOARD_RAMPS_OLD          3    // MEGA/RAMPS up to 1.2
#define BOARD_RAMPS_13_HFB      33    // RAMPS 1.3 / 1.4 (Power outputs: Hotend, Fan, Bed)
#define BOARD_RAMPS_13_HHB      34    // RAMPS 1.3 / 1.4 (Power outputs: Hotend0, Hotend1, Bed)
#define BOARD_RAMPS_13_HFF      35    // RAMPS 1.3 / 1.4 (Power outputs: Hotend, Fan, Fan)
#define BOARD_RAMPS_13_HHF      36    // RAMPS 1.3 / 1.4 (Power outputs: Hotend0, Hotend1, Fan)
#define BOARD_RAMPS_13_HHH      37    // RAMPS 1.3 / 1.4 (Power outputs: Hotend0, Hotend1, Hotend2)

/**
 * RAMPS Derivates - ATmega1280, ATmega2560
 */
#define BOARD_ULTIMAKER          7    // Ultimaker
#define BOARD_SAINSMART_2IN1    39    // SainSmart 2 in 1
#define BOARD_MKS_BASE          40    // MKS BASE v1.0
#define BOARD_MKS_13            47    // MKS GEN v1.3 or 1.4
#define BOARD_TRIGORILLA        49    // TRIGORILLA (ANYCUBIC)
#define BOARD_MKS_GEN_L         53    // MKS GEN L
#define BOARD_AZTEEG_X3         67    // Azteeg X3
#define BOARD_AZTEEG_X3_PRO     68    // Azteeg X3 Pro
#define BOARD_ULTIMAKER_OLD     71    // Ultimaker (Older electronics. Pre 1.5.4. This is rare)
#define BOARD_ULTIMAIN_2        72    // Ultimainboard 2.x (Uses TEMP_SENSOR 20)
#define BOARD_GT2560_REV_A      74    // Geeetech GT2560 Rev. A
#define BOARD_GT2560_REV_A_PLUS 75    // Geeetech GT2560 Rev. A+
#define BOARD_GT2560_V3         76    // Geeetech GT2560 Rev. B for A10(M/D)
#define BOARD_GT2560_V3_A20     86    // Geeetech GT2560 Rev. B for A20(M/D)
#define BOARD_3DRAG             77    // 3Drag Controller
#define BOARD_K8200             78    // Vellemann K8200 Controller (variant of the 3Drag Controller)
#define BOARD_3DVERTEX          79    // 3DVertex Controller (Velleman K8400)
#define BOARD_RUMBA             80    // Rumba
#define BOARD_ANET             100    // Anet board for A2, A6 and A8
#define BOARD_RAMPS_ENDER_4    243    // Creality Ender-4, CR-8
#define BOARD_MAKEBOARD_MINI   431    // MakeBoard Mini v2.1.2 is a control board sold by MicroMake

/**
 * Other ATmega1280, ATmega2560
 */
#define BOARD_CHEAPTRONIC        2    // Cheaptronic v1.0
#define BOARD_ELEFU_3           21    // Elefu Ra Board (v3)
#define BOARD_MKS_MINI          41    // MKS MINI 1.0
#define BOARD_MEGATRONICS       70    // Megatronics
#define BOARD_RAMBO            301    // Rambo
#define BOARD_MINIRAMBO_10A    302    // Mini-Rambo 1.0a
#define BOARD_MINIRAMBO        303    // Mini-Rambo
#define BOARD_PIBOT            316    // PiBot Controller Rev2.0
#define BOARD_MEGATRONICS_2    701    // Megatronics v2.0
#define BOARD_MEGATRONICS_3    703    // Megatronics v3.0
#define BOARD_LEAPFROG         999    // Leapfrog

/**
 * ATmega1281, ATmega2561
 */
#define BOARD_MINITRONICS      702    // Minitronics v1.0

/**
 * Sanguinololu and Derivatives - ATmega644P, ATmega1284P
 */
#define BOARD_SANGUINOLOLU_11    6    // Sanguinololu < 1.2
#define BOARD_SANGUINOLOLU_12   62    // Sanguinololu 1.2 and above
#define BOARD_MELZI             63    // Melzi
#define BOARD_STB_11            64    // STB V1.1
#define BOARD_AZTEEG_X1         65    // Azteeg X1
#define BOARD_MELZI_CREALITY    89    // Melzi Creality3D board (for CR-10 etc)

/**
 * Other ATmega644P, ATmega644, ATmega1284P
 */
#define BOARD_GEN6               5    // Gen6
#define BOARD_GEN3_PLUS          9    // Gen3+
#define BOARD_GEN7_CUSTOM       10    // Gen7 custom (Alfons3 Version) "https://github.com/Alfons3/Generation_7_Electronics"
#define BOARD_GEN7_12           11    // Gen7 v1.1, v1.2
#define BOARD_GEN7_13           12    // Gen7 v1.3
#define BOARD_GEN7_14           13    // Gen7 v1.4
#define BOARD_SETHI             20    // Sethi 3D_1
#define BOARD_GEN3_MONOLITHIC   22    // Gen3 Monolithic Electronics
#define BOARD_OMCA_A            90    // Alpha OMCA board
#define BOARD_OMCA              91    // Final OMCA board

/**
 * Teensyduino - AT90USB1286, AT90USB1286P
 */
#define BOARD_TEENSYLU           8    // Teensylu

/**
 * Custom Boards
 */
#define BOARD_99                99    // Custom Board


/**
 * SAM3X8E ARM Cortex M3
 */
#define BOARD_PICCOLO_3D      1400    // PICCOLO_3D ARM 32 Arduino DUE
#define BOARD_RADDS           1401    // RADDS ARM 32 bit board
#define BOARD_RAMPS_FD_V1     1403    // RAMPS-FD V1 ARM 32 bit board
#define BOARD_RAMPS_FD_V2     1404    // RAMPS-FD V2 ARM 32 bit board
#define BOARD_CNCONTROLS_V14  1405    // CNControls V14
#define BOARD_ULTIMAKER4DUE   1407    // Ultimaker Shield + Arduino DUE Aleksandr Varaksa mods (https://iworld4us.com/diy-3d-printer.html)
#define BOARD_RAMPS_SMART_HFB 1411    // RAMPS-SMART (Power outputs: Hotend, Fan, Bed)
#define BOARD_RAMPS_SMART_HHB 1412    // RAMPS-SMART (Power outputs: Hotend0, Hotend1, Bed)
#define BOARD_RAMPS_SMART_HFF 1413    // RAMPS-SMART (Power outputs: Hotend, Fan0, Fan1)
#define BOARD_RAMPS_SMART_HHF 1414    // RAMPS-SMART (Power outputs: Hotend0, Hotend1, Fan)
#define BOARD_RAMPS4DUE       1430    // RAMPS4DUE with AndrewBCN's RAMPS mods (http://forums.reprap.org/read.php?219,479626,page=1) ARM 32 bit board
#define BOARD_RAMPS_17_HFB    1433    // RAMPS 1.7 (Power outputs: Hotend, Fan, Bed)
#define BOARD_ALLIGATOR_R2    1502    // ALLIGATOR R2 ARM 32 bit board
#define BOARD_ALLIGATOR_R3    1503    // ALLIGATOR R3 ARM 32 bit board
#define BOARD_RURAMPS4D_V11   1550    // RuRAMPS4Duo v1.1 (Power outputs: Hotend0, Hotend1, Hotend2, Fan0, Fan1, Bed)
#define BOARD_RURAMPS4D_V13   1551    // RuRAMPS4Duo v1.3 (Power outputs: Hotend0, Hotend1, Hotend2, Fan0, Fan1, Bed)
#define BOARD_ARCHIM2         1590    // UltiMachine Archim2 (with TMC2130 drivers)
#define BOARD_ULTRATRONICS    1705    // Ultratronics v1.0 ARM 32 bit board

/**
 * SAMD21J18
 */
#define BOARD_MINITRONICS_V2  2706    // Minitronics v2.0

/**
 * STM32 ARM Cortex-M4F
 */
#define BOARD_RUMBA32_AUS3D   4203    // RUMBA32 STM32F446VET6 based controller from Aus3D
#define BOARD_RUMBA32_MKS     4204    // RUMBA32 STM32F446VET6 based controller from MKS
#define BOARD_STEVAL_3DP001V1 4206    // STEVAL-3DP001V1 3D PRINTER BOARD
