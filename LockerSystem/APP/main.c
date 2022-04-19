/*
 * stdTypes.h
 *
 *  Created on	: Mar 31, 2020
 *  Version		: 1.0.0
 *  Author		: MagedElnaggar
 */

#include "main.h"


int main(void)
{

	s8 EnteredPassword[MAX_PASS_NUM]={0} ;
	s8 RightPassword[MAX_PASS_NUM]= "010";
	s8 MasterPassword[MAX_PASS_NUM]="010" ;
	u8 wrongInputRemain = WRONG_INPUTS_ALLOWED;  //number of wrong inputs //save it in EEPROM

	s8 strItrr=0 ;
	//u16 address = 0x1;
	u8 key;

	Keypad_enuInit();
	LCD_enuInit();
	LCD_enuWriteCommand(0x0C); //Disable cursor

	//Buzzer
	DIO_enuSetPinDirection(DIO_u8GROUP_B,DIO_u8PIN0 , DIO_u8OUTPUT);


	//EEPROM_enuWrite(address,data);
	//EEPROM_enuRead(address , &dataFromEEPROM);

	LCD_enuWriteCommand(1);
	LCD_enuWriteString("Enter Password:");
	LCD_enuGoToPosition(2,1);


	while(1)
	{

		Keypad_GetPressedKey(&key);
		if (key != KEYPAD_NOT_PRESSED)
		{

			if(key >= '0' && key <='9')
			{
				BeebSound();
				LCD_enuWriteData('*');
				EnteredPassword[strItrr] = key;
				strItrr++;
			}
			else if('=' == key)
			{
				if((strEqual(EnteredPassword , RightPassword ) == STR_EQL) ||
						(strEqual(EnteredPassword , MasterPassword )== STR_EQL))
				{
					WelcomeTap(RightPassword);
					wrongInputRemain = WRONG_INPUTS_ALLOWED;
				}
				else{
					WrongTap(&wrongInputRemain);
				}

				for(strItrr = 0 ; strItrr<MAX_PASS_NUM ; strItrr++)
				{
					EnteredPassword[strItrr] = 0;
				}
				strItrr =0;

				LCD_enuWriteCommand(1);
				LCD_enuWriteString("Enter Password:");
				LCD_enuGoToPosition(2,1);
			}
		}

	}
	return 0;
}

void WelcomeTap(s8* Copy_ps8RightPassword)
{
	u8 key;
	u8 strItrr=0;

	LCD_enuWriteCommand(1);
	LCD_enuGoToPosition(1,5);
	LCD_enuWriteString("Welcome!!");
	while(1)
	{
		Keypad_GetPressedKey(&key);
		if (key != KEYPAD_NOT_PRESSED)
		{
			if('c'==key) //Lock the locker key
			{
				//move the motor for the lock and check if it really locked
				break;//back to main()
			}
			if('/'==key) //rest password key
			{

				//reset all RightPassword to zero
				for(strItrr = 0 ; strItrr<MAX_PASS_NUM ; strItrr++)
				{
					Copy_ps8RightPassword[strItrr] = 0;
				}
				strItrr = 0;
				/*************************/
				LCD_enuWriteCommand(1);
				LCD_enuGoToPosition(1,1);
				LCD_enuWriteString("New Password is:");
				LCD_enuGoToPosition(2,1);
				while(1)
				{
					Keypad_GetPressedKey(&key);
					if (key != KEYPAD_NOT_PRESSED)
					{
						if(key >= '0' && key <='9')
						{
							LCD_enuWriteData('*');
							Copy_ps8RightPassword[strItrr] = key;
							strItrr++;
						}
						else if('=' == key)
						{
							break;
						}
					}
				}
				break; //back to main()
			}
		}
	}
}

void WrongTap(u8* Copy_ps8wrongInputRemain)
{
	if(*Copy_ps8wrongInputRemain  > 0)
	{
		*Copy_ps8wrongInputRemain -=1;
		LCD_enuWriteCommand(1);
		LCD_enuGoToPosition(1,5);
		LCD_enuWriteString("Wrong!!");
		LCD_enuGoToPosition(2,1);
		//LCD_enuWriteString("you've ");
		LCD_enuWriteIntegerNum(*Copy_ps8wrongInputRemain);
		LCD_enuWriteString(" trial left!!");
		_delay_ms(500);
	}
	else{
		LCD_enuWriteCommand(1);
		LCD_enuWriteString("Calling Police...");
		Buzzer_TOG();
	}
}

u8 strEqual(s8* Copy_ps8str1 , s8* Copy_ps8str2)
{
	while(*Copy_ps8str1 != 0 || *Copy_ps8str2 != 0)
	{
		if(*Copy_ps8str1 == *Copy_ps8str2){
			Copy_ps8str1++;
			Copy_ps8str2++;
		}
		else{
			return STR_NEQL;
		}
	}
	return STR_EQL;
}

void BeebSound(void)
{
	DIO_enuSetPinValue(DIO_u8GROUP_B,DIO_u8PIN0, DIO_u8HIGH);
	_delay_ms(100);
	DIO_enuSetPinValue(DIO_u8GROUP_B,DIO_u8PIN0, DIO_u8LOW);
}
void  Buzzer_TOG( void )
{
	//BUZZER Waiting B0
	while(1)
	{
		DIO_enuTogglePinValue(DIO_u8GROUP_B,DIO_u8PIN0);
		_delay_ms(500);
	}
}
