/*
 * @file leds.c
 * @brief Implementation of LED initialization and control functions.
 * 
 * @author Ameed Othman	
 * @date 2024-11-29
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include "leds.h"
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/gpio.h>

// Define LED nodes
#define LED0_NODE DT_ALIAS(led0)
#define LED1_NODE DT_ALIAS(led1)
#define LED2_NODE DT_ALIAS(led2)

// Get LED specifications
static const struct gpio_dt_spec led0 = GPIO_DT_SPEC_GET_OR(LED0_NODE, gpios, {0});
static const struct gpio_dt_spec led1 = GPIO_DT_SPEC_GET_OR(LED1_NODE, gpios, {0});
static const struct gpio_dt_spec led2 = GPIO_DT_SPEC_GET_OR(LED2_NODE, gpios, {0});

// Array of LED specifications
static const struct gpio_dt_spec leds[] = {
    led0,
    led1,
    led2
};

#define NUM_LEDS (sizeof(leds) / sizeof(leds[0]))

// Array to keep track of LED states
static bool led_states[NUM_LEDS] = {false};

int leds_init(void)
{
    int ret;
    for (int i = 0; i < NUM_LEDS; i++) {
        if (!device_is_ready(leds[i].port)) {
            return -1;
        }
        ret = gpio_pin_configure_dt(&leds[i], GPIO_OUTPUT_INACTIVE);
        if (ret < 0) {
            return ret;
        }
        led_states[i] = false;
    }
    return 0;
}

void led_set_state(int led_id, bool state)
{
    if (led_id < 0 || led_id >= NUM_LEDS) {
        return;
    }
    gpio_pin_set_dt(&leds[led_id], state);
    led_states[led_id] = state;
}

void led_toggle(int led_id)
{
    if (led_id < 0 || led_id >= NUM_LEDS) {
        return;
    }
    led_states[led_id] = !led_states[led_id];
    gpio_pin_set_dt(&leds[led_id], led_states[led_id]);
}
