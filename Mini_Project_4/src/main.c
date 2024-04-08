/*
 * Mini-Project 4	:	Distance Measurer System
 * Facebook Name	:	Youssef Ahmed
 * Diploma Number	:	85
 */

/*
 * Note 1:	MISRA rules were applied to some extent in this project!
 * Note 2:	The project consists of five .c files and seven .h files
 * Note 3:	Don't forget to assign "inc" folder as the include path to use <main.h>
 */

/*
 * I.	Project Properties
 * II.	C/C++ Build
 * III.	Settings
 * IV.	Tool Settings
 * V.	AVR Compiler
 * VI.	Directories
 * VII.	Include Paths (-|): should be "${workspace_loc:/${ProjName}/inc}"
 */

#include <main.h>

int main()
{
	/* variables to store the calculated and displayed distance values */
	uint16 distance_value;
	uint16 displayed_distance_value;

	Ultrasonic_init();
	LCD_init();

	/* The LCD should look like:
	 * __________________
	 * |                |
	 * |    Distance    |
	 * |    = DDD cm    |
	 * |________________|
	 * where DDD is the 3-digits distance value */
	LCD_moveCursor(ROW_1, COL_4);
	LCD_displayString("Distance");

	LCD_moveCursor(ROW_2, COL_4);
	LCD_displayString("=     cm");

	/* read and display the initial distance value */
	displayed_distance_value = Ultrasonic_readDistance();

	LCD_moveCursor(ROW_2, COL_6);
	LCD_intgerToString(displayed_distance_value);

	while(TRUE)
	{
		/* continuously measuring the distance */
		distance_value = Ultrasonic_readDistance();

		/* update the displayed distance ONLY if changed */
		if (distance_value != displayed_distance_value)
		{
			displayed_distance_value = distance_value;
			LCD_moveCursor(ROW_2, COL_6);
			LCD_displayString("   ");
			LCD_moveCursor(ROW_2, COL_6);
			LCD_intgerToString(displayed_distance_value);
		}
	}
}
