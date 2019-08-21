/*
 * ws2812b-custom-driver.c
 *
 * Created: 7/31/2019 1:15:03 PM
 * Author : 243400
 */ 

#include <avr/io.h>
#include "ws2812b.h"

#include <util/delay.h>

int main(void)
{
	ledsetup();
	
	uint8_t r = 0x00, g = 0x00, b = 0x00;
	
    /* Replace with your application code */
    while (1) 
    {
		
		for(uint8_t i = 0; i < 25; i++)
		{

			sendPixel(r, g, b);			
			
		}
	

	
		show();
		
		if(b == 0 && r != 0xFF)
			r++;
		else if(r == 0xFF && b != 0xFF)
			b++;
		else if(b == 0xFF && r != 0x00)
			r--;
		else if(r == 0x00 && g != 0xFF)
			g++;
		else if(g == 0xFF && b != 0x00)
			b--;
		
		
		_delay_ms(16);
		
    }
}

