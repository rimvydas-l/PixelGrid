/*
 * LED.h
 *
 *  Created on: Mar 16, 2024
 *      Author: Rimvis
 */

#ifndef INC_LED_H_
#define INC_LED_H_

//Inc
#include "stm32f1xx_hal.h"

//PD
#define LED_ZERO 22
#define LED_ONE 43

#define LED_NUM_PIXEL 8
#define PIXEL_NUM_MODULE 4
#define LED_NUM_MODULE LED_NUM_PIXEL * PIXEL_NUM_MODULE
#define LED_BIT 24
#define LED_DMA_BUFF_SIZE (LED_NUM_MODULE * LED_BIT) + 1

#define MODULE_COUNT 10

#define grb(rgb) ((((rgb >> 8) & 0x0000ff) << 16) | (((rgb >> 16) & 0x0000ff) << 8) |(rgb & 0x0000ff))
#define grbd(r, g, b) ((g << 16) | (r << 8) | b)

//#define DIMM

#define MODULE_STATUS_OK 1
#define MODULE_STATUS_UPDATING 2
#define MODULE_STATUS_NEEDS_UPDATE 3

#define CONTINUOS_COLOR

#ifdef CONTINUOS_COLOR

#define c1  grbd(255,0,0)
#define c2  grbd(255,51,0)
#define c3  grbd(255,102,0)
#define c4  grbd(255,153,0)
#define c5  grbd(255,204,0)
#define c6  grbd(255,255,0)
#define c7  grbd(204,255,0)
#define c8  grbd(153,255,0)
#define c9  grbd(102,255,0)
#define c10 grbd(51,255,0)
#define c11 grbd(0,255,0)
#define c12 grbd(0,255,51)
#define c13 grbd(0,255,102)
#define c14 grbd(0,255,153)
#define c15 grbd(0,255,204)
#define c16 grbd(0,255,255)
#define c17 grbd(0,204,255)
#define c18 grbd(0,153,255)
#define c19 grbd(0,102,255)
#define c20 grbd(0,53,255)
#define c21 grbd(0,0,255)
#define c22 grbd(51,0,255)
#define c23 grbd(102,0,255)
#define c24 grbd(153,0,255)
#define c25 grbd(204,0,255)
#define c26 grbd(255,0,255)
#define c27 grbd(255,0,204)
#define c28 grbd(255,0,153)
#define c29 grbd(255,0,102)
#define c30 grbd(255,0,53)
#define c31 grbd(0,0,0)

#define COLOR_COUNT 31

#else

#define c1  grb(0x0000ff)
#define c2  grb(0x000000)
#define c3  grb(0xff0000)
#define c4  grb(0xffffff)
#define c5  grb(0x008000)
#define c6  grb(0x800080)
#define c7  grb(0xffff00)
#define c8  grb(0xffa500)
#define c9  grb(0xee82ee)
#define c10 grb(0xc0c0c0)
#define c11 grb(0xffd700)
#define c12 grb(0x808080)
#define c13 grb(0xffc0cb)
#define c14 grb(0xff00ff)
#define c15 grb(0xadd8e6)
#define c16 grb(0x87ceeb)
#define c17 grb(0x00ffff)
#define c18 grb(0xf0e68c)

#define COLOR_COUNT 18

#endif

//PTD
typedef union
{
  struct
  {
    uint8_t b;
    uint8_t r;
    uint8_t g;
  } color;
  uint32_t data;
} LedRGB_t;

typedef struct
{
	LedRGB_t leds[LED_NUM_PIXEL];
} Pixel_t;

typedef struct
{
	Pixel_t pixels[PIXEL_NUM_MODULE];
	uint32_t dmaBuffer[LED_DMA_BUFF_SIZE];
	TIM_HandleTypeDef *htim;
	uint32_t Channel;
	uint8_t status;
} Module_t;


//PV


//PFP
void SetModuleColor(Module_t *module, uint8_t r, uint8_t g, uint8_t b);
void SetPixelColor(Pixel_t *pixel, uint8_t r, uint8_t g, uint8_t b);
void SetLedColor(LedRGB_t *led, uint8_t r, uint8_t g, uint8_t b);

void SetModuleColorP(Module_t *module, uint8_t c);
void SetPixelColorP(Pixel_t *pixel, uint8_t c);
void SetLedColorP(LedRGB_t *led, uint8_t c);

void InitModule(Module_t *module,TIM_HandleTypeDef *htim, uint32_t channel);
void UpdateModuleColor(Module_t *module);
void UpdateModule(Module_t *module);

#endif /* INC_LED_H_ */
