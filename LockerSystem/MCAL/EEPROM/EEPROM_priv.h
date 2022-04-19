/*
 * EEPROM_priv.h
 *
 *  Created on: Apr 14, 2022
 *      Author: maged
 */

#ifndef MCAL_EEPROM_EEPROM_PRIV_H_
#define MCAL_EEPROM_EEPROM_PRIV_H_

#define EEARH 			*((volatile u8*) 0x3F)
#define EEARL			*((volatile u8*) 0x3E)
#define EEAR			*((volatile u16*) 0x3E)  //u16 to write on low and high EEAR
#define EEDR 			*((volatile u8*) 0x3D)
#define EECR 			*((volatile u8*) 0x3C)
#define SPMCR 			*((volatile u8*) 0x3C)

/* EECR Register bits */
#define EERE			0U
#define EEWE			1U
#define EEMWE			2U
#define EERIE			3U

/* EEARH Register bits */
#define EEAR8			0U
#define EEAR9			1U

/* SPMCR Register bits */
#define SPMEN			0U

#endif /* MCAL_EEPROM_EEPROM_PRIV_H_ */
