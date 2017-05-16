#ifndef __USER_AT24CXX_H_
#define __USER_AT24CXX_H_

#define AT24_I2C_INTERFACE hi2c1 // HAL I2C handler
#define AT24_DEV_ADDR 0xA0 // 8-bit with trailing 0
#define AT24_SIZE 2048 // Bytes

void AT24CXX_Random_Read(uint8_t addr, uint8_t * pData);
void AT24CXX_Byte_Write(uint8_t addr, uint8_t * pData);

#endif
