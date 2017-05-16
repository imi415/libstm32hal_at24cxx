#include "i2c.h"

#include "user_at24cxx.h"

uint8_t i2cOK = 0x00;

void AT24CXX_Random_Read(uint8_t addr, uint8_t * pData) {
  HAL_I2C_Mem_Read_DMA(&AT24_I2C_INTERFACE, AT24_DEV_ADDR, addr, 0x01, pData, 0x01);
  while(!i2cOK) {

  }
  i2cOK = 0x00;
}

void AT24CXX_Byte_Write(uint8_t addr, uint8_t * pData) {
  HAL_I2C_Mem_Write_DMA(&AT24_I2C_INTERFACE, AT24_DEV_ADDR, addr, 0x01, pData, 0x01);
  while(!i2cOK) {

  }
  i2cOK = 0;
}

void HAL_I2C_MemRxCpltCallback(I2C_HandleTypeDef *hi2c){
  i2cOK = 0x01;
}

void HAL_I2C_MemTxCpltCallback(I2C_HandleTypeDef *hi2c){
  i2cOK = 0x01;
}
