/*
 * EEPROM_prog.c
 *
 *  Created on: Apr 14, 2022
 *      Author: maged
 */

//public libs
#include "../../LIB/stdTypes.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/errorState.h"

//lower layer libs

//own libs
#include "EEPROM_config.h"
#include "EEPROM_priv.h"

ES_t EEPROM_enuInit(void){
	ES_t Local_enuErrorState = ES_NOK;

	//body

	return Local_enuErrorState;
}
ES_t EEPROM_enuWrite(u16 Copy_u16Address, u8 Copy_u8Data){
	ES_t Local_enuErrorState = ES_NOK;

	/*1. Wait until EEWE becomes zero.*/
	//while(GET_BIT(EECR,EEWE) == 1);
	/*2. Wait until SPMEN in SPMCR becomes zero.*/
	while(GET_BIT(SPMCR,SPMEN));
	/*3. Write new EEPROM address to EEAR.*/
	EEAR = Copy_u16Address;
	/*4. Write new EEPROM data to EEDR.*/
	EEDR = Copy_u8Data;
	/*5. Write a logical one to the EEMWE bit while writing a zero to EEWE in EECR*/
	SET_BIT(EECR,EEMWE);
	/*6. Within four clock cycles after setting EEMWE, write a logical one to EEWE.*/
	SET_BIT(EECR,EEWE);

	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}
ES_t EEPROM_enuRead(u16 Copy_u16Address, u8* Copy_u8Data){
	ES_t Local_enuErrorState = ES_NOK;

	/*1. Wait until EEWE becomes zero.*/
	//while(GET_BIT(EECR,EEWE) == 1);

	EEAR = Copy_u16Address;
	SET_BIT(EECR,EERE);
	*Copy_u8Data = EEDR;

	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}
