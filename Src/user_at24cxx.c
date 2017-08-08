#include "i2c.h"

#include "user_at24cxx.h"

uint8_t i2cOK = 0x00;

/**
 * Read specified address.
 * @param addr  address.
 * @param pData data pointer.
 */
void AT24CXX_Random_Read(uint8_t addr, uint8_t * pData) {
  HAL_I2C_Mem_Read_DMA(&AT24_I2C_INTERFACE, AT24_DEV_ADDR, addr, 0x01, pData, 0x01);
  uint32_t tickStart = HAL_GetTick();
  while(!i2cOK) {
    if ((HAL_GetTick() - tickStart) > AT24CXX_MAX_TIMEOUT_TICKS) {
      break; // Oops!
    }
  }
  i2cOK = 0x00;
}

/**
 * Sequencial read.
 * @param addr start address
 * @param pData     data
 * @param length    transfer length
 */
void AT24CXX_Sequencial_Read(uint8_t addr, uint8_t * pData, uint8_t length) {
  HAL_I2C_Mem_Read_DMA(&AT24_I2C_INTERFACE, AT24_DEV_ADDR, addr, 0x01, pData, length);
  uint32_t tickStart = HAL_GetTick();
  while(!i2cOK) {
    if ((HAL_GetTick() - tickStart) > AT24CXX_MAX_TIMEOUT_TICKS) {
      break; // Oops!
    }
  }
  i2cOK = 0x00;
}

/**
 * Write to specified address.
 * @param addr  address
 * @param pData data
 */
void AT24CXX_Byte_Write(uint8_t addr, uint8_t * pData) {
  HAL_I2C_Mem_Write_DMA(&AT24_I2C_INTERFACE, AT24_DEV_ADDR, addr, 0x01, pData, 0x01);
  uint32_t tickStart = HAL_GetTick();
  while(!i2cOK) {
    if ((HAL_GetTick() - tickStart) > AT24CXX_MAX_TIMEOUT_TICKS) {
      break; // Oops!
    }
  }
  i2cOK = 0;
}

/**
 * Sequencial write.
 * @param addr   start address
 * @param pData  data
 * @param length length
 */
void AT24CXX_Sequencial_Write(uint8_t addr, uint8_t * pData, uint8_t length) {
  HAL_I2C_Mem_Write_DMA(&AT24_I2C_INTERFACE, AT24_DEV_ADDR, addr, 0x01, pData, length);
  uint32_t tickStart = HAL_GetTick();
  while(!i2cOK) {
    if ((HAL_GetTick() - tickStart) > AT24CXX_MAX_TIMEOUT_TICKS) {
      break; // Oops!
    }
  }
  i2cOK = 0;
}


void HAL_I2C_MemRxCpltCallback(I2C_HandleTypeDef *hi2c){
  i2cOK = 0x01;
}

void HAL_I2C_MemTxCpltCallback(I2C_HandleTypeDef *hi2c){
  i2cOK = 0x01;
}
