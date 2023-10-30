/**
 * @file APP.c
 * @author Mohamed Sami
 * @brief
 * @version 0.1
 * @date 2023-10-24
 *
 *
 */
#include "STD_Types.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "KEYPAD_Interface.h"
#include "LCD_Interface.h"
#include "calculator.h"
#include <avr/delay.h>
#include <avr/io.h>

void main(void)
{

	u8 ret = 0;				// KEYPAD CHARACTER RECEIVER VARIABLE TO RECEIVE KEYPAD CHARACTER
	u8 infix_index = 0;		// to increment the index of the infix array to put the input expression
	u8 lcd_postfix_pos = 0; // to increment lcd colum position while Printing the expression value
	u8 lcd_infix_pos = 0;	// to increment lcd colum position while adding the expression
	KPD_VidInit();
	LCD_VidInit();
	Init_Project();

	while (1)
	{

		do
		{
			ret = KPD_u8GetPressedKey();
		} while (KPD_NO_PRESSED_KEY == ret);
		_delay_ms(100);

		/* Get data from user, reserve it in LOC_u8Data array */
		while (ret != '=')
		{
			// LCD_VidWriteString(" KPD_NO_PRESSED_KEY ");
			//_delay_ms(2000);
			if (ret != KPD_NO_PRESSED_KEY)
			{
				LCD_VidSetPosition(0, lcd_infix_pos);
				lcd_infix_pos++;
				if (ret == '1' || ret == '2' || ret == '3' || ret == '4' || ret == '5' || // IF FUNCTION TO CHECK USER INPUTS
					ret == '6' || ret == '7' || ret == '8' || ret == '9' ||

					ret == '0')
				{
					infix[infix_index++] = ret;
					LCD_VidWriteChar(ret);
				}
				else if (ret == '*' || ret == '/' || ret == '+' || ret == '-')
				{

					LCD_VidWriteChar(ret);
					infix[infix_index++] = ret;
					infix[infix_index++] = ' ';
				}
				else if (ret == 'c')
				{
					LCD_VidSendCommand(1);
					infix_index = 0;
					lcd_postfix_pos = 0;
					lcd_infix_pos = 0;
				}
			}
			ret = KPD_u8GetPressedKey();
		}
		lcd_postfix_pos++;
		s8 *postfix = infixToPostfix(infix);
		LCD_VidSetPosition(1, lcd_postfix_pos + 4);
		// LCD_VidWriteString(postfix);
		LCD_VidSetPosition(2, 6);
		LCD_VidWriteChar(ret);
		LCD_VidWriteNumber(evaluatePostfix(postfix));
	}

	return 0;
}
