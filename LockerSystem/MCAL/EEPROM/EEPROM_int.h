/*
 * EEPROM_int.h
 *
 *  Created on: Apr 14, 2022
 *      Author: maged
 */

#ifndef MCAL_EEPROM_EEPROM_INT_H_
#define MCAL_EEPROM_EEPROM_INT_H_

ES_t EEPROM_enuInit(void);
ES_t EEPROM_enuWrite(u16 Copy_u16Address, u8 Copy_u8Data);
ES_t EEPROM_enuRead(u16 Copy_u16Address, u8* Copy_u8Data);



#endif /* MCAL_EEPROM_EEPROM_INT_H_ */
