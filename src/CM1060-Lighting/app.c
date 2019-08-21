/*
 * app.c
 *
 * Created: 7/29/2019 11:09:24 AM
 *  Author: 243400
 */ 

#include "app.h"
#include "ElementConfig.h"

ElementThermistor tank_thermistor = {
	TANK_NTC_PIN,
	TANK_NTC_RES, // We are going for 10 bit resolution.
	TANK_NTC_REF_TYPE, // We are using an external reference.
	TANK_NTC_REF_INDEX, // Use the index 1 reference.
	TANK_NTC_PRESCALER,
	TANK_NTC_SERIES_RESISTOR, // We have a 10K resistor on the voltage div circuit.
	TANK_NTC_LOWEST_TEMP, // The lowest temperature we will support is 0 C.
	TANK_NTC_HIGHEST_TEMP, // The highest temperature we will support is 600 C.
	TANK_NTC_NOMINAL_TEMP, // The nominal resistance is probably 25 C
	TANK_NTC_NOMINAL_RESISTANCE, // Probably around 100K
	TANK_NTC_BETA, // This is just a guess.
	0, // There is no current temp.
};

CMStateStruct cm_state = {
		.is_brewing = false,
		.brew_start_time = 0,
		.brew_end_time = 0,
		.sneak_a_cup_active = false,
		.sneak_start_time = 0,
		
	.underbody_active = false,
	.underbody_demo_id = 0,	
		
};