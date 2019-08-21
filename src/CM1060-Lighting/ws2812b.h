/*
 * ws2812b.h
 *
 * Created: 7/31/2019 1:15:53 PM
 *  Author: 243400
 */ 


#ifndef WS2812B_H_
#define WS2812B_H_

#include <stdbool.h>



#define PIXELS 25//96*11 // Number of pixels in the string
 
// These values depend on which pin your string is connected to and what board you are using
// More info on how to find these at http://www.arduino.cc/en/Reference/PortManipulation
 
// These values are for digital pin 8 on an Arduino Yun or digital pin 12 on a DueMilinove
// Note that you could also include the DigitalWriteFast header file to not need to to this lookup.
 
#define PIXEL_PORT PORTD // Port of the pin the pixels are connected to
#define PIXEL_DDR DDRD // Port of the pin the pixels are connected to
#define PIXEL_BIT 7 // Bit of the pin the pixels are connected to
 
// These are the timing constraints taken mostly from the WS2812 datasheets
// These are chosen to be conservative and avoid problems rather than for maximum throughput 
 
#define T1H	900				// Width of a 1 bit in ns
#define T1L	600				// Width of a 1 bit in ns
 
#define T0H	400				// Width of a 0 bit in ns
#define T0L	900				// Width of a 0 bit in ns
 
#define RES 14000//7000			// Width of the low gap between bits to cause a frame to latch
 
// Here are some convenience defines for using nanoseconds specs to generate actual CPU delays
 
#define NS_PER_SEC (1000000000L) // Note that this has to be SIGNED since we want to be able to check for negative values of derivatives
 
#define CYCLES_PER_SEC (F_CPU)
 
#define NS_PER_CYCLE ( NS_PER_SEC / CYCLES_PER_SEC )
 
#define NS_TO_CYCLES(n) ( (n) / NS_PER_CYCLE )
 
#define DELAY_CYCLES(n) ( ((n) > 0) ? __builtin_avr_delay_cycles( n ) : __builtin_avr_delay_cycles( 0 ) ) // Make sure we never have a delay less than zero
 
 #define bitSet(reg, bit) ( reg |= 1 << bit)

 #define bitClear(reg, bit) ( reg &= ~(1 << bit))

 #define bitRead(reg, bit) ( (reg >> bit) & 0x1)
 
// Actually send a bit to the string. We turn off optimizations to make sure the compile does
// not reorder things and make it so the delay happens in the wrong place.
 
//void sendBit(bool) __attribute__ ((optimize(0)));
 
void sendBit( bool bitVal );
 
void sendByte( unsigned char byte );
 
 
void ledsetup();
 
void sendPixel( unsigned char r, unsigned char g , unsigned char b );
 
// Just wait long enough without sending any bots to cause the pixels to latch and display the last sent frame
 
void show();


#endif /* WS2812B_H_ */