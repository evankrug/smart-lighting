/*
 * analog-rgb-spike.c
 *
 * Created: 8/1/2019 11:19:58 AM
 * Author : 243400
 */ 

#include <avr/io.h>

#include <MorphConfig.h>
#include <MorphPWM.h>

#include <math.h>

#define PERIOD 5.0

#define RED_TIME_OFFSET    0
#define GREEN_TIME_OFFSET  PERIOD/3.0f * 1000
#define BLUE_TIME_OFFSET   (PERIOD/3.0f) * 2 * 1000

#define RED_PIN		    17
#define GREEN_PIN	    12
#define BLUE_PIN		11

int main(void)
{

	MorphConfig_init();

	MorphTime_init(0, 16);

	MorphPWM_start_pwm(11);
	MorphPWM_start_pwm(12);
	MorphPWM_start_pwm(17);

    /* Replace with your application code */
    while (1) 
    {
		
		MorphTimeValue time = MorphTime_millis();
		
		//float val = (time % 1000) / 1000.0f;
		
		float red_val = ((cos(((time+RED_TIME_OFFSET)/1000.0f * M_PI)/PERIOD) + 1.0f) / 2.0f);
		float green_val = ((cos(((time+GREEN_TIME_OFFSET)/1000.0f * M_PI)/PERIOD) + 1.0f) / 2.0f);
		float blue_val = ((cos(((time+BLUE_TIME_OFFSET)/1000.0f * M_PI)/PERIOD) + 1.0f) / 2.0f);
		

		MorphPWM_set_pwm_duty_float(RED_PIN, red_val);
		MorphPWM_set_pwm_duty_float(GREEN_PIN, green_val);
		MorphPWM_set_pwm_duty_float(BLUE_PIN, blue_val);
		
    }
}

