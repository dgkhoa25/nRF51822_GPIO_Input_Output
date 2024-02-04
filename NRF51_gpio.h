#ifndef __NRF51_GPIO_H_
#define __NRF51_GPIO_H_

#include <stdint.h>

typedef void (*nrf51_input_callback_t)(uint32_t pin);

void nrf51_output_create(uint32_t pin);
void nrf51_output_set_level(uint32_t pin, int level);
void nrf51_output_toggle(uint32_t pin);
void nrf51_input_in_create(uint32_t pin);
void nrf51_input_setCallback(void *cb);
#endif
