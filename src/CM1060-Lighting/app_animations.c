/*
* app_animations.c
*
* Created: 7/29/2019 11:10:14 AM
*  Author: 243400
*/

#include "app_animations.h"

#include "app.h"

ElementAnimationBufferConfigStruct lights_buffer = {
	0x1,				// Buffer ID is 1.
	NULL,	// The pointer to the buffer space.
	NULL,				// This is the write buffer.
	// Will be initialized when passed to animation engine.
	NULL,				// This is the read buffer.
	// Will be initialized when passed to animation engine.
	2,					// We have 2 buffers.
	1,					// The bit depth of this buffer is 1.
	12,					// Every buffer is made of 12 bytes.
	{	// This buffer is for a 8 x 12 display.
		8, 12
	},
	{
		NULL
	},
	0					// We have 0 animations running on this buffer currently.
};


// This animation displays the amount to brew (drip or kcup)
enum ElementAnimationEngineStatus display_general()
{
	//ledsetup();
	//
	//uint8_t r = 0x00, g = 0x00, b = 0x00;
	//
	///* Replace with your application code */
	//while (1)
	//{
	//for(uint8_t i = 0; i < 25; i++){
	//sendPixel(r, g, b);
	//}
	//
	//
	//show();
	//
	//if(b == 0 && r != 0xFF)
	//r++;
	//else if(r == 0xFF && b != 0xFF)
	//b++;
	//else if(b == 0xFF && r != 0x00)
	//r--;
	//else if(r == 0x00 && g != 0xFF)
	//g++;
	//else if(g == 0xFF && b != 0x00)
	//b--;
	//
	//_delay_ms(16);
	//}
	//
	//return Animation_Engine_Success;
	
	for(uint8_t i = 0; i < 15; i++){
		sendPixel(30, 200, 40);
	}
	
	for(uint8_t i = 15; i < 25; i++){
		sendPixel(200, 0, 100);
	}
	show();
	return Animation_Engine_Success;
}

enum ElementAnimationEngineStatus mysample()
{
	// Place your animation code here.
	for(uint8_t i = 0; i < 15; i++){
		sendPixel(200, 2, 45);
	}
	
	for(uint8_t i = 16; i < 25; i++){
		sendPixel(56, 100, 10);
	}
	show();
	return Animation_Engine_Success;
	
}

enum ElementAnimationEngineStatus coffeeProgress()
{
	uint8_t r = 0x00, g = 0x00, b = 0x00, blank = 0x00;
	MorphTimeValue cur_time = MorphTime_millis() - cm_state.brew_start_time;
	
	if(cur_time >= 0 && cur_time < BREW_DURATION && cm_state.is_brewing)
	{
		
		float percent_done = ((double)cur_time/(float)(BREW_DURATION));
		
		g = 0xFF * percent_done;
		b = 0xFF * (1.0f - percent_done);
		
		uint8_t led_count = (float)NUM_LEDS * (1.0f - percent_done);
		
		for(uint8_t i = 0; i < led_count; i++){
			sendPixel(0x20, 0x20, 0x20);
		}
		for(uint8_t i = 0; i < NUM_LEDS - led_count; i++){
			sendPixel(r, g, b);
		}
		
		show();
	}
	else
	{
		return Animation_Engine_Animation_Complete;
	}
	
	
	//uint8_t r = 0xFF, g = 0x00, b = 0x00, blank = 0x00;
	//
//
	//
	//MorphTimeValue cur_time = MorphTime_millis() - cm_state.brew_start_time;
	//
	//if(cur_time >= 0 && cur_time < BREW_DURATION && cm_state.is_brewing)
	//{
		//
		//float percent_done = ((double)cur_time/(float)(BREW_DURATION));
		//
		//r = 0xFF * percent_done;
		//g = 0xFF * (1.0f - percent_done);
		//
		//uint8_t led_count = (float)NUM_LEDS * (1.0f - percent_done);
		//
		//for(uint8_t i = 0; i < led_count; i++){
			//sendPixel(r, g, b);
		//}
		//for(uint8_t i = 0; i < NUM_LEDS - led_count; i++){
			//sendPixel(0xFF, 0xFF, 0xFF);
		//}
		//
		//show();
	//}
	//else
	//{
		//return Animation_Engine_Animation_Complete;
	//}
	
	//uint8_t r = 0x00, g = 0x00, b = 0x00;
	//
	//MorphTimeValue cur_time = MorphTime_millis() - cm_state.brew_start_time;
	//
	//if(cur_time >= 0 && cm_state.is_brewing)
	//{
		//
		//float percent_done = ((double)cur_time/(float)(BREW_DURATION));
		//
		//g = 0xFF * percent_done;
		//r = 0xFF * (1.0f - percent_done);
		//
		//
		//int prog = ((double)cur_time /(float)BREW_DURATION) * NUM_LEDS;
		//
		//for(uint8_t i = 0; i < prog; i++){
			//sendPixel(r, g, b);
		//}
		//
		//show();
	//}
	//else
	//{
		//return Animation_Engine_Animation_Complete;
	//}
	
	//uint8_t r = 0x00, g = 0x00, b = 0x00;
		//
	//MorphTimeValue cur_time = MorphTime_millis() - cm_state.brew_start_time;
	//
	//if(cur_time >= 0 && cm_state.is_brewing)
	//{
		//
		//float percent_done = ((double)cur_time/(float)(BREW_DURATION));
		//
		//g = 0xFF * percent_done;
		//r = 0xFF * (1.0f - percent_done);
				//
		//for(uint8_t i = 0; i < NUM_LEDS; i++){
			//sendPixel(r, g, b);
		//}
		//
		//show();
	//}
	//else
	//{
		//return Animation_Engine_Animation_Complete;
	//}
	
	
	
	//MorphTimeValue cur_time = MorphTime_millis() - cm_state.brew_start_time;
	//float percent_done = ((double)cur_time/(float)(SNEAK_DURATION));
	//
	//uint8_t r = 0x00, g = 0x00, b = 0x00;
	//for(uint8_t i = 0; i < NUM_LEDS; i++){
	//	sendPixel(r, g, b);
	//}
	//show();
	//r = 0xFF, g = 0x00, b = 0x00;
	//uint8_t i = 0;
	//uint8_t prog = 0;
	//while(prog < NUM_LEDS){
	//	for(uint8_t i = 0; i < prog; i++){
	//		sendPixel(r, g, b);
	//	}
	//	show();
	//	r = r - (FULL_COLOR / NUM_LEDS);
	//	b = b + ((FULL_COLOR / NUM_LEDS) / 2);
	//	g = g + (FULL_COLOR / NUM_LEDS);
	//	prog++;
	//	_delay_ms(BREW_PROG_DELAY);
	//}
	////turn all lights green
	//r = 0x00, g = 0xFF, b = 0x00;
	//for(uint8_t i = 0; i < NUM_LEDS; i++){
	//	sendPixel(r, g, b);
	//}
	//show();
	////perform soft flashing to alert user that brew cycle is complete
	//for(int i = 0; i < NUM_FLASHES; i++){
	//	while(g > 0){
	//		g--;
	//		for(uint8_t i = 0; i < NUM_LEDS; i++){
	//			sendPixel(r, g, b);
	//		}
	//		show();
	//		_delay_ms(FLASH_DELAY);
	//	}
	//	while(g < 0xFF){
	//		g++;
	//		for(uint8_t i = 0; i < NUM_LEDS; i++){
	//			sendPixel(r, g, b);
	//		}
	//		show();
	//		_delay_ms(FLASH_DELAY);
	//	}
	//}
	//return Animation_Engine_Animation_Complete;
}

enum ElementAnimationEngineStatus softFlash()
{

	MorphTimeValue cur_time = MorphTime_millis() - cm_state.brew_end_time;
	
	float flash_amount = ((cos(((cur_time)/1000.0f * M_PI)/1.0) + 1.0f) / 2.0f);

	if(cur_time >= BREW_DONE_DURATION)
	{
		
		for(uint8_t i = 0; i < NUM_LEDS; i++){
			sendPixel(0, 0, 0);
		}
	
		return Animation_Engine_Animation_Complete;
	}
	else
	{
		for(uint8_t i = 0; i < NUM_LEDS; i++){
			sendPixel(0, 0x10 + (0xEF * flash_amount), 0);
		}
			
	}
	
	show();
	
	return Animation_Engine_Success;
	
};

enum ElementAnimationEngineStatus sneakCupTimer(){
	//uint8_t r = 0x00, g = 0xFF, b = 0x00, blank = 0x00;
	//
//
	//
	//MorphTimeValue cur_time = MorphTime_millis() - cm_state.sneak_start_time;
	//
	//if(cur_time >= 0 && cur_time < SNEAK_DURATION && cm_state.sneak_a_cup_active)
	//{
		//
		//float percent_done = ((double)cur_time/(float)(SNEAK_DURATION));
		//
		//r = 0xFF * percent_done;
		//g = 0xFF * (1.0f - percent_done);
		//
		//uint8_t led_count = (float)NUM_LEDS * (1.0f - percent_done);
		//
		//for(uint8_t i = 0; i < led_count; i++){
			//sendPixel(0x00, 0xFF, 0x00);
		//}
		//for(uint8_t i = 0; i < NUM_LEDS - led_count; i++){
			//sendPixel(0xFF, 0x00, 0x00);
		//}
		//
		//show();
	//}
	//else
	//{
		//return Animation_Engine_Animation_Complete;
	//}
	
	
	
	uint8_t r = 0x00, g = 0xFF, b = 0x00, blank = 0x00;
	

	
	MorphTimeValue cur_time = MorphTime_millis() - cm_state.sneak_start_time;
	
	if(cur_time >= 0 && cur_time < SNEAK_DURATION && cm_state.sneak_a_cup_active)
	{
		
		float percent_done = ((double)cur_time/(float)(SNEAK_DURATION));
		
		r = 0xFF * percent_done;
		g = 0xFF * (1.0f - percent_done);
		
		uint8_t led_count = (float)NUM_LEDS * (1.0f - percent_done);
		
		for(uint8_t i = 0; i < led_count; i++){
			sendPixel(r, g, b);
		}
		for(uint8_t i = 0; i < NUM_LEDS - led_count; i++){
			sendPixel(0x20, 0x20, 0x20);
		}		
		
		show();
	}
	else
	{
		return Animation_Engine_Animation_Complete;
	}
	
	
	//uint8_t i = 0;
	//uint8_t prog = NUM_LEDS;
	//while(prog > 0){
		//for(uint8_t i = 0; i < prog; i++){
			//sendPixel(r, g, b);
		//}
		//for(uint8_t i = prog; i < NUM_LEDS; i++){
			//sendPixel(blank, blank, blank);
		//}
		//show();
		//r = r + (FULL_COLOR / NUM_LEDS);
		////b = b + 5;
		//g = g - (FULL_COLOR / NUM_LEDS);
		//prog--;
		//_delay_ms(SNEAK_TIMER_TICK);
	//}
	////turn off all the lights (because the time is up)
	//for(uint8_t i = 0; i < NUM_LEDS; i++){
		//sendPixel(blank, blank, blank);
	//}
	return Animation_Engine_Success;
}
enum ElementAnimationEngineStatus nightLightBlue()
{
					
	if(cm_state.light_level > 0.5)
	{
	
		float pwm_intensity = (cm_state.light_level - 0.5f) / 0.5f;
	
		switch(cm_state.underbody_demo_id)
		{
			
			case 0:
				
				// White
				
				MorphPWM_set_pwm_duty_float(RED_PIN, pwm_intensity );
				MorphPWM_set_pwm_duty_float(GREEN_PIN, pwm_intensity );
				MorphPWM_set_pwm_duty_float(BLUE_PIN, pwm_intensity );

			break;
	
			case 1:

				// Red

				MorphPWM_set_pwm_duty_float(RED_PIN, pwm_intensity );
				MorphPWM_set_pwm_duty_float(GREEN_PIN, 0);
				MorphPWM_set_pwm_duty_float(BLUE_PIN, 0);

			break;
			
			case 2:
					
				// Green					
					
				MorphPWM_set_pwm_duty_float(RED_PIN, 0 );
				MorphPWM_set_pwm_duty_float(GREEN_PIN, pwm_intensity );
				MorphPWM_set_pwm_duty_float(BLUE_PIN, 0);
					
			break;					
						
			case 3:

				// Blue

				MorphPWM_set_pwm_duty_float(RED_PIN, 0);
				MorphPWM_set_pwm_duty_float(GREEN_PIN, 0 );
				MorphPWM_set_pwm_duty_float(BLUE_PIN, pwm_intensity );

					
			break;
			
								
									
			case 4:

				// Yellow

				MorphPWM_set_pwm_duty_float(RED_PIN, pwm_intensity );
				MorphPWM_set_pwm_duty_float(GREEN_PIN, pwm_intensity );
				MorphPWM_set_pwm_duty_float(BLUE_PIN, 0 );

			
			break;			
												
			case 5:			
			
				// Cyan
			
				MorphPWM_set_pwm_duty_float(RED_PIN, 0);
				MorphPWM_set_pwm_duty_float(GREEN_PIN, pwm_intensity);
				MorphPWM_set_pwm_duty_float(BLUE_PIN, pwm_intensity);			
			
			case 6:
			default:
			
				// Magenta
				
				MorphPWM_set_pwm_duty_float(RED_PIN, pwm_intensity);
				MorphPWM_set_pwm_duty_float(GREEN_PIN, 0);
				MorphPWM_set_pwm_duty_float(BLUE_PIN, pwm_intensity);
				
			
			break;
			
														
			
		}
	

	}
	else
	{
		
		MorphPWM_set_pwm_duty_float(RED_PIN, 0);
		MorphPWM_set_pwm_duty_float(GREEN_PIN, 0);
		MorphPWM_set_pwm_duty_float(BLUE_PIN, 0);		
		
	}
	
	
	//while (1)
	//{
	//MorphTimeValue time = MorphTime_millis();
	//
	//float red_val = ((cos(((time+RED_TIME_OFFSET)/1000.0f * M_PI)/PERIOD) + 1.0f) / 2.0f);
	//float green_val = ((cos(((time+GREEN_TIME_OFFSET)/1000.0f * M_PI)/PERIOD) + 1.0f) / 2.0f);
	//float blue_val = ((cos(((time+BLUE_TIME_OFFSET)/1000.0f * M_PI)/PERIOD) + 1.0f) / 2.0f);
	//
	//MorphPWM_set_pwm_duty_float(RED_PIN, red_val);
	//MorphPWM_set_pwm_duty_float(GREEN_PIN, green_val);
	//MorphPWM_set_pwm_duty_float(BLUE_PIN, blue_val);
	
	//MorphPWM_set_pwm_duty_float(BLUE_PIN, 0x00);
	//MorphPWM_set_pwm_duty_float(RED_PIN, 0xFF);
	//_delay_ms(1000);
	//MorphPWM_set_pwm_duty_float(BLUE_PIN, 0x00);
	//MorphPWM_set_pwm_duty_float(RED_PIN, 0xFF);
	//_delay_ms(1000);
	//}
	
	//MorphTimeValue time = MorphTime_millis();
	//float red_val = ((cos(((time+RED_TIME_OFFSET)/1000.0f * M_PI)/PERIOD) + 1.0f) / 2.0f);
	//float green_val = ((cos(((time+GREEN_TIME_OFFSET)/1000.0f * M_PI)/PERIOD) + 1.0f) / 2.0f);
	//float blue_val = ((cos(((time+BLUE_TIME_OFFSET)/1000.0f * M_PI)/PERIOD) + 1.0f) / 2.0f);
	//
	//time = MorphTime_millis();
	//
//
	//red_val = ((cos(((time+RED_TIME_OFFSET)/1000.0f * M_PI)/PERIOD) + 1.0f) / 2.0f);
	//green_val = ((cos(((time+GREEN_TIME_OFFSET)/1000.0f * M_PI)/PERIOD) + 1.0f) / 2.0f);
	//blue_val = ((cos(((time+BLUE_TIME_OFFSET)/1000.0f * M_PI)/PERIOD) + 1.0f) / 2.0f);
	
	
	//MorphPWM_set_pwm_duty_float(RED_PIN, red_val);
	//MorphPWM_set_pwm_duty_float(GREEN_PIN, green_val);
	//MorphPWM_set_pwm_duty_float(BLUE_PIN, blue_val);



	return Animation_Engine_Success;
}