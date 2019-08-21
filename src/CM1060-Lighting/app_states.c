/*
 * app_states.c
 *
 * Created: 7/29/2019 11:10:29 AM
 *  Author: 243400
 */ 


#include "app_states.h"
#include "app_states.h"

#include "app_animations.h"

#include <MorphPWM.h>
#include <MorphGPIO.h>
#include <MorphTime.h>
 
bool switched = false;

void start_state()
{
	// Start and initialize everything here.
	
	//ElementAnimationEngine_push_animation(&lights_buffer, &brewProgressAnim);
	ElementAnimationEngine_add_buffer(&lights_buffer);
	
	
	
	ElementAnimationEngine_remove_all_animations(&lights_buffer);
	ElementAnimationEngine_push_animation(&lights_buffer, &nightLightBlueAnim);
	//ElementAnimationEngine_push_animation(&lights_buffer, &sneakCupAnim);
	
	//ElementAnimationEngine_push_animation(&lights_buffer, &softFlashAnim);
	
	ElementDirectButton_init();
	
	ElementDirectButton_register_button(SNEAK_A_CUP_SWITCH_ID, SNEAK_A_CUP_SWITCH_PIN, Low, PullHigh);
	ElementDirectButton_register_button(LID_SWITCH_ID, LID_SWITCH_PIN, Low, PullHigh);
	ElementDirectButton_register_button(AMBIENT_SWITCH_ID, AMBIENT_SWITCH_PIN, Low, PullHigh);
	ElementDirectButton_register_button(DEMO_SWITCH_ID, DEMO_SWITCH_PIN, Low, PullHigh);	
	
	MorphPWM_set_pwm_duty_float(RED_PIN, 0);
	MorphPWM_set_pwm_duty_float(GREEN_PIN, 0);
	MorphPWM_set_pwm_duty_float(BLUE_PIN, 0);


	//ElementDirectButton_register_callback(&sneak_a_cup_start, DEMO_SWITCH_ID, ElementButtonEventDown);

	//ElementDirectButton_register_callback(&sneak_a_cup_end, DEMO_SWITCH_ID, ElementButtonEventUp);

	ElementDirectButton_register_callback(&start_brew_demo, DEMO_SWITCH_ID, ElementButtonEventPress);

	ElementDirectButton_register_callback(&sneak_a_cup_start, SNEAK_A_CUP_SWITCH_ID, ElementButtonEventUp);
	ElementDirectButton_register_callback(&sneak_a_cup_end, SNEAK_A_CUP_SWITCH_ID, ElementButtonEventDown);
	
	ledsetup();		
}

void test_state()
{
//	ElementAnimationEngine_remove_all_animations(&lights_buffer);
//	ElementAnimationEngine_push_animation(&lights_buffer, &nightLightBlueAnim);
//    ElementAnimationEngine_add_buffer(&lights_buffer);
}

uint8_t loop_count = 0;

void loop_state() //can't get it to run in real-time
{
	// Update anything we need to here.
	
	//if(MorphTime_millis() > 30 && !switched)
	//{
		//ElementAnimationEngine_remove_animation(&lights_buffer, 0x0);
	////    ElementAnimationEngine_remove_all_animations(&lights_buffer);
		//ElementAnimationEngine_push_animation(&lights_buffer, &second_anim);
		//ElementAnimationEngine_add_buffer(&lights_buffer);
		////ledsetup();
		//switched = true;
	//}
	//
	//if(MorphTime_millis() > 30 && !switched)
	//{
		//ElementAnimationEngine_remove_animation(&lights_buffer, 0x0);
		//ElementAnimationEngine_push_animation(&lights_buffer, &brewProgAnim);
		//switched = true;
		//ElementAnimationEngine_add_buffer(&lights_buffer);
		//
		//ledsetup();
	//}
	
	//_delay_ms(5000);
	
	//if(MorphTime_millis() > 6500 && !switched)
	//{
	//	ElementAnimationEngine_remove_animation(&lights_buffer, 0x3);
	//	
	//	ElementAnimationEngine_push_animation(&lights_buffer, &brewProgressAnim);
	//
	//	//ElementAnimationEngine_add_buffer(&lights_buffer);
	//	switched = true;
	//	//ledsetup();
	//}
	//
	//if(MorphTime_millis() > 10000 && switched)
	//{
	//	ElementAnimationEngine_remove_animation(&lights_buffer, 0x3);
	//	ElementAnimationEngine_push_animation(&lights_buffer, &second_anim);
	//	switched = true;
	//}
	loop_count++;
	ElementAnimationEngine_update();
	ElementDirectButton_update();
}

void start_brew_demo()
{
	
	cm_state.is_brewing = true;
	cm_state.brew_start_time = MorphTime_millis();

	ElementAnimationEngine_push_animation(&lights_buffer, &brewProgressAnim);
	
	ElementDirectButton_register_callback(&end_brew_demo, DEMO_SWITCH_ID, ElementButtonEventPress);
	
}

void end_brew_demo()
{

	ElementAnimationEngine_remove_animation(&lights_buffer, brewProgressAnim.animation_id);

	cm_state.is_brewing = false;

	cm_state.brew_end_time = MorphTime_millis();

	ElementAnimationEngine_push_animation(&lights_buffer, &softFlashAnim);
	
	ElementDirectButton_register_callback(&underbody_demo_advance, DEMO_SWITCH_ID, ElementButtonEventPress);
	
}

void underbody_demo_advance()
{
	
	if(cm_state.underbody_demo_id == 6)
	{

		ElementDirectButton_register_callback(&start_brew_demo, DEMO_SWITCH_ID, ElementButtonEventPress);
		
		cm_state.underbody_demo_id = 0;
		
	}	
	else
	{
		
		cm_state.underbody_demo_id ++;
		
	}
	
}

void sneak_a_cup_start()
{

	if(cm_state.is_brewing)
	{

		cm_state.sneak_a_cup_active = true;
		cm_state.sneak_start_time = MorphTime_millis();

		ElementAnimationEngine_remove_animation(&lights_buffer, brewProgressAnim.animation_id);

		ElementAnimationEngine_push_animation(&lights_buffer, &sneakCupAnim);

		MorphGPIO_set_pin_value(19, High);
		
		
	}
	
}

void sneak_a_cup_end()
{
	
	cm_state.sneak_a_cup_active = false;

	ElementAnimationEngine_remove_animation(&lights_buffer, sneakCupAnim.animation_id);

	ElementAnimationEngine_push_animation(&lights_buffer, &brewProgressAnim);

	MorphGPIO_set_pin_value(19, Low);
	
	
}
