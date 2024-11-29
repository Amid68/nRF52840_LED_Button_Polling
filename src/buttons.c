/*
 * @file buttons.c
 * @brief Implementation of button initialization and state retrieval functions.
 * 
 * @author Ameed Othman	
 * @date 2024-11-29
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include "buttons.h"
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/gpio.h>

// Define button nodes
#define SW0_NODE DT_ALIAS(sw0)
#define SW1_NODE DT_ALIAS(sw1)
#define SW2_NODE DT_ALIAS(sw2)

// Get button specifications
static const struct gpio_dt_spec button0 = GPIO_DT_SPEC_GET_OR(SW0_NODE, gpios, {0});
static const struct gpio_dt_spec button1 = GPIO_DT_SPEC_GET_OR(SW1_NODE, gpios, {0});
static const struct gpio_dt_spec button2 = GPIO_DT_SPEC_GET_OR(SW2_NODE, gpios, {0});

// Array of button specifications
static const struct gpio_dt_spec buttons[] = {
    button0,
    button1,
    button2
};

#define NUM_BUTTONS (sizeof(buttons) / sizeof(buttons[0]))

int buttons_init(void)
{
    int ret;
    for (int i = 0; i < NUM_BUTTONS; i++) {
        if (!device_is_ready(buttons[i].port)) {
            return -1;
        }
        ret = gpio_pin_configure_dt(&buttons[i], GPIO_INPUT);
        if (ret < 0) {
            return ret;
        }
    }
    return 0;
}

bool button_get_state(int button_id)
{
    if (button_id < 0 || button_id >= NUM_BUTTONS) {
        return false;
    }
    return gpio_pin_get_dt(&buttons[button_id]);
}
