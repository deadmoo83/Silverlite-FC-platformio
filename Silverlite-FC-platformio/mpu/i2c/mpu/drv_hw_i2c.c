/*
The MIT License (MIT)

Copyright (c) 2016 silverx

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/


#include "main.h"
#include "drv_hw_i2c.h"

extern I2C_HandleTypeDef hi2c1;

void hw_i2c_init(void)
{
	extern void MX_I2C1_Init(void);
	MX_I2C1_Init();
}


void hw_i2c_writereg(uint8_t address, uint8_t reg, uint8_t data)
{
	uint8_t d[2];
	d[0] = reg;
	d[1] = data;

	while(HAL_I2C_Master_Transmit(&hi2c1, (uint16_t)address<<1, d, 2, HAL_MAX_DELAY)!=HAL_OK);
}


void hw_i2c_readdata(uint8_t address, uint8_t reg, uint32_t data[], uint8_t size )
{
	uint8_t d[size];

	while(HAL_I2C_Master_Transmit(&hi2c1, (uint16_t)address<<1, (uint8_t *)&reg, 1, HAL_MAX_DELAY)!=HAL_OK);
	while(HAL_I2C_Master_Receive(&hi2c1, (uint16_t)address<<1, d, size, HAL_MAX_DELAY)!=HAL_OK);
	for(uint8_t i = 0; i < size; i++)
	{
		data[i] = (uint32_t)d[i];
	}
}


uint8_t hw_i2c_readreg(uint8_t address, uint8_t reg )
{
	uint32_t data;
	hw_i2c_readdata(address, reg, &data, 1 );
	return (uint8_t)data;
}






