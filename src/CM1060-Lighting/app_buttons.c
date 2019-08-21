/*
 * appButtons.c
 *
 * Created: 8/16/2019 11:41:21 AM
 *  Author: 245845
 */ 

#include "app_buttons.h"


void setUpButton()
{
	
	ElementDirectButton_init();
	ElementDirectButton_update();
	ElementDirectButton_register_button(programBtn, 8, High, PullNone);
	
}