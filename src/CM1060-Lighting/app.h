/*
 * app.h
 *
 * Created: 7/29/2019 11:09:34 AM
 *  Author: 243400
 */ 


#ifndef APP_H_
#define APP_H_

#include <MorphTypes.h>
#include <ElementConfig.h>

typedef struct cm_state_struct{
	bool is_brewing;
	MorphTimeValue brew_start_time;
	MorphTimeValue brew_end_time;
	bool sneak_a_cup_active;
	MorphTimeValue sneak_start_time;
	bool underbody_active;
	uint8_t underbody_demo_id;
	float light_level;
	// Add anything else you want to track here.
	
} CMStateStruct;

extern CMStateStruct cm_state;


#define SNEAK_DURATION (MorphTimeValue)25000L

#define BREW_DURATION (MorphTimeValue)2L * 60L * 1000L

#define BREW_DONE_DURATION (MorphTimeValue)10000L

// BEGIN Pin setup

#define TANK_NTC_PIN		24

#define SNEAK_A_CUP_SWITCH_PIN 2
#define LID_SWITCH_PIN 3
#define AMBIENT_SWITCH_PIN 4
#define DEMO_SWITCH_PIN 5

#define SNEAK_A_CUP_SWITCH_ID 0
#define LID_SWITCH_ID 1
#define AMBIENT_SWITCH_ID 2
#define DEMO_SWITCH_ID 3

// END Pin setup



// Setup for the tank thermistor.
extern ElementThermistor tank_thermistor;

#define TANK_NTC_RES                10
#define TANK_NTC_PRESCALER          64
#define TANK_NTC_REF_TYPE           MorphADCExternalRef
#define TANK_NTC_REF_INDEX          0
#define TANK_NTC_SERIES_RESISTOR    49900
#define TANK_NTC_LOWEST_TEMP        0
#define TANK_NTC_HIGHEST_TEMP       200

#define TANK_NTC_NOMINAL_TEMP       25
#define TANK_NTC_NOMINAL_RESISTANCE 50000
#define TANK_NTC_BETA               3950


#endif /* APP_H_ */