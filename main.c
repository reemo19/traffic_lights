/*
 * main.c
 *
 *  Created on: Sep 22, 2023
 *      Author: hp
 */
#include "STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_interface.h"
#include "TIMER_TEST_interface.h"
#include"GIE.h"
#include "Seven_Segments.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

u8 seconds_counter=0;
ISR(TIMER0_OVF_vect)
{
	static u16 c=0,LED0=0;
	c++;
	if(c==3907){

		TCNT0=192;
	    seconds_counter++;
	    c=0;
	    LED0++;
	    if(LED0==1)
	    {
	    	DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_OUT);//G

	    	DIO_u8SetPinValue(DIO_PORTB,DIO_PIN0,DIO_PIN_OUT);
	    	DIO_u8SetPinValue(DIO_PORTD,DIO_PIN0,DIO_PIN_OUT);
	    	DIO_u8SetPinValue(DIO_PORTD,DIO_PIN3,DIO_PIN_OUT);
	    }
	    else if(LED0==11)
	    {
	    	seconds_counter=0;
	    	DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_IN);
	    	DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_OUT);//y

	    	DIO_u8SetPinValue(DIO_PORTD,DIO_PIN3,DIO_PIN_IN);//CLOSEred
	    	DIO_u8SetPinValue(DIO_PORTD,DIO_PIN4,DIO_PIN_OUT);//y
	    }
	    else if(LED0==16)
	    {
	    	seconds_counter=0;
	    	DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_IN);
	    	DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_OUT);

	    	DIO_u8SetPinValue(DIO_PORTD,DIO_PIN4,DIO_PIN_IN);
	    	DIO_u8SetPinValue(DIO_PORTD,DIO_PIN3,DIO_PIN_IN);
	    	DIO_u8SetPinValue(DIO_PORTD,DIO_PIN5,DIO_PIN_OUT);//G
	    }

	  else if(LED0==26)
	 	    {
	 	    	seconds_counter=0;
	 	    	DIO_u8SetPinValue(DIO_PORTD,DIO_PIN5,DIO_PIN_IN);
	 	    	DIO_u8SetPinValue(DIO_PORTD,DIO_PIN4,DIO_PIN_OUT);//y

	 	    	DIO_u8SetPinValue(DIO_PORTD,DIO_PIN0,DIO_PIN_IN);//close  red
	 	    	DIO_u8SetPinValue(DIO_PORTD,DIO_PIN1,DIO_PIN_OUT);//y
	 	    }
	 	    else if(LED0==31)
	 	    {
	 	    	seconds_counter=0;
	 	    	DIO_u8SetPinValue(DIO_PORTD,DIO_PIN4,DIO_PIN_IN);
	 	    	DIO_u8SetPinValue(DIO_PORTD,DIO_PIN3,DIO_PIN_OUT);

	 	    DIO_u8SetPinValue(DIO_PORTD,DIO_PIN1,DIO_PIN_IN);
	 	   	DIO_u8SetPinValue(DIO_PORTD,DIO_PIN0,DIO_PIN_IN);
	 	   	DIO_u8SetPinValue(DIO_PORTD,DIO_PIN2,DIO_PIN_OUT);//G
	 	    }
	  	  else if(LED0==41)
	  	 	    {
	  	 	    	seconds_counter=0;
	  	 	    	DIO_u8SetPinValue(DIO_PORTD,DIO_PIN2,DIO_PIN_IN);
	  	 	    	DIO_u8SetPinValue(DIO_PORTD,DIO_PIN1,DIO_PIN_OUT);//Y

	  	 	 	DIO_u8SetPinValue(DIO_PORTB,DIO_PIN0,DIO_PIN_IN);//close  red
	  	 	    	DIO_u8SetPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_OUT);//Y
	  	 	    }
	  	 	    else if(LED0==46)
	  	 	    {
	  	 	    	seconds_counter=0;
	  	 	    	DIO_u8SetPinValue(DIO_PORTD,DIO_PIN1,DIO_PIN_IN);
	  	 	    	DIO_u8SetPinValue(DIO_PORTD,DIO_PIN0,DIO_PIN_OUT);

	  	 	    	DIO_u8SetPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_IN);
	  	 	    	DIO_u8SetPinValue(DIO_PORTB,DIO_PIN0,DIO_PIN_IN);
	  	 	    	DIO_u8SetPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_OUT);//G
	  	 	    }

	  		  else if(LED0==56)
	  		 	    {
	  		 	    	seconds_counter=0;
	  		 	    	DIO_u8SetPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_IN);
	  		 	    	DIO_u8SetPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_OUT);//Y

	  		 	 	DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_IN);//close  red
	  		 	    	DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_OUT);//Y
	  		 	    }
	  		else if(LED0==61)
	  		 	    {
	  		 	    	seconds_counter=0;
	  		 	    	DIO_u8SetPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_IN);
	  		 	    	DIO_u8SetPinValue(DIO_PORTB,DIO_PIN0,DIO_PIN_OUT);

	  		 	    	DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_IN);
	  		 	    	DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_IN);

	  		 	    	DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_OUT);
	  		 	    	LED0=0;
	  		 	    }

	}
}


int main()
{
	DIO_u8SetPinDir(DIO_PORTC,DIO_PIN0,DIO_PIN_OUT);//7seg
	DIO_u8SetPinDir(DIO_PORTC,DIO_PIN1,DIO_PIN_OUT);//7seg
	DIO_u8SetPinDir(DIO_PORTC,DIO_PIN2,DIO_PIN_OUT);//7seg
	DIO_u8SetPinDir(DIO_PORTC,DIO_PIN3,DIO_PIN_OUT);//7seg
	DIO_u8SetPinDir(DIO_PORTC,DIO_PIN4,DIO_PIN_OUT);//7seg
	DIO_u8SetPinDir(DIO_PORTC,DIO_PIN5,DIO_PIN_OUT);//7seg
	DIO_u8SetPinDir(DIO_PORTC,DIO_PIN6,DIO_PIN_OUT);//7seg


	DIO_u8SetPinDir(DIO_PORTD,DIO_PIN6,DIO_PIN_OUT);//7seg
	DIO_u8SetPinDir(DIO_PORTD,DIO_PIN7,DIO_PIN_OUT);//7seg


	DIO_u8SetPinDir(DIO_PORTA,DIO_PIN0,DIO_PIN_OUT);
	DIO_u8SetPinDir(DIO_PORTA,DIO_PIN1,DIO_PIN_OUT);
	DIO_u8SetPinDir(DIO_PORTA,DIO_PIN2,DIO_PIN_OUT);

	DIO_u8SetPinDir(DIO_PORTB,DIO_PIN0,DIO_PIN_OUT);
	DIO_u8SetPinDir(DIO_PORTB,DIO_PIN1,DIO_PIN_OUT);
	DIO_u8SetPinDir(DIO_PORTB,DIO_PIN2,DIO_PIN_OUT);

	DIO_u8SetPinDir(DIO_PORTD,DIO_PIN3,DIO_PIN_OUT);
	DIO_u8SetPinDir(DIO_PORTD,DIO_PIN4,DIO_PIN_OUT);
	DIO_u8SetPinDir(DIO_PORTD,DIO_PIN5,DIO_PIN_OUT);

	DIO_u8SetPinDir(DIO_PORTD,DIO_PIN0,DIO_PIN_OUT);
	DIO_u8SetPinDir(DIO_PORTD,DIO_PIN1,DIO_PIN_OUT);
	DIO_u8SetPinDir(DIO_PORTD,DIO_PIN2,DIO_PIN_OUT);

	TIMER0_voidOfInit();
	TIMER0_voidPreLoadValue(192);
	GIE_voidEnable();
	while(1)
	{

		SET_BIT(PORTD,PIN6);
		CLEAR_BIT(PORTD,PIN7);
		WriteSegment(seconds_counter%10);
		_delay_ms(5);
		SET_BIT(PORTD,PIN7);
		CLEAR_BIT(PORTD,PIN6);
		WriteSegment(seconds_counter/10);
		_delay_ms(5);
	}
}
