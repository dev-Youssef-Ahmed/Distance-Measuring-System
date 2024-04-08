/*
 * ultrasonic.h
 *
 *  Created on: Mar 12, 2024
 *      Author: Youssef
 */

#ifndef INC_ULTRASONIC_H_
#define INC_ULTRASONIC_H_

#include <gpio.h>
#include <icu.h>
#include <common_macros.h>
#include <util/delay.h>

/* this type will be used in s_edgeCount */
typedef enum
{
	INITIAL_VALUE,
	RAISING_EDGE,
	FALLING_EDGE
}	edgeCount_t;

#define FACTOR_OF_DISTANCE	(58.8)

/* this function-like macro will calibrate the displayed distance using +1 cm for each 70 cm */
#define CALIBRATED(time)	(time) 	+										\
									(										\
										(time >=   0 && time <  70) ? 1 :	\
										(time >=  70 && time < 140) ? 2 :	\
										(time >= 140 && time < 210) ? 3 :	\
										(time >= 210 && time < 280) ? 4 :	\
										(time >= 280 && time < 350) ? 5 : 6	\
									)

void Ultrasonic_init(void);
void Ultrasonic_Trigger(void);
uint16 Ultrasonic_readDistance(void);
void Ultrasonic_edgeProcessing(void);

#endif /* INC_ULTRASONIC_H_ */
