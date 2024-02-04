#include <stdbool.h>
#include <stdint.h>
#include "nrf_delay.h"
#include "boards.h"
#include "NRF51_gpio.h"

void nrf51_input_in_callback(uint32_t pin)
{
	switch (pin)
	{
		case BUTTON_1:
		{
			nrf51_output_toggle(LED_1);
			break;
		}
		case BUTTON_2:
		{
			nrf51_output_toggle(LED_2);
			break;
		}
		case BUTTON_3:
		{
			nrf51_output_toggle(LED_3);
			break;
		}
		case BUTTON_4:
		{
			nrf51_output_toggle(LED_4);
			break;
		}
		default:
		{
			break;
		}
	}
}


int main(void)
{
	nrf51_input_setCallback(nrf51_input_in_callback);
	nrf51_input_in_create(BUTTON_1);
	nrf51_input_in_create(BUTTON_2);
	nrf51_input_in_create(BUTTON_3);
	nrf51_input_in_create(BUTTON_4);
	
	nrf51_output_create(LED_1);
	nrf51_output_set_level(LED_1, 0);
	nrf51_output_create(LED_2);
	nrf51_output_set_level(LED_2, 0);
	nrf51_output_create(LED_3);
	nrf51_output_set_level(LED_3, 0);
	nrf51_output_create(LED_4);
	nrf51_output_set_level(LED_4, 0);
	
	while (true)
	{
		
//		nrf51_output_set_level(LED_4, 0);
//		nrf_delay_ms(1000);
//		nrf51_output_set_level(LED_4, 1);
//		nrf_delay_ms(1000);
	}
}

