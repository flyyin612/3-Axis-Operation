#include "three_axis.h"
#include "i2c.h"
#include "usart.h"
#include "fsl_debug_console.h"
#include "usart.h"

uint8_t accel_x, accel_y, accel_z;
uint8_t Aresultx, Aresulty, Aresultz;
int8_t Atestx,Atesty,Atestz;
/*
*@brief:Single Byte Read
*@param:reg_addr -- register addr
*@retval:None
*/
uint8_t Three_Axis_Single_Byte_Read(uint8_t reg_addr)
{
	uint8_t single_byte = 0;
	
	i2c_Start();
	
	i2c_SendByte(THREE_AXIS_ADDR | I2C_WR);
	
	i2c_WaitAck();
	
	i2c_SendByte(reg_addr);
	
	i2c_WaitAck();
	
	i2c_Start();
	
	i2c_SendByte(THREE_AXIS_ADDR + I2C_RD);
	
	i2c_WaitAck();
	
	single_byte = i2c_ReadByte();
	
	i2c_NAck();
	
	i2c_Stop();
	
	return single_byte;
}

/*
*@brief:Multiple Byte Read
*@param:reg_addr  -- register addr
*				*data_buf -- 读取到得数据
*				len       -- 数据长度
*@retval:None
*/
uint8_t Three_Axis_Multiple_Byte_Read(uint8_t reg_addr,uint8_t *data_buf,uint8_t len)
{
	uint8_t i;
	uint8_t read_data[]={0};
	
	i2c_Start();
	
	i2c_SendByte(THREE_AXIS_ADDR | I2C_WR);
	
	i2c_WaitAck();
	
	i2c_SendByte(reg_addr);
	
	i2c_WaitAck();
	
	i2c_Start();
	
	i2c_SendByte(THREE_AXIS_ADDR + I2C_RD);
	
	i2c_WaitAck();
	
	for(i = 0; i < len; i++)
	{
		read_data[i] = i2c_ReadByte();
		
		
		if(i==len-1)
			i2c_NAck();
    else
      i2c_Ack();
	}
	
	i2c_Stop();
	
	data_buf = read_data;
	
	return 0;
}

/*
*@brief:Single Byte Write
*@param:reg_addr   -- register addr
*				write_data -- write data
*@retval:None
*/
void Three_Axis_Single_Byte_Write(uint8_t reg_addr,uint8_t write_data)
{
	i2c_Start();
	
	i2c_SendByte(THREE_AXIS_ADDR | I2C_WR);
	
	i2c_WaitAck();
	
	i2c_SendByte(reg_addr);
	
	i2c_WaitAck();
	
	i2c_SendByte(write_data);
	
	i2c_WaitAck();
	
	i2c_Stop();
}

/*
*@brief:Multiple Byte Write
*@param:reg_addr    -- register addr
*				*write_data -- write data
*       len         -- 写数据长度
*@retval:None
*/
void Three_Axis_Multiple_Byte_Write(uint8_t reg_addr,uint8_t *write_data,uint8_t len)
{
	uint8_t i;
	
	i2c_Start();
	
	i2c_SendByte(THREE_AXIS_ADDR | I2C_WR);
	
	i2c_WaitAck();
	
	i2c_SendByte(reg_addr);
	
	i2c_WaitAck();
	
	for(i = 0; i < len; i++)
	{
		i2c_SendByte(*write_data);
		i2c_WaitAck();
		write_data++;
	}
	
	i2c_Stop();
}

