/*
 * LED.c
 *
 *  Created on: Mar 16, 2024
 *      Author: Rimvis
 */

#include "LED.h"

#ifdef CONTINUOS_COLOR
const uint32_t colors[COLOR_COUNT] ={c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14, c15, c16, c17, c18, c19, c20, c21, c22, c23, c24, c25, c26, c27, c28, c29, c30, c31};
#else
const uint32_t colors[COLOR_COUNT] ={c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14, c15, c16, c17, c18};
#endif

uint32_t *pBuff;


void SetModuleColor(Module_t *module, uint8_t r, uint8_t g, uint8_t b)
{
	for(uint8_t i=0; i < PIXEL_NUM_MODULE; i++)
	{
		SetPixelColor(&module->pixels[i], r, g ,b);
	}
}

void SetModuleColorP(Module_t *module, uint8_t c)
{
	for(uint8_t i=0; i < PIXEL_NUM_MODULE; i++)
	{
		SetPixelColorP(&module->pixels[i], c);
	}
}

void SetPixelColor(Pixel_t *pixel, uint8_t r, uint8_t g, uint8_t b)
{
	for(uint8_t i=0; i < LED_NUM_PIXEL; i++)
	{
		SetLedColor(&pixel->leds[i], r, g ,b);
	}
}

void SetPixelColorP(Pixel_t *pixel, uint8_t c)
{
	for(uint8_t i=0; i < LED_NUM_PIXEL; i++)
	{
		SetLedColorP(&pixel->leds[i], c);
	}
}

void SetLedColorP(LedRGB_t *led, uint8_t c)
{
	led->data = colors[c];

#ifdef DIMM
	// not so bright
	led->color.r >>= 1;
	led->color.g >>= 1;
	led->color.b >>= 1;

#endif
}

void SetLedColor(LedRGB_t *led, uint8_t r, uint8_t g, uint8_t b)
{
	led->color.r = r;
	led->color.g = g;
	led->color.b = b;

#ifdef DIMM
	// not so bright
	led->color.r >>= 1;
	led->color.g >>= 1;
	led->color.b >>= 1;

#endif
}

void InitModule(Module_t *module, TIM_HandleTypeDef *htim, uint32_t channel)
{
	/*for(uint8_t i = 0; i < LED_DMA_BUFF_SIZE; i++)
	{
		module->dmaBuffer[0] = 0;
	}*/
	module->htim = htim;
	module->Channel = channel;
	module->status = MODULE_STATUS_OK;
	SetModuleColor(module, 0, 0, 0);
}

void UpdateModuleColor(Module_t *module)
{
	 module->status = MODULE_STATUS_UPDATING;
     pBuff = module->dmaBuffer;
     for(uint8_t i = 0; i < PIXEL_NUM_MODULE; i++)
     {
    	 for (uint8_t j = 0; j < LED_NUM_PIXEL; j++)
    	 {
    		 for (int k = LED_BIT - 1; k >= 0; k--)
    		 {
    			 if ((module->pixels[i].leds[j].data >> k) & 0x01)
    			 {
    				 *pBuff = LED_ONE;
    			 }
    			 else
    			 {
    				 *pBuff = LED_ZERO;
    			 }
    			 pBuff++;
    		 }
    	 }
     }
     module->dmaBuffer[LED_DMA_BUFF_SIZE - 1] = 0; // last element must be 0!

     HAL_TIM_PWM_Start_DMA(module->htim, module->Channel, module->dmaBuffer, LED_DMA_BUFF_SIZE);
}


void UpdateModule(Module_t *module)
{
	if(module->status !=MODULE_STATUS_UPDATING){
	module->status = MODULE_STATUS_NEEDS_UPDATE;
	}
}



