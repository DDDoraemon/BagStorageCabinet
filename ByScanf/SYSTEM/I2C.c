#include "I2C.h"

void I2C_Start(void)
{
	I2C_SDA = 1;
	I2C_SCL = 1;
	I2C_SDA = 0;
	I2C_SCL = 0;
}

void I2C_Stop(void)
{
	I2C_SDA = 0;
	I2C_SCL = 1;
	I2C_SDA = 1;
}

void I2C_SendByte(uint8_t Byte)
{
	uint8_t i;
	for(i = 0; i < 8; i++)
	{
		I2C_SDA = Byte & (0x80>>i);
		I2C_SCL = 1;
		I2C_SCL = 0;
	}
}

uint8_t I2C_ReceiveByte(void)
{
	uint8_t i, Byte = 0x00;
	I2C_SDA = 1;
	for(i = 0; i < 8; i++)
	{
		I2C_SCL = 1;
		if(I2C_SDA) {
			Byte |= (0x80>>i);
		}
		I2C_SCL = 0;
	}
	return Byte;
}

void I2C_SendAck(uint8_t AckBit)
{
	I2C_SDA = AckBit;
	I2C_SCL = 1;
	I2C_SCL = 0;
}

uint8_t I2C_ReceiveAck(void)
{
	unsigned char AckBit;
	I2C_SDA = 1;
	I2C_SCL = 1;
	AckBit = I2C_SDA;
	I2C_SCL = 0;
	return AckBit;
}
