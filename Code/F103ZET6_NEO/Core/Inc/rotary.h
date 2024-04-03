/*
 * Rotary encoder library for STM/ other C based MCU.
 */

#ifndef rotary_h
#define rotary_h

#include "main.h"


// Disable this emit codes once per step instead of twice.
#define HALF_STEP

// Values returned by 'process'
// No complete step yet.
#define DIR_NONE 0x0
// Clockwise step.
#define DIR_CW 0x10
// Anti-clockwise step.
#define DIR_CCW 0x20
// Default start state
#define R_START 0x0

typedef union
{
	struct
	{
		uint8_t r1;
		uint8_t r2;
	} status;
	uint16_t data;
} RotaryEncStatus_t;

typedef struct
{
	GPIO_TypeDef *GPIO_port;
	uint16_t GPIO_Pin;
} RotaryPin_t;

typedef struct
{
	RotaryEncStatus_t pinStatus;
	RotaryEncStatus_t historyStatus;
	uint8_t state;
	RotaryPin_t pin1;
	RotaryPin_t pin2;
	uint8_t counter;
	uint8_t changed;
} RotaryEnc_t;


void RotaryProcess(RotaryEnc_t *re, uint8_t max);


#endif
