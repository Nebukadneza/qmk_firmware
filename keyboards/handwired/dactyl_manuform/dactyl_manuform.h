#ifndef REV2_H
#define REV2_H

#include "dactyl_manuform.h"

//void promicro_bootloader_jmp(bool program);
#include "quantum.h"


#ifdef USE_I2C
#include <stddef.h>
#ifdef __AVR__
	#include <avr/io.h>
	#include <avr/interrupt.h>
#endif
#endif


volatile static uint16_t layerkc1 = KC_NO;
volatile static bool hasregistered=false;

//void promicro_bootloader_jmp(bool program);

#define LAYOUT( \
	L00, L01, L02, L03, L04, L05, L06,                R06, R05, R04, R03, R02, R01, R00,\
	L10, L11, L12, L13, L14, L15, L16,                R16, R15, R14, R13, R12, R11, R10,\
	L20, L21, L22, L23, L24, L25, L26,                R26, R25, R24, R23, R22, R21, R20,\
	L30, L31, L32, L33, L34, L35, L36,                R36, R35, R34, R33, R32, R31, R30,\
	               L43, L44,                                    R44, R43,          \
	                         L45, L46,                R46, R45,                    \
	                                   L55, L56, R56, R55,                         \
	                                   L53, L54, R54, R53                         \
	) \
	{ \
		{ L00,   L01,   L02,    L03,   L04,   L05,   L06 }, \
		{ L10,   L11,   L12,    L13,   L14,   L15,   L16 }, \
		{ L20,   L21,   L22,    L23,   L24,   L25,   L26 }, \
		{ L30,   L31,   L32,    L33,   L34,   L35,   L36 }, \
		{ KC_NO, KC_NO, KC_NO,  L43,   L44,   L45,   L46 }, \
		{ KC_NO, KC_NO, KC_NO,  L53,   L54,   L55,   L56 }, \
\
		{ R06,   R05,   R04,   R03,   R02,   R01,   R00 }, \
		{ R16,   R15,   R14,   R13,   R12,   R11,   R10 }, \
		{ R26,   R25,   R24,   R23,   R22,   R21,   R20 }, \
		{ R36,   R35,   R34,   R33,   R32,   R31,   R30 }, \
		{ R46,   R45,   R44,   R43,   KC_NO, KC_NO, KC_NO }, \
		{ R56, R55, R54, R53,   KC_NO, KC_NO, KC_NO }, \
	}

#endif
