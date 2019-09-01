#ifndef __THREE_AXIS_H_
#define __THREE_AXIS_H_

#include "fsl_common.h"

#define SA0

/***************************************Three Axis Addr*************************************************/
#ifndef SA0

	#define THREE_AXIS_ADDR						0x1c						//SA0 = 0 ,MMA8541Q Addr = 0x1c
	
#else

	#define THREE_AXIS_ADDR						0x3A 			  		//SA0 = 1 ,MMA8541Q Addr = 0x1d
	
#endif

/*************************************Register Map***************************************************/
#define F_STATUS										0x00		  // R FMODE = 0,real time status.FMODE > 0,FIFO status
#define OUT_X_MSB										0x01			//R
#define OUT_X_LSB										0x02      //R
#define OUT_Y_MSB										0x03      //R
#define OUT_Y_LSB										0x04      //R
#define OUT_Z_MSB										0x05      //R
#define OUT_Z_LSB										0x06      //R
#define F_SETUP											0x09			//R/W 0x00,FIFO set-up
#define TRIG_CFG										0x0a			//R/W 0x00,Map of FIFO data capture events
#define SYSMOD											0x0b			//R 0x00,Current System Mode
#define INT_SOURCE									0x0c			//R 0x00,Interrupt status
#define WHO_AM_I										0x0d			//R 0x1a,Device ID (0x1A)
#define XYZ_DATA_CFG								0x0e			//R/W 0x00,Dynamic Range Settings
#define HP_FILTER_CUTOFF						0x0f			//R/W 0x00,Cut-off frequency is set to 16 Hz @800 Hz
#define PL_STATUS										0x10			//R 0x00,Landscape/Portrait orientation status
#define PL_CFG    									0x11			//R/W 0x80,Landscape/Portrait configuration.
#define PL_COUNT										0x12			//R/W 0x00,Landscape/Portrait debounce counter 
#define PL_BF_ZCOMP									0x13			//R/W 0x44,Back/Front, Z-Lock Trip threshold
#define P_L_THS_REG									0x14      //R/W 0x84,Portrait to Landscape Trip Angle is 29бу

#define CTRL_REG1										0x2a			//R/W 0x00,ODR = 800 Hz, STANDBY Mode.

uint8_t Three_Axis_Single_Byte_Read(uint8_t reg_addr);

uint8_t Three_Axis_Multiple_Byte_Read(uint8_t reg_addr,uint8_t *data_buf,uint8_t len);

void Three_Axis_Single_Byte_Write(uint8_t reg_addr,uint8_t write_data);

void Three_Axis_Multiple_Byte_Write(uint8_t reg_addr,uint8_t *write_data,uint8_t len);

#endif
