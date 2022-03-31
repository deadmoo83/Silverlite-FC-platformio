

#include <inttypes.h>

#define I2C_GYRO_ADDRESS 0x68

void hw_i2c_init(void);
void hw_i2c_readdata(uint8_t address, uint8_t reg, uint32_t data[], uint8_t size );
uint8_t hw_i2c_readreg(uint8_t address, uint8_t reg );
void hw_i2c_writereg(uint8_t address, uint8_t reg , uint8_t data);




