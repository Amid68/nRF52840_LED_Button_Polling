/*
 * @file leds.h
 * @brief Header file for LED initialization and control functions.
 * 
 * @author Ameed Othman	
 * @date 2024-11-29
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#ifndef __LEDS_H__
#define __LEDS_H__

#include <stdbool.h>

int leds_init(void);
void led_set_state(int led_id, bool state);
void led_toggle(int led_id);

#endif 
