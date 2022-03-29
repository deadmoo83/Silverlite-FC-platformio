

#include <inttypes.h>

#define I2C_GYRO_ADDRESS 0x68

void hw_i2c_init( void);
int hw_i2c_readdata(int address, int reg, uint32_t *data, int size );
int hw_i2c_readreg(int address, int reg );
void hw_i2c_writereg(int address, int reg , int data);




