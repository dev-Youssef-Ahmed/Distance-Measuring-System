/*
 * ultrasonic.c
 *
 *  Created on: Mar 12, 2024
 *      Author: Youssef
 */

#include <ultrasonic.h>

uint16 g_timerValue;

void Ultrasonic_init(void)
{
	/* Enable the global interrupt bit ("avr/io.h" not used) */
	SET_BIT(SREG,I_BIT);

	/* Initialize the ICU driver as required */
	/* ICU should be configured with frequency F_CPU/8 and to detect the raising edge as the first edge */
	ICU_ConfigType ICU_parameters = {F_CPU_8, RAISING};
	ICU_init(&ICU_parameters);

	/* Setup the ICU call back function */
	ICU_setCallBack(Ultrasonic_edgeProcessing);

	/* Setup the direction for the trigger pin as output pin through the GPIO driver (PB5) */
	GPIO_setupPinDirection(PORTB_ID, PIN5_ID, PIN_OUTPUT);
}

void Ultrasonic_Trigger(void)
{
	/* Send the Trigger pulse to the ultrasonic for 10 microsecond */
	GPIO_writePin(PORTB_ID, PIN5_ID, LOGIC_HIGH);
	_delay_us(TEN);
	GPIO_writePin(PORTB_ID, PIN5_ID, LOGIC_LOW);
}

uint16 Ultrasonic_readDistance(void)
{
	/* Send the trigger pulse*/
	Ultrasonic_Trigger();

	/*	How to calculate the distance?
	 * 1.	distance = time * velocity
	 * 		>>	This is the general formula of distance, and it measured in meters
	 * 2.	distance = time * 340 * 100 * 0.000001 / 2
	 * 		>>	340		: sound velocity in air
	 * 		>>	100		: meters to centimeters factor
	 * 		>>	0.000001: timer pre-scaler (F_CPU/8), where F_CPU = 8 MHz
	 * 		>>	2		: divided by 2 because echo signal is a round-trip!
	 * 3.	Now distance = time * 0.017
	 * 4.	Distance also could be represented as: distance = time / 58.8
	 * 6.	Due to floating points, this distance will not be accurate
	 * 		>> In order to match the real distance as possible, some calibrations used */

	return CALIBRATED(g_timerValue/FACTOR_OF_DISTANCE);
}

/* This is the call-back function */
void Ultrasonic_edgeProcessing(void)
{
	/* a variable to store the number of edges detected */
	static edgeCount_t s_edgeCount = INITIAL_VALUE;
	s_edgeCount++;

	if(s_edgeCount == RAISING_EDGE)
	{
		/*
		* Clear the timer counter register to start measurements from the
		* first detected rising edge
		*/
		ICU_clearTimerValue();
		/* Detect falling edge */
		ICU_setEdgeDetectionType(FALLING);
	}
	else if(s_edgeCount == FALLING_EDGE)
	{
		/* Store the High time value */
		g_timerValue = ICU_getInputCaptureValue();
		/* Reset s_edgeCount for the next cycle */
		s_edgeCount = INITIAL_VALUE;
		/* Detect rising edge */
		ICU_setEdgeDetectionType(RAISING);
	}
}

