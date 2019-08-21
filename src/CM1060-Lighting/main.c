/*
 * CM1060-Lighting.c
 *
 * Created: 7/29/2019 10:50:18 AM
 * Author : 243400
 */ 

#include <avr/io.h>
#include <Morph.h>

#include <MorphConfig.h>
#include <MorphPWM.h>
#include <MorphADC.h>

#include <math.h>

#include <stdio.h>

#include <ElementConfig.h>
#include <ElementAnimationEngine.h>
#include <ElementDirectButton.h>

#include "app.h"


#include "ws2812b.h"
#include <util/delay.h>



//WS2812B LED light strip
#define LED_PIN     7
#define NUM_LEDS    25


//RGBs
#define RED_PIN		    11
#define GREEN_PIN	    12
#define BLUE_PIN		17

#define M_PI 3.14159265358979323846	/* pi */
#define PERIOD 5.0

#define RED_TIME_OFFSET    0
#define GREEN_TIME_OFFSET  PERIOD/3.0f * 1000
#define BLUE_TIME_OFFSET   (PERIOD/3.0f) * 2 * 1000


int main(void)
{
	// Initialize Morph
	MorphConfig_init();
	
	// Setup a timer for our clock
	MorphTime_init(0, 16);
	
	MorphPWM_start_pwm(LED_PIN);
	
	MorphPWM_start_pwm(11);
	MorphPWM_start_pwm(12);
	MorphPWM_start_pwm(17);

	ElementDirectButton_init();

	start_state();

	
	MorphTimeValue time = MorphTime_millis();

	MorphGPIO_set_pin_direction(19, Output);
	
	MorphADC_init_adc(23);
	MorphADC_set_reference(23, MorphADCExternalRef, 1);
	MorphADC_set_prescaler(23, 64);
	MorphADC_set_resolution(23, 10);
	
	MorphUART_setup_channel(0, 9600, 8, MorphNoParity, 1);

	float filtered_values[10] = {0};

	uint8_t current_filtered_light_index = 0;

    /* Replace with your application code */
    while (1) 
    {
		//time = MorphTime_millis();
		//
		loop_state();
		
		uint16_t reading = MorphADC_read(23);	
		uint16_t max_val = MorphADC_get_maximum_value(23);
		
		
		uint16_t light_reading = (int16_t)reading - 620 > 0 ? reading - 620 : 0;
		
		float volt_percent = light_reading/170.0f;

		filtered_values[current_filtered_light_index++] = volt_percent;

		if(current_filtered_light_index >= 10)
		{
			current_filtered_light_index = 0;
		}
		
		float filtered_value = 0;
		
		for(uint8_t i = 0; i < 10; i++)
		{
			
			filtered_value += filtered_values[i];
			
		}
		
		filtered_value /= 10.0f;
		
		cm_state.light_level = filtered_value;

		char str[12];
		sprintf(str, "%d", (uint16_t)(cm_state.light_level * 100.0f)); // str now contains "3"
		
		MorphUART_write_byte_buffer(0, &str, strlen(str) + 1);

		MorphUART_send_byte(0, '\n');
		MorphUART_send_byte(0, '\r');

		////_delay_ms(5000);
		////MorphPWM_set_pwm_duty_float(RED_PIN, 255);
		////_delay_ms(1000);
		////MorphPWM_set_pwm_duty_float(BLUE_PIN, 0x00);
		////MorphPWM_set_pwm_duty_float(RED_PIN, 0xFF);
		////_delay_ms(1000);
		////MorphTimeValue time = MorphTime_millis();
		//
		//
		////float red_val = ((cos(((time+RED_TIME_OFFSET)/1000.0f * M_PI)/PERIOD) + 1.0f) / 2.0f);
		////float green_val = ((cos(((time+GREEN_TIME_OFFSET)/1000.0f * M_PI)/PERIOD) + 1.0f) / 2.0f);
		////float blue_val = ((cos(((time+BLUE_TIME_OFFSET)/1000.0f * M_PI)/PERIOD) + 1.0f) / 2.0f);
		////
		////
		////MorphPWM_set_pwm_duty_float(RED_PIN, red_val);
		////MorphPWM_set_pwm_duty_float(GREEN_PIN, green_val);
		////MorphPWM_set_pwm_duty_float(BLUE_PIN, blue_val);
		////

    }
}

