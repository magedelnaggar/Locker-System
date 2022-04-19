/*
 * stdTypes.h
 *
 *  Created on	: Mar 31, 2020
 *  Version		: 1.0.0
 *  Author		: MagedElnaggar
 */

#ifndef APP_MAIN_H_
#define APP_MAIN_H_


#include "../LIB/stdTypes.h"
#include "../LIB/errorState.h"

#include "../MCAL/DIO/DIO_int.h"

#include "../MCAL/EEPROM/EEPROM_int.h"

#include "../HAL/LCD/LCD_int.h"

#include "../HAL/Keypad/Keypad_int.h"


#include <util/delay.h>



u8 strEqual(s8* Copy_ps8str1 , s8* Copy_ps8str2);
void WelcomeTap(s8* Copy_ps8RightPassword);
void WrongTap(u8* Copy_ps8wrongInputRemain);
void BeebSound(void);
void Buzzer_TOG(void );


/**/
#define STR_NEQL 				0
#define STR_EQL 				1
#define MAX_PASS_NUM			20
#define WRONG_INPUTS_ALLOWED	3

#endif /* APP_MAIN_H_ */
