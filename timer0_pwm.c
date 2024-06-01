#include "timer0_pwm.h"
#include "avr_registers.h"
#include "gpio.h"


void PWM_Timer0_Start(uint8 duty_cycle)
{
	/* setting PWM OC0 pin as output pin */
	GPIO_setupPinDirection(TIMER0_PWM_PORT_ID,TIMER0_PWM_PIN_ID,PIN_OUTPUT);

	/* error checking as duty cycle should be:  0 <= duty cycle <= 100 */
	if(duty_cycle>100 || duty_cycle<0)
	{
		return;
	}

	/* clearing TCCR0 register */
	TCCR0_REG.Byte=0;
	if(duty_cycle == 0)
	{
		/* do nothing */
	}
	else	/* configuring Timer0 to operate with Fast PWM mode */
	{
		/* configuring Timer0 mode of operation */
		TCCR0_REG.Bits.WGM00_bit=1;
		TCCR0_REG.Bits.WGM01_bit=1;

		/* configuring PWM to non-inverting mode */
		TCCR0_REG.Bits.COM01_bit=1;

		/* configuring Timer0 prescaler */
		TCCR0_REG.Bits.CS01_bit=1;

		TCNT0_REG.Byte=0; /* clearing counter register */

		/* setting compare match value to given duty cycle */
		OCR0_REG.Byte=duty_cycle;
	}
}
