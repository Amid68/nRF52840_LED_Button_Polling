/*
 * @file main.c
 * @brief Application that controls LEDs based on button inputs.
 *
 * @author Ameed Othman	
 * @date 2024-11-29
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include <zephyr/kernel.h>
#include "buttons.h"
#include "leds.h"

#define SLEEP_TIME_MS 100

int main(void)
{
    int ret;

    // Initialize buttons
    ret = buttons_init();
    if (ret < 0) {
        return -1;
    }

    // Initialize LEDs
    ret = leds_init();
    if (ret < 0) {
        return -1;
    }

    // Variables to keep track of LED states
    bool led1_blink = false;
    int led2_pattern = 0;

    // Variables to keep track of previous button states
    bool prev_button1_state = false;
    bool prev_button2_state = false;

    while (1) {
        // Read button states
        bool button0_state = button_get_state(0);
        bool button1_state = button_get_state(1);
        bool button2_state = button_get_state(2);

        // Set LED 0 state based on Button 0 state
        led_set_state(0, button0_state);

        // Detect button 1 press (toggle blinking of LED 1)
        if (button1_state && !prev_button1_state) {
            led1_blink = !led1_blink;
        }
        prev_button1_state = button1_state;

        // Update LED 1 blinking
        if (led1_blink) {
            led_toggle(1);
        }

        // Detect button 2 press (cycle LED 2 patterns)
        if (button2_state && !prev_button2_state) {
            led2_pattern = (led2_pattern + 1) % 3;
        }
        prev_button2_state = button2_state;

        // Update LED 2 based on the current pattern
        switch (led2_pattern) {
            case 0:
                led_set_state(2, false); // Off
                break;
            case 1:
                led_set_state(2, true);  // On
                break;
            case 2:
                led_toggle(2);           // Blinking
                break;
        }

        // Sleep to reduce CPU usage
        k_msleep(SLEEP_TIME_MS);
    }

    return 0;
}