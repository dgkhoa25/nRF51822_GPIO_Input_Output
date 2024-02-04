#include "NRF51_gpio.h"
#include "nrf_gpio.h"
#include "nrf_drv_gpiote.h"

static nrf51_input_callback_t nrf51_input_callback = NULL;

void nrf51_output_create(uint32_t pin)
{
	nrf_gpio_cfg_output(pin);
}

void nrf51_output_set_level(uint32_t pin, int level)
{
	if (level)
	{
		nrf_gpio_pin_set(pin);
	}
	else
	{
		nrf_gpio_pin_clear(pin);
	}
}

void nrf51_output_toggle(uint32_t pin)
{
	nrf_gpio_pin_toggle(pin);
}

static void in_pin_handler(nrf_drv_gpiote_pin_t pin, nrf_gpiote_polarity_t action)
{
	if(action == NRF_GPIOTE_POLARITY_HITOLO)
	{
		nrf51_input_callback(pin);
	}
}


void nrf51_input_in_create(uint32_t pin)
{
	if (!nrf_drv_gpiote_is_init())
	{
		int err_code = nrf_drv_gpiote_init();
		APP_ERROR_CHECK(err_code);
	}
  
	nrf_drv_gpiote_in_config_t in_config = GPIOTE_CONFIG_IN_SENSE_HITOLO(false);
	in_config.pull = NRF_GPIO_PIN_PULLUP;
	
	
	int err_code = nrf_drv_gpiote_in_init(pin, &in_config, in_pin_handler);
	APP_ERROR_CHECK(err_code);
	nrf_drv_gpiote_in_event_enable(pin, true);
}

void nrf51_input_setCallback(void *cb)
{
	if (cb != NULL)
	{
		nrf51_input_callback = (nrf51_input_callback_t)cb;
	}
}
