#include "timer.h"
#include "avr_registers.h"
#include "common_macros.h"

void TIMER0_init(TIMER0_configType *config)
{

	TCCR0_REG.Byte = 0;

	TCCR0_REG.Bits.FOC0_bit = config -> PWM_mode;

	TCCR0_REG.Bits.WGM00_bit = GET_BIT(config ->mode, 0);
	TCCR0_REG.Bits.WGM01_bit = GET_BIT(config ->mode, 1);

	TCCR0_REG.Byte = (TCCR0_REG.Byte & 0x11001111) | ((config -> compare_mode) << 4);

	TCCR0_REG.Byte = (TCCR0_REG.Byte & 0x11111000) | (config -> prescaler);

	TCNT0_REG.Byte = config -> timerCounterRegister;

	OCR0_REG.Byte = config -> outputCompareRegister;

	switch(config -> interrupt_mask)
	{
	case TOIE0:
		TIMSK_REG.Bits.TOIE0_bit = 1;
		break;
	case OCIE0:
		TIMSK_REG.Bits.OCIE0_bit = 1;
		break;
	default:
		TIMSK_REG.Bits.TOIE0_bit = 0;
		TIMSK_REG.Bits.OCIE0_bit = 0;
	}
}
