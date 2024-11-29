/*
 * @file buttons.h
 * @brief Header file for button initialization and state retrieval.
 * 
 * @author Ameed Othman	
 * @date 2024-11-29
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#ifndef __BUTTONS_H__
#define __BUTTONS_H__

#include <stdbool.h>

int buttons_init(void);
bool button_get_state(int button_id);

#endif 
