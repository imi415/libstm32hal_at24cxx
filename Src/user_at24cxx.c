#include "i2c.h"

#include "user_board.h"
#include "user_at24cxx.h"

void AT24CXX_Init(AT24_HandleTypeDef * at24) {
  at24 -> Lock = 0;
  at24 -> TxFlag = 0;
  at24 -> RxFlag = 0;
}

/**
 * Read specified address.
 * @param addr  address.
 * @param pData data pointer.
 */
HAL_StatusTypeDef AT24CXX_Random_Read(AT24_HandleTypeDef * at24, uint16_t addr, uint8_t * pData) {
  __HAL_LOCK(at24);
  uint8_t page = addr / 0x100;
  uint8_t actual_dev_addr = (AT24_DEV_ADDR << 1 | page << 1);
  HAL_I2C_Mem_Read_DMA(&AT24_I2C_INTERFACE, actual_dev_addr, (addr & 0xFF), 0x01, pData, 0x01);
  uint32_t tickStart = HAL_GetTick();
  while(!at24 -> RxFlag) {
    if ((HAL_GetTick() - tickStart) > AT24CXX_MAX_TIMEOUT_TICKS) {
      break; // Oops!
    }
  }
  at24 -> RxFlag = 0x00;
  __HAL_UNLOCK(at24);
  return(HAL_OK);
}

/**
 * Sequencial read.
 * @param addr start address
 * @param pData     data
 * @param length    transfer length
 */
HAL_StatusTypeDef AT24CXX_Sequencial_Read(AT24_HandleTypeDef * at24, uint16_t addr, uint8_t * pData, uint8_t length) {
  __HAL_LOCK(at24);
  uint8_t page = addr / 0x100;
  uint8_t actual_dev_addr = (AT24_DEV_ADDR << 1 | page << 1);
  HAL_I2C_Mem_Read_DMA(&AT24_I2C_INTERFACE, actual_dev_addr, (addr & 0xFF), 0x01, pData, length);
  uint32_t tickStart = HAL_GetTick();
  while(!at24 -> RxFlag) {
    if ((HAL_GetTick() - tickStart) > AT24CXX_MAX_TIMEOUT_TICKS) {
      break; // Oops!
    }
  }
  at24 -> RxFlag = 0x00;
  __HAL_UNLOCK(at24);
  return(HAL_OK);
}

/**
 * Write to specified address.
 * @param addr  address
 * @param pData data
 */
HAL_StatusTypeDef AT24CXX_Byte_Write(AT24_HandleTypeDef * at24, uint16_t addr, uint8_t * pData) {
  __HAL_LOCK(at24);
  HAL_I2C_Mem_Write_DMA(&AT24_I2C_INTERFACE, AT24_DEV_ADDR, addr, 0x02, pData, 0x01);
  uint32_t tickStart = HAL_GetTick();
  while(!at24 -> TxFlag) {
    if ((HAL_GetTick() - tickStart) > AT24CXX_MAX_TIMEOUT_TICKS) {
      break; // Oops!
    }
  }
  at24 -> TxFlag = 0x00;
  __HAL_UNLOCK(at24);
  return(HAL_OK);
}

/**
 * Sequencial write.
 * @param addr   start address
 * @param pData  data
 * @param length length
 */
HAL_StatusTypeDef AT24CXX_Sequencial_Write(AT24_HandleTypeDef * at24, uint16_t addr, uint8_t * pData, uint8_t length) {
  __HAL_LOCK(at24);
  HAL_I2C_Mem_Write_DMA(&AT24_I2C_INTERFACE, AT24_DEV_ADDR, addr, 0x02, pData, length);
  uint32_t tickStart = HAL_GetTick();
  while(!at24 -> TxFlag) {
    if ((HAL_GetTick() - tickStart) > AT24CXX_MAX_TIMEOUT_TICKS) {
      break; // Oops!
    }
  }
  at24 -> TxFlag = 0x00;
  __HAL_UNLOCK(at24);
  return(HAL_OK);
}
