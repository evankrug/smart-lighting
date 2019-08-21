/*
 * app_animations.h
 *
 * Created: 7/29/2019 11:09:51 AM
 *  Author: 243400
 */ 


#ifndef APP_ANIMATIONS_H_
#define APP_ANIMATIONS_H_

#include <ElementAnimationEngine.h>

#include <avr/io.h>
#include "ws2812b.h"
#include "MorphTypes.h"
#include "MorphConfig.h"
#include "MorphTime.h"
#include <util/delay.h>

#include <util/delay.h>

extern ElementAnimationBufferConfigStruct lights_buffer;


//Light strip values
#define BREW_PROG_DELAY 1000 //placeholder for now; need to determine actual time
#define SNEAK_TIMER_TICK 2000
#define FLASH_DELAY 3
#define NUM_FLASHES 10 //number of times the lights should flash to indicate end of brew cycle
#define NUM_LEDS 25 //number of leds in the light strip
#define FULL_COLOR 255

//RGB values
#define RED_PIN		    17
#define GREEN_PIN	    12
#define BLUE_PIN		11


#define M_PI 3.14159265358979323846	/* pi */
#define PERIOD 5.0

#define RED_TIME_OFFSET    0
#define GREEN_TIME_OFFSET  PERIOD/3.0f * 1000
#define BLUE_TIME_OFFSET   (PERIOD/3.0f) * 2 * 1000


// This animation displays the amount to brew (drip or kcup)

// This animation ensures all of the icons on the rim of the display are shown.
enum ElementAnimationEngineStatus display_general();

static ElementFunctionalAnimationInstance display_general_anim_func =
{
	&display_general
};

static ElementAnimationInstance display_general_anim =
{
	.animation_id = 0x0,
	.is_calculated = false,
	.cal_anim = NULL,
	.fun_anim = &display_general_anim_func
};

enum ElementAnimationEngineStatus mysample();

static ElementFunctionalAnimationInstance sampleanim =
{
	&mysample
};

static ElementAnimationInstance second_anim =
{
	.animation_id = 0x1,
	.is_calculated = false,
	.cal_anim = NULL,
	.fun_anim = &sampleanim
};



enum ElementAnimationEngineStatus coffeeProgress();
static ElementFunctionalAnimationInstance brewProgAnim =
{
	&coffeeProgress
};
static ElementAnimationInstance brewProgressAnim =
{
	.animation_id = 0x2,
	.is_calculated = false,
	.cal_anim = NULL,
	.fun_anim = &brewProgAnim
};

enum ElementAnimationEngineStatus softFlash();
static ElementFunctionalAnimationInstance softFlashFunAnim =
{
	&softFlash
};
static ElementAnimationInstance softFlashAnim =
{
	.animation_id = 0x2,
	.is_calculated = false,
	.cal_anim = NULL,
	.fun_anim = &softFlashFunAnim
};

enum ElementAnimationEngineStatus sneakCupTimer();
static ElementFunctionalAnimationInstance sneakCupFunAnim =
{
	&sneakCupTimer
};
static ElementAnimationInstance sneakCupAnim =
{
	.animation_id = 0x3,
	.is_calculated = false,
	.cal_anim = NULL,
	.fun_anim = &sneakCupFunAnim
};


enum ElementAnimationEngineStatus nightLightBlue();
static ElementFunctionalAnimationInstance nightLightBlueFunc =
{
	&nightLightBlue
};
static ElementAnimationInstance nightLightBlueAnim =
{
	.animation_id = 0x4,
	.is_calculated = false,
	.cal_anim = NULL,
	.fun_anim = &nightLightBlueFunc
};


#endif /* APP_ANIMATIONS_H_ */